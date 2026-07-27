module NPC(
  input  logic        clk,
  input  logic        reset,
  output logic        halt,
  output logic [31:0] halt_code,
  output logic [31:0] pc_out,
  output logic [31:0] inst_out
);
  import "DPI-C" function int pmem_read(input int raddr, input byte len);
  import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte len);

  localparam logic [31:0] RESET_VECTOR = 32'h8000_0000;
  localparam logic [31:0] NOP_INST     = 32'h0000_0013;

  typedef struct packed {
    logic        valid;
    logic [31:0] pc;
    logic [31:0] inst;
  } if_id_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] pc;
    logic [31:0] inst;
    logic [4:0]  rd;
    logic [4:0]  rs1;
    logic [4:0]  rs2;
    logic [31:0] src1;
    logic [31:0] src2;
    logic        reg_write;
    logic        mem_read;
  } id_ex_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] pc;
    logic [31:0] inst;
    logic [4:0]  rd;
    logic        reg_write;
    logic        mem_read;
    logic        mem_write;
    logic [7:0]  mem_len;
    logic [2:0]  load_funct3;
    logic [31:0] alu_result;
    logic [31:0] store_data;
    logic [31:0] wb_data;
    logic        halt_req;
    logic [31:0] halt_code;
  } ex_mem_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] pc;
    logic [31:0] inst;
    logic [4:0]  rd;
    logic        reg_write;
    logic [31:0] wb_data;
    logic        halt_req;
    logic [31:0] halt_code;
  } mem_wb_t;

  logic [31:0] pc;
  logic [31:0] regs [0:31];

  logic [31:0] mstatus;
  logic [31:0] mtvec;
  logic [31:0] mepc;
  logic [31:0] mcause;
  logic [31:0] mie;
  logic [31:0] mip;
  logic [31:0] mscratch;

  if_id_t if_id;
  id_ex_t id_ex;
  ex_mem_t ex_mem;
  mem_wb_t mem_wb;

  logic halt_pending;
  logic [31:0] commit_pc;
  logic [31:0] commit_inst;
  logic ex_redirect;
  logic ex_halt_req;

  assign pc_out = commit_pc;
  assign inst_out = commit_inst;

  function automatic logic [31:0] csr_read(input logic [11:0] addr);
    case (addr)
      12'h300: csr_read = mstatus;
      12'h304: csr_read = mie;
      12'h305: csr_read = mtvec;
      12'h340: csr_read = mscratch;
      12'h341: csr_read = mepc;
      12'h342: csr_read = mcause;
      12'h344: csr_read = mip;
      default: csr_read = 32'b0;
    endcase
  endfunction

  function automatic logic [31:0] sign_extend_load(
    input logic [31:0] data,
    input logic [2:0]  funct3
  );
    case (funct3)
      3'b000: sign_extend_load = {{24{data[7]}}, data[7:0]};
      3'b001: sign_extend_load = {{16{data[15]}}, data[15:0]};
      3'b010: sign_extend_load = data;
      3'b100: sign_extend_load = {24'b0, data[7:0]};
      3'b101: sign_extend_load = {16'b0, data[15:0]};
      default: sign_extend_load = 32'b0;
    endcase
  endfunction

  function automatic logic [7:0] mem_len_from_funct3(input logic [2:0] funct3);
    case (funct3)
      3'b000, 3'b100: mem_len_from_funct3 = 8'd1;
      3'b001, 3'b101: mem_len_from_funct3 = 8'd2;
      default:        mem_len_from_funct3 = 8'd4;
    endcase
  endfunction

  function automatic logic [31:0] forward_value(
    input logic [4:0]  rs,
    input logic [31:0] raw
  );
    begin
      forward_value = raw;
      if (rs != 5'b0) begin
        if (ex_mem.valid && ex_mem.reg_write && !ex_mem.mem_read && ex_mem.rd == rs) begin
          forward_value = ex_mem.wb_data;
        end else if (mem_wb.valid && mem_wb.reg_write && mem_wb.rd == rs) begin
          forward_value = mem_wb.wb_data;
        end
      end
    end
  endfunction

  function automatic logic [31:0] read_gpr_for_id(input logic [4:0] rs);
    begin
      read_gpr_for_id = (rs == 5'b0) ? 32'b0 : regs[rs];
      if (rs != 5'b0 && mem_wb.valid && mem_wb.reg_write && mem_wb.rd == rs) begin
        read_gpr_for_id = mem_wb.wb_data;
      end
    end
  endfunction

  wire [31:0] if_inst =
    (!reset && !halt && !halt_pending && !ex_redirect && !ex_halt_req) ? pmem_read(pc, 8'd4) : NOP_INST;

  wire [6:0] id_opcode = if_id.inst[6:0];
  wire [4:0] id_rd     = if_id.inst[11:7];
  wire [2:0] id_funct3 = if_id.inst[14:12];
  wire [4:0] id_rs1    = if_id.inst[19:15];
  wire [4:0] id_rs2    = if_id.inst[24:20];

  logic id_uses_rs1;
  logic id_uses_rs2;
  logic id_uses_a0_for_halt;
  logic id_reg_write;
  logic id_mem_read;

  always_comb begin
    id_uses_rs1 = 1'b0;
    id_uses_rs2 = 1'b0;
    id_uses_a0_for_halt = (if_id.inst == 32'h0010_0073);
    id_reg_write = 1'b0;
    id_mem_read = 1'b0;

    unique case (id_opcode)
      7'b0110111: begin
        id_reg_write = 1'b1;
      end
      7'b0010111: begin
        id_reg_write = 1'b1;
      end
      7'b1101111: begin
        id_reg_write = 1'b1;
      end
      7'b1100111: begin
        id_uses_rs1 = 1'b1;
        id_reg_write = 1'b1;
      end
      7'b1100011: begin
        id_uses_rs1 = 1'b1;
        id_uses_rs2 = 1'b1;
      end
      7'b0000011: begin
        id_uses_rs1 = 1'b1;
        id_reg_write = 1'b1;
        id_mem_read = 1'b1;
      end
      7'b0100011: begin
        id_uses_rs1 = 1'b1;
        id_uses_rs2 = 1'b1;
      end
      7'b0010011: begin
        id_uses_rs1 = 1'b1;
        id_reg_write = 1'b1;
      end
      7'b0110011: begin
        id_uses_rs1 = 1'b1;
        id_uses_rs2 = 1'b1;
        id_reg_write = 1'b1;
      end
      7'b1110011: begin
        if (id_funct3 != 3'b000) begin
          id_reg_write = 1'b1;
          id_uses_rs1 = (id_funct3 == 3'b001 || id_funct3 == 3'b010 || id_funct3 == 3'b011);
        end
      end
      default: begin end
    endcase
  end

  wire load_use_stall =
    if_id.valid && id_ex.valid && id_ex.mem_read && id_ex.rd != 5'b0 &&
    ((id_uses_rs1 && id_rs1 == id_ex.rd) ||
     (id_uses_rs2 && id_rs2 == id_ex.rd) ||
     (id_uses_a0_for_halt && id_ex.rd == 5'd10));

  logic [31:0] ex_src1;
  logic [31:0] ex_src2;
  logic [31:0] ex_src_a0;
  logic [31:0] ex_imm_i;
  logic [31:0] ex_imm_s;
  logic [31:0] ex_imm_b;
  logic [31:0] ex_imm_u;
  logic [31:0] ex_imm_j;
  logic [6:0]  ex_opcode;
  logic [2:0]  ex_funct3;
  logic [6:0]  ex_funct7;
  logic [4:0]  ex_rd;
  logic [4:0]  ex_rs1;
  logic [31:0] ex_next_pc;
  logic [31:0] ex_redirect_pc;
  logic        ex_reg_write;
  logic        ex_mem_read;
  logic        ex_mem_write;
  logic [7:0]  ex_mem_len;
  logic [2:0]  ex_load_funct3;
  logic [31:0] ex_alu_result;
  logic [31:0] ex_store_data;
  logic [31:0] ex_wb_data;
  logic [31:0] ex_halt_code;
  logic        ex_csr_write;
  logic [11:0] ex_csr_addr;
  logic [31:0] ex_csr_wdata;
  logic        ex_ecall;
  logic        ex_illegal;

  always_comb begin
    ex_src1 = forward_value(id_ex.rs1, id_ex.src1);
    ex_src2 = forward_value(id_ex.rs2, id_ex.src2);
    ex_src_a0 = forward_value(5'd10, regs[10]);

    ex_opcode = id_ex.inst[6:0];
    ex_rd = id_ex.inst[11:7];
    ex_funct3 = id_ex.inst[14:12];
    ex_rs1 = id_ex.inst[19:15];
    ex_funct7 = id_ex.inst[31:25];
    ex_imm_i = {{20{id_ex.inst[31]}}, id_ex.inst[31:20]};
    ex_imm_s = {{20{id_ex.inst[31]}}, id_ex.inst[31:25], id_ex.inst[11:7]};
    ex_imm_b = {{19{id_ex.inst[31]}}, id_ex.inst[31], id_ex.inst[7],
                id_ex.inst[30:25], id_ex.inst[11:8], 1'b0};
    ex_imm_u = {id_ex.inst[31:12], 12'b0};
    ex_imm_j = {{11{id_ex.inst[31]}}, id_ex.inst[31], id_ex.inst[19:12],
                id_ex.inst[20], id_ex.inst[30:21], 1'b0};

    ex_next_pc = id_ex.pc + 32'd4;
    ex_redirect = 1'b0;
    ex_redirect_pc = ex_next_pc;
    ex_reg_write = 1'b0;
    ex_mem_read = 1'b0;
    ex_mem_write = 1'b0;
    ex_mem_len = 8'd4;
    ex_load_funct3 = ex_funct3;
    ex_alu_result = 32'b0;
    ex_store_data = ex_src2;
    ex_wb_data = 32'b0;
    ex_halt_req = 1'b0;
    ex_halt_code = 32'd1;
    ex_csr_write = 1'b0;
    ex_csr_addr = id_ex.inst[31:20];
    ex_csr_wdata = 32'b0;
    ex_ecall = 1'b0;
    ex_illegal = 1'b0;

    unique case (ex_opcode)
      7'b0110111: begin
        ex_reg_write = 1'b1;
        ex_wb_data = ex_imm_u;
      end
      7'b0010111: begin
        ex_reg_write = 1'b1;
        ex_wb_data = id_ex.pc + ex_imm_u;
      end
      7'b1101111: begin
        ex_reg_write = 1'b1;
        ex_wb_data = id_ex.pc + 32'd4;
        ex_redirect = 1'b1;
        ex_redirect_pc = id_ex.pc + ex_imm_j;
      end
      7'b1100111: begin
        ex_reg_write = 1'b1;
        ex_wb_data = id_ex.pc + 32'd4;
        ex_redirect = 1'b1;
        ex_redirect_pc = (ex_src1 + ex_imm_i) & 32'hffff_fffe;
      end
      7'b1100011: begin
        unique case (ex_funct3)
          3'b000: ex_redirect = (ex_src1 == ex_src2);
          3'b001: ex_redirect = (ex_src1 != ex_src2);
          3'b100: ex_redirect = ($signed(ex_src1) < $signed(ex_src2));
          3'b101: ex_redirect = ($signed(ex_src1) >= $signed(ex_src2));
          3'b110: ex_redirect = (ex_src1 < ex_src2);
          3'b111: ex_redirect = (ex_src1 >= ex_src2);
          default: begin
            ex_halt_req = 1'b1;
            ex_halt_code = 32'd1;
          end
        endcase
        ex_redirect_pc = id_ex.pc + ex_imm_b;
      end
      7'b0000011: begin
        if (ex_funct3 == 3'b000 || ex_funct3 == 3'b001 || ex_funct3 == 3'b010 ||
            ex_funct3 == 3'b100 || ex_funct3 == 3'b101) begin
          ex_reg_write = 1'b1;
          ex_mem_read = 1'b1;
          ex_mem_len = mem_len_from_funct3(ex_funct3);
          ex_load_funct3 = ex_funct3;
          ex_alu_result = ex_src1 + ex_imm_i;
        end else begin
          ex_halt_req = 1'b1;
          ex_halt_code = 32'd1;
        end
      end
      7'b0100011: begin
        if (ex_funct3 == 3'b000 || ex_funct3 == 3'b001 || ex_funct3 == 3'b010) begin
          ex_mem_write = 1'b1;
          ex_mem_len = mem_len_from_funct3(ex_funct3);
          ex_alu_result = ex_src1 + ex_imm_s;
          ex_store_data = ex_src2;
        end else begin
          ex_halt_req = 1'b1;
          ex_halt_code = 32'd1;
        end
      end
      7'b0010011: begin
        ex_reg_write = 1'b1;
        unique case (ex_funct3)
          3'b000: ex_wb_data = ex_src1 + ex_imm_i;
          3'b010: ex_wb_data = ($signed(ex_src1) < $signed(ex_imm_i)) ? 32'd1 : 32'd0;
          3'b011: ex_wb_data = (ex_src1 < ex_imm_i) ? 32'd1 : 32'd0;
          3'b100: ex_wb_data = ex_src1 ^ ex_imm_i;
          3'b110: ex_wb_data = ex_src1 | ex_imm_i;
          3'b111: ex_wb_data = ex_src1 & ex_imm_i;
          3'b001: ex_wb_data = ex_src1 << id_ex.inst[24:20];
          3'b101: begin
            if (ex_funct7 == 7'b0100000) ex_wb_data = $signed(ex_src1) >>> id_ex.inst[24:20];
            else if (ex_funct7 == 7'b0000000) ex_wb_data = ex_src1 >> id_ex.inst[24:20];
            else begin
              ex_reg_write = 1'b0;
              ex_halt_req = 1'b1;
              ex_halt_code = 32'd1;
            end
          end
          default: begin end
        endcase
      end
      7'b0110011: begin
        ex_reg_write = 1'b1;
        unique case ({ex_funct7, ex_funct3})
          {7'b0000000, 3'b000}: ex_wb_data = ex_src1 + ex_src2;
          {7'b0100000, 3'b000}: ex_wb_data = ex_src1 - ex_src2;
          {7'b0000000, 3'b001}: ex_wb_data = ex_src1 << ex_src2[4:0];
          {7'b0000000, 3'b010}: ex_wb_data = ($signed(ex_src1) < $signed(ex_src2)) ? 32'd1 : 32'd0;
          {7'b0000000, 3'b011}: ex_wb_data = (ex_src1 < ex_src2) ? 32'd1 : 32'd0;
          {7'b0000000, 3'b100}: ex_wb_data = ex_src1 ^ ex_src2;
          {7'b0000000, 3'b101}: ex_wb_data = ex_src1 >> ex_src2[4:0];
          {7'b0100000, 3'b101}: ex_wb_data = $signed(ex_src1) >>> ex_src2[4:0];
          {7'b0000000, 3'b110}: ex_wb_data = ex_src1 | ex_src2;
          {7'b0000000, 3'b111}: ex_wb_data = ex_src1 & ex_src2;
          default: begin
            ex_reg_write = 1'b0;
            ex_halt_req = 1'b1;
            ex_halt_code = 32'd1;
          end
        endcase
      end
      7'b0001111: begin end
      7'b1110011: begin
        if (id_ex.inst == 32'h0010_0073) begin
          ex_halt_req = 1'b1;
          ex_halt_code = ex_src_a0;
        end else if (id_ex.inst == 32'h0000_0073) begin
          ex_ecall = 1'b1;
          ex_redirect = 1'b1;
          ex_redirect_pc = mtvec;
        end else if (id_ex.inst == 32'h3020_0073) begin
          ex_redirect = 1'b1;
          ex_redirect_pc = mepc;
        end else if (ex_funct3 == 3'b001 || ex_funct3 == 3'b010 || ex_funct3 == 3'b011 ||
                     ex_funct3 == 3'b101 || ex_funct3 == 3'b110 || ex_funct3 == 3'b111) begin
          logic [31:0] old_csr;
          logic [31:0] zimm;
          old_csr = csr_read(id_ex.inst[31:20]);
          zimm = {27'b0, ex_rs1};
          ex_reg_write = 1'b1;
          ex_wb_data = old_csr;
          ex_csr_addr = id_ex.inst[31:20];
          unique case (ex_funct3)
            3'b001: begin
              ex_csr_write = 1'b1;
              ex_csr_wdata = ex_src1;
            end
            3'b010: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = old_csr | ex_src1;
            end
            3'b011: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = old_csr & ~ex_src1;
            end
            3'b101: begin
              ex_csr_write = 1'b1;
              ex_csr_wdata = zimm;
            end
            3'b110: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = old_csr | zimm;
            end
            3'b111: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = old_csr & ~zimm;
            end
            default: begin end
          endcase
        end else begin
          ex_halt_req = 1'b1;
          ex_halt_code = 32'd1;
        end
      end
      default: begin
        ex_illegal = 1'b1;
        ex_halt_req = 1'b1;
        ex_halt_code = 32'd1;
      end
    endcase

    if (!id_ex.valid) begin
      ex_redirect = 1'b0;
      ex_mem_read = 1'b0;
      ex_mem_write = 1'b0;
      ex_reg_write = 1'b0;
      ex_halt_req = 1'b0;
      ex_csr_write = 1'b0;
      ex_ecall = 1'b0;
      ex_illegal = 1'b0;
    end
  end

  logic [31:0] mem_rdata;
  always_comb begin
    mem_rdata = 32'b0;
    if (!reset && ex_mem.valid && ex_mem.mem_read) begin
      mem_rdata = pmem_read(ex_mem.alu_result, ex_mem.mem_len);
    end
  end

  integer i;
  always_ff @(posedge clk) begin
    if (reset) begin
      pc <= RESET_VECTOR;
      halt <= 1'b0;
      halt_code <= 32'b0;
      halt_pending <= 1'b0;
      commit_pc <= RESET_VECTOR;
      commit_inst <= NOP_INST;
      if_id <= '0;
      id_ex <= '0;
      ex_mem <= '0;
      mem_wb <= '0;
      mstatus <= 32'h0000_1800;
      mtvec <= 32'b0;
      mepc <= 32'b0;
      mcause <= 32'b0;
      mie <= 32'b0;
      mip <= 32'b0;
      mscratch <= 32'b0;
      for (i = 0; i < 32; i = i + 1) begin
        regs[i] <= 32'b0;
      end
    end else if (!halt) begin
      if (mem_wb.valid) begin
        commit_pc <= mem_wb.pc;
        commit_inst <= mem_wb.inst;
        if (mem_wb.reg_write && mem_wb.rd != 5'b0) begin
          regs[mem_wb.rd] <= mem_wb.wb_data;
        end
        if (mem_wb.halt_req) begin
          halt <= 1'b1;
          halt_code <= mem_wb.halt_code;
          halt_pending <= 1'b0;
        end
      end

      if (ex_mem.valid && ex_mem.mem_write) begin
        pmem_write(ex_mem.alu_result, ex_mem.store_data, ex_mem.mem_len);
      end

      if (id_ex.valid) begin
        if (ex_ecall) begin
          mepc <= id_ex.pc;
          mcause <= 32'd11;
        end
        if (ex_csr_write) begin
          unique case (ex_csr_addr)
            12'h300: mstatus <= ex_csr_wdata;
            12'h304: mie <= ex_csr_wdata;
            12'h305: mtvec <= ex_csr_wdata;
            12'h340: mscratch <= ex_csr_wdata;
            12'h341: mepc <= ex_csr_wdata;
            12'h342: mcause <= ex_csr_wdata;
            12'h344: mip <= ex_csr_wdata;
            default: begin end
          endcase
        end
      end

      mem_wb.valid <= ex_mem.valid;
      mem_wb.pc <= ex_mem.pc;
      mem_wb.inst <= ex_mem.inst;
      mem_wb.rd <= ex_mem.rd;
      mem_wb.reg_write <= ex_mem.reg_write;
      mem_wb.wb_data <= ex_mem.mem_read ? sign_extend_load(mem_rdata, ex_mem.load_funct3)
                                        : ex_mem.wb_data;
      mem_wb.halt_req <= ex_mem.halt_req;
      mem_wb.halt_code <= ex_mem.halt_code;

      ex_mem.valid <= id_ex.valid;
      ex_mem.pc <= id_ex.pc;
      ex_mem.inst <= id_ex.inst;
      ex_mem.rd <= ex_rd;
      ex_mem.reg_write <= ex_reg_write;
      ex_mem.mem_read <= ex_mem_read;
      ex_mem.mem_write <= ex_mem_write;
      ex_mem.mem_len <= ex_mem_len;
      ex_mem.load_funct3 <= ex_load_funct3;
      ex_mem.alu_result <= ex_alu_result;
      ex_mem.store_data <= ex_store_data;
      ex_mem.wb_data <= ex_wb_data;
      ex_mem.halt_req <= ex_halt_req;
      ex_mem.halt_code <= ex_halt_code;

      if (ex_halt_req) begin
        halt_pending <= 1'b1;
      end

      if (ex_redirect || ex_halt_req || halt_pending) begin
        id_ex <= '0;
      end else if (load_use_stall) begin
        id_ex <= '0;
      end else begin
        id_ex.valid <= if_id.valid;
        id_ex.pc <= if_id.pc;
        id_ex.inst <= if_id.inst;
        id_ex.rd <= id_rd;
        id_ex.rs1 <= id_rs1;
        id_ex.rs2 <= id_rs2;
        id_ex.src1 <= read_gpr_for_id(id_rs1);
        id_ex.src2 <= read_gpr_for_id(id_rs2);
        id_ex.reg_write <= id_reg_write;
        id_ex.mem_read <= id_mem_read;
      end

      if (ex_redirect || ex_halt_req || halt_pending) begin
        if_id <= '0;
      end else if (load_use_stall) begin
        if_id <= if_id;
      end else begin
        if_id.valid <= 1'b1;
        if_id.pc <= pc;
        if_id.inst <= if_inst;
      end

      if (ex_redirect) begin
        pc <= ex_redirect_pc;
      end else if (ex_halt_req || halt_pending || load_use_stall) begin
        pc <= pc;
      end else begin
        pc <= pc + 32'd4;
      end

      regs[0] <= 32'b0;
    end
  end
endmodule
