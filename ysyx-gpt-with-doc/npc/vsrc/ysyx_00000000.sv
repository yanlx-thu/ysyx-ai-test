module ysyx_00000000(
  input  logic        clock,
  input  logic        reset,
  input  logic        io_interrupt,
  input  logic        io_master_awready,
  output logic        io_master_awvalid,
  output logic [31:0] io_master_awaddr,
  output logic [3:0]  io_master_awid,
  output logic [7:0]  io_master_awlen,
  output logic [2:0]  io_master_awsize,
  output logic [1:0]  io_master_awburst,
  input  logic        io_master_wready,
  output logic        io_master_wvalid,
  output logic [31:0] io_master_wdata,
  output logic [3:0]  io_master_wstrb,
  output logic        io_master_wlast,
  output logic        io_master_bready,
  input  logic        io_master_bvalid,
  input  logic [1:0]  io_master_bresp,
  input  logic [3:0]  io_master_bid,
  input  logic        io_master_arready,
  output logic        io_master_arvalid,
  output logic [31:0] io_master_araddr,
  output logic [3:0]  io_master_arid,
  output logic [7:0]  io_master_arlen,
  output logic [2:0]  io_master_arsize,
  output logic [1:0]  io_master_arburst,
  output logic        io_master_rready,
  input  logic        io_master_rvalid,
  input  logic [1:0]  io_master_rresp,
  input  logic [31:0] io_master_rdata,
  input  logic        io_master_rlast,
  input  logic [3:0]  io_master_rid,
  output logic        io_slave_awready,
  input  logic        io_slave_awvalid,
  input  logic [31:0] io_slave_awaddr,
  input  logic [3:0]  io_slave_awid,
  input  logic [7:0]  io_slave_awlen,
  input  logic [2:0]  io_slave_awsize,
  input  logic [1:0]  io_slave_awburst,
  output logic        io_slave_wready,
  input  logic        io_slave_wvalid,
  input  logic [31:0] io_slave_wdata,
  input  logic [3:0]  io_slave_wstrb,
  input  logic        io_slave_wlast,
  input  logic        io_slave_bready,
  output logic        io_slave_bvalid,
  output logic [1:0]  io_slave_bresp,
  output logic [3:0]  io_slave_bid,
  output logic        io_slave_arready,
  input  logic        io_slave_arvalid,
  input  logic [31:0] io_slave_araddr,
  input  logic [3:0]  io_slave_arid,
  input  logic [7:0]  io_slave_arlen,
  input  logic [2:0]  io_slave_arsize,
  input  logic [1:0]  io_slave_arburst,
  input  logic        io_slave_rready,
  output logic        io_slave_rvalid,
  output logic [1:0]  io_slave_rresp,
  output logic [31:0] io_slave_rdata,
  output logic        io_slave_rlast,
  output logic [3:0]  io_slave_rid
);
`ifndef SYNTHESIS
  import "DPI-C" function void soc_cpu_commit(input int pc, input int inst);
  import "DPI-C" function void soc_cpu_tick(
    input int reset,
    input int state,
    input int pc,
    input int ifu_resp,
    input int ifu_rdata,
    input int lsu_resp
  );
`endif

  localparam logic [31:0] RESET_VECTOR = 32'h3000_0000;
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
    logic [1:0]  mem_size;
    logic [2:0]  load_funct3;
    logic [1:0]  addr_low;
    logic [31:0] alu_result;
    logic [31:0] store_wdata;
    logic [3:0]  store_wmask;
    logic [31:0] wb_data;
    logic        halt_req;
  } ex_mem_t;

  typedef struct packed {
    logic        valid;
    logic [31:0] pc;
    logic [31:0] inst;
    logic [4:0]  rd;
    logic        reg_write;
    logic [31:0] wb_data;
    logic        halt_req;
  } mem_wb_t;

  logic [31:0] regs [0:15];

  logic [31:0] mstatus;
  logic [31:0] mtvec;
  logic [31:0] mepc;
  logic [31:0] mcause;
  logic [31:0] mie;
  logic [31:0] mip;
  logic [31:0] mscratch;

  if_id_t  if_id;
  id_ex_t  id_ex;
  ex_mem_t ex_mem;
  mem_wb_t mem_wb;
  if_id_t  next_if_id;
  id_ex_t  next_id_ex;
  ex_mem_t next_ex_mem;
  mem_wb_t next_mem_wb;

  logic        fetch_busy;
  logic        fetch_discard;
  logic [31:0] fetch_pc;
  logic        fetch_buf_valid;
  logic [31:0] fetch_buf_pc;
  logic [31:0] fetch_buf_inst;
  logic [31:0] next_fetch_addr;

  logic halt;
  logic halt_pending;
  logic next_halt_v;

  logic [31:0] debug_pc;
  logic [31:0] fetched_pc;
  logic [31:0] fetched_inst;
  logic        fetch_resp;
  logic        fetch_resp_kept;
  logic        fetch_available;
  logic        consume_fetch;
  logic        take_redirect;
  logic        take_halt_req;
  logic        stop_fetch;
  logic        bus_in_next_ex_mem;
  logic        next_fetch_busy_v;
  logic        next_fetch_discard_v;
  logic [31:0] next_fetch_pc_v;
  logic        next_fetch_buf_valid_v;
  logic [31:0] next_fetch_buf_pc_v;
  logic [31:0] next_fetch_buf_inst_v;
  logic [31:0] next_fetch_addr_v;
  logic        next_halt_pending_v;

  logic        ifu_req_valid;
  logic [31:0] ifu_addr;
  logic        ifu_resp_valid;
  logic [31:0] ifu_rdata;
  logic        lsu_req_valid;
  logic [31:0] lsu_addr;
  logic [1:0]  lsu_size;
  logic        lsu_wen;
  logic [31:0] lsu_wdata;
  logic [3:0]  lsu_wmask;
  logic        lsu_resp_valid;
  logic [31:0] lsu_rdata;

  typedef enum logic [1:0] {
    AXI_IDLE,
    AXI_READ_ADDR,
    AXI_READ_DATA,
    AXI_WRITE
  } axi_state_t;

  axi_state_t  axi_state;
  logic        axi_req_lsu;
  logic        axi_aw_done;
  logic        axi_w_done;
  logic [31:0] axi_addr;
  logic [2:0]  axi_size;
  logic [31:0] axi_wdata;
  logic [3:0]  axi_wstrb;

  wire ex_mem_is_bus = ex_mem.valid && (ex_mem.mem_read || ex_mem.mem_write);
  wire lsu_can_req = ex_mem_is_bus && !fetch_busy;
  wire mem_complete = !ex_mem_is_bus || (lsu_can_req && lsu_resp_valid);
  wire mem_stall = ex_mem_is_bus && !mem_complete;

  assign ifu_req_valid = !reset && fetch_busy;
  assign ifu_addr = fetch_pc;

  assign lsu_req_valid = !reset && lsu_can_req;
  assign lsu_addr = ex_mem.alu_result;
  assign lsu_size = ex_mem.mem_size;
  assign lsu_wen = ex_mem.mem_write;
  assign lsu_wdata = ex_mem.store_wdata;
  assign lsu_wmask = ex_mem.store_wmask;

  wire axi_start_read = (axi_state == AXI_IDLE) &&
    ((lsu_req_valid && !lsu_wen) || ifu_req_valid);
  wire axi_start_read_lsu = lsu_req_valid && !lsu_wen;
  wire axi_start_write = (axi_state == AXI_IDLE) && lsu_req_valid && lsu_wen;
  wire axi_read_resp = (axi_state == AXI_READ_DATA) && io_master_rvalid;
  wire axi_write_resp = (axi_state == AXI_WRITE) && io_master_bvalid;

  assign ifu_resp_valid = axi_read_resp && !axi_req_lsu;
  assign ifu_rdata = io_master_rdata;
  assign lsu_resp_valid = (axi_read_resp && axi_req_lsu) || axi_write_resp;
  assign lsu_rdata = io_master_rdata;

  assign io_master_awvalid = (axi_state == AXI_WRITE) && !axi_aw_done;
  assign io_master_awaddr = axi_addr;
  assign io_master_awid = 4'h0;
  assign io_master_awlen = 8'h0;
  assign io_master_awsize = axi_size;
  assign io_master_awburst = 2'b01;
  assign io_master_wvalid = (axi_state == AXI_WRITE) && !axi_w_done;
  assign io_master_wdata = axi_wdata;
  assign io_master_wstrb = axi_wstrb;
  assign io_master_wlast = 1'b1;
  assign io_master_bready = (axi_state == AXI_WRITE);
  assign io_master_arvalid = (axi_state == AXI_READ_ADDR);
  assign io_master_araddr = axi_addr;
  assign io_master_arid = 4'h0;
  assign io_master_arlen = 8'h0;
  assign io_master_arsize = axi_size;
  assign io_master_arburst = 2'b01;
  assign io_master_rready = (axi_state == AXI_READ_DATA);

  assign io_slave_awready = 1'b0;
  assign io_slave_wready = 1'b0;
  assign io_slave_bvalid = 1'b0;
  assign io_slave_bresp = 2'b00;
  assign io_slave_bid = 4'h0;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid = 1'b0;
  assign io_slave_rresp = 2'b00;
  assign io_slave_rdata = 32'h0;
  assign io_slave_rlast = 1'b0;
  assign io_slave_rid = 4'h0;

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

  function automatic logic [31:0] load_extend(
    input logic [31:0] data,
    input logic [1:0]  addr_low,
    input logic [2:0]  funct3
  );
    logic [31:0] shifted;
    begin
      shifted = data >> {addr_low, 3'b000};
      case (funct3)
        3'b000: load_extend = {{24{shifted[7]}}, shifted[7:0]};
        3'b001: load_extend = {{16{shifted[15]}}, shifted[15:0]};
        3'b010: load_extend = data;
        3'b100: load_extend = {24'b0, shifted[7:0]};
        3'b101: load_extend = {16'b0, shifted[15:0]};
        default: load_extend = 32'b0;
      endcase
    end
  endfunction

  function automatic logic [1:0] bus_size_from_funct3(input logic [2:0] funct3);
    case (funct3)
      3'b000, 3'b100: bus_size_from_funct3 = 2'd0;
      3'b001, 3'b101: bus_size_from_funct3 = 2'd1;
      default:        bus_size_from_funct3 = 2'd2;
    endcase
  endfunction

  function automatic logic [3:0] store_mask(
    input logic [1:0] addr_low,
    input logic [2:0] funct3
  );
    case (funct3)
      3'b000: store_mask = 4'b0001 << addr_low;
      3'b001: store_mask = addr_low[1] ? 4'b1100 : 4'b0011;
      3'b010: store_mask = 4'b1111;
      default: store_mask = 4'b0000;
    endcase
  endfunction

  function automatic logic [31:0] store_data_align(
    input logic [1:0]  addr_low,
    input logic [2:0]  funct3,
    input logic [31:0] data
  );
    case (funct3)
      3'b000: store_data_align = {24'b0, data[7:0]} << {addr_low, 3'b000};
      3'b001: store_data_align = {16'b0, data[15:0]} << {addr_low[1], 4'b0000};
      3'b010: store_data_align = data;
      default: store_data_align = 32'b0;
    endcase
  endfunction

  function automatic logic [31:0] forward_value(
    input logic [4:0]  rs,
    input logic [31:0] raw
  );
    begin
      forward_value = raw;
      if (rs != 5'b0 && !rs[4]) begin
        if (ex_mem.valid && ex_mem.reg_write && !ex_mem.mem_read && ex_mem.rd == rs) begin
          forward_value = ex_mem.wb_data;
        end else if (mem_wb.valid && mem_wb.reg_write && mem_wb.rd == rs) begin
          forward_value = mem_wb.wb_data;
        end
      end
    end
  endfunction

  always_ff @(posedge clock) begin
    if (reset) begin
      axi_state <= AXI_IDLE;
      axi_req_lsu <= 1'b0;
      axi_aw_done <= 1'b0;
      axi_w_done <= 1'b0;
      axi_addr <= 32'b0;
      axi_size <= 3'd2;
      axi_wdata <= 32'b0;
      axi_wstrb <= 4'b0;
    end else begin
      unique case (axi_state)
        AXI_IDLE: begin
          axi_aw_done <= 1'b0;
          axi_w_done <= 1'b0;
          if (axi_start_write) begin
            axi_state <= AXI_WRITE;
            axi_req_lsu <= 1'b1;
            axi_addr <= lsu_addr;
            axi_size <= {1'b0, lsu_size};
            axi_wdata <= lsu_wdata;
            axi_wstrb <= lsu_wmask;
          end else if (axi_start_read) begin
            axi_state <= AXI_READ_ADDR;
            axi_req_lsu <= axi_start_read_lsu;
            axi_addr <= axi_start_read_lsu ? lsu_addr : ifu_addr;
            axi_size <= axi_start_read_lsu ? {1'b0, lsu_size} : 3'd2;
            axi_wdata <= 32'b0;
            axi_wstrb <= 4'b0;
          end
        end

        AXI_READ_ADDR: begin
          if (io_master_arready) begin
            axi_state <= AXI_READ_DATA;
          end
        end

        AXI_READ_DATA: begin
          if (io_master_rvalid) begin
            axi_state <= AXI_IDLE;
          end
        end

        AXI_WRITE: begin
          if (!axi_aw_done && io_master_awready) begin
            axi_aw_done <= 1'b1;
          end
          if (!axi_w_done && io_master_wready) begin
            axi_w_done <= 1'b1;
          end
          if (io_master_bvalid) begin
            axi_state <= AXI_IDLE;
            axi_aw_done <= 1'b0;
            axi_w_done <= 1'b0;
          end
        end

        default: begin
          axi_state <= AXI_IDLE;
        end
      endcase
    end
  end

  function automatic logic [31:0] read_gpr_for_id(input logic [4:0] rs);
    begin
      read_gpr_for_id = (rs == 5'b0 || rs[4]) ? 32'b0 : regs[rs[3:0]];
      if (rs != 5'b0 && !rs[4] && mem_wb.valid && mem_wb.reg_write && mem_wb.rd == rs) begin
        read_gpr_for_id = mem_wb.wb_data;
      end
    end
  endfunction

  function automatic logic rv32e_reg_illegal(input logic [31:0] inst);
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [4:0] rd;
    logic [4:0] rs1;
    logic [4:0] rs2;
    begin
      opcode = inst[6:0];
      funct3 = inst[14:12];
      rd = inst[11:7];
      rs1 = inst[19:15];
      rs2 = inst[24:20];
      rv32e_reg_illegal = 1'b0;

      unique case (opcode)
        7'b0110111, 7'b0010111, 7'b1101111, 7'b0000011, 7'b0010011: begin
          rv32e_reg_illegal = rd[4];
        end
        7'b1100111: begin
          rv32e_reg_illegal = rd[4] || rs1[4];
        end
        7'b1100011, 7'b0100011, 7'b0110011: begin
          rv32e_reg_illegal = rs1[4] || rs2[4] || (opcode == 7'b0110011 && rd[4]);
        end
        7'b1110011: begin
          if (funct3 == 3'b001 || funct3 == 3'b010 || funct3 == 3'b011) begin
            rv32e_reg_illegal = rd[4] || rs1[4];
          end else if (funct3 == 3'b101 || funct3 == 3'b110 || funct3 == 3'b111) begin
            rv32e_reg_illegal = rd[4];
          end
        end
        default: begin end
      endcase
    end
  endfunction

  wire [6:0] id_opcode = if_id.inst[6:0];
  wire [4:0] id_rd     = if_id.inst[11:7];
  wire [2:0] id_funct3 = if_id.inst[14:12];
  wire [4:0] id_rs1    = if_id.inst[19:15];
  wire [4:0] id_rs2    = if_id.inst[24:20];

  logic id_uses_rs1;
  logic id_uses_rs2;
  logic id_reg_write;
  logic id_mem_read;

  always_comb begin
    id_uses_rs1 = 1'b0;
    id_uses_rs2 = 1'b0;
    id_reg_write = 1'b0;
    id_mem_read = 1'b0;

    unique case (id_opcode)
      7'b0110111: id_reg_write = 1'b1;
      7'b0010111: id_reg_write = 1'b1;
      7'b1101111: id_reg_write = 1'b1;
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
    !mem_stall && if_id.valid && id_ex.valid && id_ex.mem_read && id_ex.rd != 5'b0 &&
    ((id_uses_rs1 && id_rs1 == id_ex.rd) ||
     (id_uses_rs2 && id_rs2 == id_ex.rd) ||
     (if_id.inst == 32'h0010_0073 && id_ex.rd == 5'd10));

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
  logic        ex_redirect;
  logic [31:0] ex_redirect_pc;
  logic        ex_reg_write;
  logic        ex_mem_read;
  logic        ex_mem_write;
  logic [1:0]  ex_mem_size;
  logic [2:0]  ex_load_funct3;
  logic [31:0] ex_alu_result;
  logic [31:0] ex_store_wdata;
  logic [3:0]  ex_store_wmask;
  logic [31:0] ex_wb_data;
  logic        ex_halt_req;
  logic        ex_csr_write;
  logic [11:0] ex_csr_addr;
  logic [31:0] ex_csr_wdata;
  logic        ex_ecall;

  always_comb begin
    logic [31:0] store_addr;
    logic [31:0] csr_old;
    logic [31:0] csr_zimm;

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

    store_addr = 32'b0;
    csr_old = 32'b0;
    csr_zimm = 32'b0;

    ex_next_pc = id_ex.pc + 32'd4;
    ex_redirect = 1'b0;
    ex_redirect_pc = ex_next_pc;
    ex_reg_write = 1'b0;
    ex_mem_read = 1'b0;
    ex_mem_write = 1'b0;
    ex_mem_size = 2'd2;
    ex_load_funct3 = ex_funct3;
    ex_alu_result = 32'b0;
    ex_store_wdata = 32'b0;
    ex_store_wmask = 4'b0;
    ex_wb_data = 32'b0;
    ex_halt_req = 1'b0;
    ex_csr_write = 1'b0;
    ex_csr_addr = id_ex.inst[31:20];
    ex_csr_wdata = 32'b0;
    ex_ecall = 1'b0;

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
          default: ex_halt_req = 1'b1;
        endcase
        ex_redirect_pc = id_ex.pc + ex_imm_b;
      end
      7'b0000011: begin
        if (ex_funct3 == 3'b000 || ex_funct3 == 3'b001 || ex_funct3 == 3'b010 ||
            ex_funct3 == 3'b100 || ex_funct3 == 3'b101) begin
          ex_reg_write = 1'b1;
          ex_mem_read = 1'b1;
          ex_mem_size = bus_size_from_funct3(ex_funct3);
          ex_load_funct3 = ex_funct3;
          ex_alu_result = ex_src1 + ex_imm_i;
        end else begin
          ex_halt_req = 1'b1;
        end
      end
      7'b0100011: begin
        if (ex_funct3 == 3'b000 || ex_funct3 == 3'b001 || ex_funct3 == 3'b010) begin
          store_addr = ex_src1 + ex_imm_s;
          ex_mem_write = 1'b1;
          ex_mem_size = bus_size_from_funct3(ex_funct3);
          ex_alu_result = store_addr;
          ex_store_wdata = store_data_align(store_addr[1:0], ex_funct3, ex_src2);
          ex_store_wmask = store_mask(store_addr[1:0], ex_funct3);
        end else begin
          ex_halt_req = 1'b1;
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
          3'b001: begin
            if (ex_funct7 == 7'b0000000) ex_wb_data = ex_src1 << id_ex.inst[24:20];
            else begin
              ex_reg_write = 1'b0;
              ex_halt_req = 1'b1;
            end
          end
          3'b101: begin
            if (ex_funct7 == 7'b0100000) ex_wb_data = $signed(ex_src1) >>> id_ex.inst[24:20];
            else if (ex_funct7 == 7'b0000000) ex_wb_data = ex_src1 >> id_ex.inst[24:20];
            else begin
              ex_reg_write = 1'b0;
              ex_halt_req = 1'b1;
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
          end
        endcase
      end
      7'b0001111: begin end
      7'b1110011: begin
        if (id_ex.inst == 32'h0010_0073) begin
          ex_halt_req = 1'b1;
          ex_wb_data = ex_src_a0;
        end else if (id_ex.inst == 32'h0000_0073) begin
          ex_ecall = 1'b1;
          ex_redirect = 1'b1;
          ex_redirect_pc = mtvec;
        end else if (id_ex.inst == 32'h3020_0073) begin
          ex_redirect = 1'b1;
          ex_redirect_pc = mepc;
        end else if (ex_funct3 == 3'b001 || ex_funct3 == 3'b010 || ex_funct3 == 3'b011 ||
                     ex_funct3 == 3'b101 || ex_funct3 == 3'b110 || ex_funct3 == 3'b111) begin
          csr_old = csr_read(id_ex.inst[31:20]);
          csr_zimm = {27'b0, ex_rs1};
          ex_reg_write = 1'b1;
          ex_wb_data = csr_old;
          ex_csr_addr = id_ex.inst[31:20];
          unique case (ex_funct3)
            3'b001: begin
              ex_csr_write = 1'b1;
              ex_csr_wdata = ex_src1;
            end
            3'b010: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = csr_old | ex_src1;
            end
            3'b011: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = csr_old & ~ex_src1;
            end
            3'b101: begin
              ex_csr_write = 1'b1;
              ex_csr_wdata = csr_zimm;
            end
            3'b110: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = csr_old | csr_zimm;
            end
            3'b111: begin
              ex_csr_write = (ex_rs1 != 5'b0);
              ex_csr_wdata = csr_old & ~csr_zimm;
            end
            default: begin end
          endcase
        end else begin
          ex_halt_req = 1'b1;
        end
      end
      default: begin
        ex_halt_req = 1'b1;
      end
    endcase

    if (rv32e_reg_illegal(id_ex.inst)) begin
      ex_redirect = 1'b0;
      ex_reg_write = 1'b0;
      ex_mem_read = 1'b0;
      ex_mem_write = 1'b0;
      ex_csr_write = 1'b0;
      ex_ecall = 1'b0;
      ex_halt_req = 1'b1;
    end

    if (!id_ex.valid) begin
      ex_redirect = 1'b0;
      ex_reg_write = 1'b0;
      ex_mem_read = 1'b0;
      ex_mem_write = 1'b0;
      ex_halt_req = 1'b0;
      ex_csr_write = 1'b0;
      ex_ecall = 1'b0;
    end
  end

  always_comb begin
    debug_pc = fetch_busy ? fetch_pc : next_fetch_addr;
    next_if_id = if_id;
    next_id_ex = id_ex;
    next_ex_mem = ex_mem;
    next_mem_wb = mem_wb;
    next_fetch_busy_v = fetch_busy;
    next_fetch_discard_v = fetch_discard;
    next_fetch_pc_v = fetch_pc;
    next_fetch_buf_valid_v = fetch_buf_valid;
    next_fetch_buf_pc_v = fetch_buf_pc;
    next_fetch_buf_inst_v = fetch_buf_inst;
    next_fetch_addr_v = next_fetch_addr;
    next_halt_pending_v = halt_pending;
    next_halt_v = halt;

    fetch_resp = fetch_busy && ifu_resp_valid;
    fetch_resp_kept = fetch_resp && !fetch_discard;
    fetch_available = fetch_buf_valid || fetch_resp_kept;
    fetched_pc = fetch_buf_valid ? fetch_buf_pc : fetch_pc;
    fetched_inst = fetch_buf_valid ? fetch_buf_inst : ifu_rdata;
    take_redirect = !mem_stall && ex_redirect;
    take_halt_req = !mem_stall && ex_halt_req;
    consume_fetch = !mem_stall && !load_use_stall && !take_redirect &&
                    !take_halt_req && !halt_pending && fetch_available;
    bus_in_next_ex_mem = next_ex_mem.valid && (next_ex_mem.mem_read || next_ex_mem.mem_write);
    stop_fetch = next_halt_pending_v || halt || bus_in_next_ex_mem;

    if (!halt) begin
      if (mem_wb.valid) begin
        if (mem_wb.halt_req) begin
          next_halt_v = 1'b1;
          next_halt_pending_v = 1'b0;
        end
      end

      if (fetch_resp) begin
        next_fetch_busy_v = 1'b0;
        next_fetch_discard_v = 1'b0;
        if (fetch_resp_kept && !consume_fetch && !take_redirect && !take_halt_req && !halt_pending) begin
          next_fetch_buf_valid_v = 1'b1;
          next_fetch_buf_pc_v = fetch_pc;
          next_fetch_buf_inst_v = ifu_rdata;
        end
      end

      if (consume_fetch && fetch_buf_valid) begin
        next_fetch_buf_valid_v = 1'b0;
      end

      if (mem_stall) begin
        next_mem_wb = '0;
      end else begin
        if (ex_mem.valid) begin
          next_mem_wb.valid = 1'b1;
          next_mem_wb.pc = ex_mem.pc;
          next_mem_wb.inst = ex_mem.inst;
          next_mem_wb.rd = ex_mem.rd;
          next_mem_wb.reg_write = ex_mem.reg_write;
          next_mem_wb.wb_data = ex_mem.mem_read
            ? load_extend(lsu_rdata, ex_mem.addr_low, ex_mem.load_funct3)
            : ex_mem.wb_data;
          next_mem_wb.halt_req = ex_mem.halt_req;
        end else begin
          next_mem_wb = '0;
        end

        next_ex_mem.valid = id_ex.valid;
        next_ex_mem.pc = id_ex.pc;
        next_ex_mem.inst = id_ex.inst;
        next_ex_mem.rd = ex_rd;
        next_ex_mem.reg_write = ex_reg_write;
        next_ex_mem.mem_read = ex_mem_read;
        next_ex_mem.mem_write = ex_mem_write;
        next_ex_mem.mem_size = ex_mem_size;
        next_ex_mem.load_funct3 = ex_load_funct3;
        next_ex_mem.addr_low = ex_alu_result[1:0];
        next_ex_mem.alu_result = ex_alu_result;
        next_ex_mem.store_wdata = ex_store_wdata;
        next_ex_mem.store_wmask = ex_store_wmask;
        next_ex_mem.wb_data = ex_wb_data;
        next_ex_mem.halt_req = ex_halt_req;

        if (take_halt_req) begin
          next_halt_pending_v = 1'b1;
        end

        if (take_redirect || take_halt_req || halt_pending) begin
          next_id_ex = '0;
          next_if_id = '0;
        end else if (load_use_stall) begin
          next_id_ex = '0;
        end else begin
          next_id_ex.valid = if_id.valid;
          next_id_ex.pc = if_id.pc;
          next_id_ex.inst = if_id.inst;
          next_id_ex.rd = id_rd;
          next_id_ex.rs1 = id_rs1;
          next_id_ex.rs2 = id_rs2;
          next_id_ex.src1 = read_gpr_for_id(id_rs1);
          next_id_ex.src2 = read_gpr_for_id(id_rs2);
          next_id_ex.reg_write = id_reg_write;
          next_id_ex.mem_read = id_mem_read;

          if (consume_fetch) begin
            next_if_id.valid = 1'b1;
            next_if_id.pc = fetched_pc;
            next_if_id.inst = fetched_inst;
            next_fetch_addr_v = fetched_pc + 32'd4;
          end else begin
            next_if_id = '0;
          end
        end
      end

      if (take_redirect) begin
        next_fetch_addr_v = ex_redirect_pc;
        next_fetch_buf_valid_v = 1'b0;
        if (next_fetch_busy_v) begin
          next_fetch_discard_v = 1'b1;
        end
      end

      if (take_halt_req || halt_pending) begin
        next_fetch_buf_valid_v = 1'b0;
        if (next_fetch_busy_v) begin
          next_fetch_discard_v = 1'b1;
        end
      end

      bus_in_next_ex_mem = next_ex_mem.valid && (next_ex_mem.mem_read || next_ex_mem.mem_write);
      stop_fetch = next_halt_pending_v || halt || bus_in_next_ex_mem;
      if (!next_fetch_busy_v && !next_fetch_buf_valid_v && !stop_fetch) begin
        next_fetch_busy_v = 1'b1;
        next_fetch_discard_v = 1'b0;
        next_fetch_pc_v = next_fetch_addr_v;
      end
    end
  end

  integer i;
  always_ff @(posedge clock) begin
`ifndef SYNTHESIS
    soc_cpu_tick({31'b0, reset}, {29'b0, halt, mem_stall, fetch_busy}, debug_pc,
                 {31'b0, ifu_resp_valid}, ifu_rdata, {31'b0, lsu_resp_valid});
`endif

    if (reset) begin
      if_id <= '0;
      id_ex <= '0;
      ex_mem <= '0;
      mem_wb <= '0;
      fetch_busy <= 1'b1;
      fetch_discard <= 1'b0;
      fetch_pc <= RESET_VECTOR;
      fetch_buf_valid <= 1'b0;
      fetch_buf_pc <= 32'b0;
      fetch_buf_inst <= NOP_INST;
      next_fetch_addr <= RESET_VECTOR + 32'd4;
      halt <= 1'b0;
      halt_pending <= 1'b0;
      mstatus <= 32'h0000_1800;
      mtvec <= 32'b0;
      mepc <= 32'b0;
      mcause <= 32'b0;
      mie <= 32'b0;
      mip <= 32'b0;
      mscratch <= 32'b0;
      for (i = 0; i < 16; i = i + 1) begin
        regs[i] <= 32'b0;
      end
    end else if (!halt) begin
      if (mem_wb.valid) begin
`ifndef SYNTHESIS
        soc_cpu_commit(mem_wb.pc, mem_wb.inst);
`endif
        if (mem_wb.reg_write && mem_wb.rd != 5'b0 && !mem_wb.rd[4]) begin
          regs[mem_wb.rd[3:0]] <= mem_wb.wb_data;
        end
      end

      if (!mem_stall && id_ex.valid) begin
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

      if_id <= next_if_id;
      id_ex <= next_id_ex;
      ex_mem <= next_ex_mem;
      mem_wb <= next_mem_wb;
      fetch_busy <= next_fetch_busy_v;
      fetch_discard <= next_fetch_discard_v;
      fetch_pc <= next_fetch_pc_v;
      fetch_buf_valid <= next_fetch_buf_valid_v;
      fetch_buf_pc <= next_fetch_buf_pc_v;
      fetch_buf_inst <= next_fetch_buf_inst_v;
      next_fetch_addr <= next_fetch_addr_v;
      halt <= next_halt_v;
      halt_pending <= next_halt_pending_v;
      regs[0] <= 32'b0;
    end
  end
endmodule
