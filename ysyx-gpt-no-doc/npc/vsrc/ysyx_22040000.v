module ysyx_22040000 #(
  parameter RESET_VECTOR = 32'h30000000,
  parameter CLINT_BASE   = 32'h02000000
) (
  input         clock,
  input         reset,
  input         io_interrupt,

  input         io_master_awready,
  output        io_master_awvalid,
  output [31:0] io_master_awaddr,
  output [3:0]  io_master_awid,
  output [7:0]  io_master_awlen,
  output [2:0]  io_master_awsize,
  output [1:0]  io_master_awburst,
  input         io_master_wready,
  output        io_master_wvalid,
  output [31:0] io_master_wdata,
  output [3:0]  io_master_wstrb,
  output        io_master_wlast,
  output        io_master_bready,
  input         io_master_bvalid,
  input  [1:0]  io_master_bresp,
  input  [3:0]  io_master_bid,
  input         io_master_arready,
  output        io_master_arvalid,
  output [31:0] io_master_araddr,
  output [3:0]  io_master_arid,
  output [7:0]  io_master_arlen,
  output [2:0]  io_master_arsize,
  output [1:0]  io_master_arburst,
  output        io_master_rready,
  input         io_master_rvalid,
  input  [1:0]  io_master_rresp,
  input  [31:0] io_master_rdata,
  input         io_master_rlast,
  input  [3:0]  io_master_rid,

  output        io_slave_awready,
  input         io_slave_awvalid,
  input  [31:0] io_slave_awaddr,
  input  [3:0]  io_slave_awid,
  input  [7:0]  io_slave_awlen,
  input  [2:0]  io_slave_awsize,
  input  [1:0]  io_slave_awburst,
  output        io_slave_wready,
  input         io_slave_wvalid,
  input  [31:0] io_slave_wdata,
  input  [3:0]  io_slave_wstrb,
  input         io_slave_wlast,
  input         io_slave_bready,
  output        io_slave_bvalid,
  output [1:0]  io_slave_bresp,
  output [3:0]  io_slave_bid,
  output        io_slave_arready,
  input         io_slave_arvalid,
  input  [31:0] io_slave_araddr,
  input  [3:0]  io_slave_arid,
  input  [7:0]  io_slave_arlen,
  input  [2:0]  io_slave_arsize,
  input  [1:0]  io_slave_arburst,
  input         io_slave_rready,
  output        io_slave_rvalid,
  output [1:0]  io_slave_rresp,
  output [31:0] io_slave_rdata,
  output        io_slave_rlast,
  output [3:0]  io_slave_rid
);

  localparam ST_FETCH  = 4'd0;
  localparam ST_IF_AR  = 4'd1;
  localparam ST_IF_R   = 4'd2;
  localparam ST_EXEC   = 4'd3;
  localparam ST_LD_AR  = 4'd4;
  localparam ST_LD_R   = 4'd5;
  localparam ST_ST_AW  = 4'd6;
  localparam ST_ST_B   = 4'd7;
  localparam ST_HALT   = 4'd8;

  localparam CAUSE_INST_MISALIGNED = 32'd0;
  localparam CAUSE_INST_FAULT      = 32'd1;
  localparam CAUSE_ILLEGAL         = 32'd2;
  localparam CAUSE_BREAKPOINT      = 32'd3;
  localparam CAUSE_LOAD_MISALIGN   = 32'd4;
  localparam CAUSE_LOAD_FAULT      = 32'd5;
  localparam CAUSE_STORE_MISALIGN  = 32'd6;
  localparam CAUSE_STORE_FAULT     = 32'd7;
  localparam CAUSE_ECALL_M         = 32'd11;

  localparam CSR_MVENDORID = 12'hf11;
  localparam CSR_MARCHID   = 12'hf12;
  localparam CSR_MSTATUS   = 12'h300;
  localparam CSR_MTVEC     = 12'h305;
  localparam CSR_MEPC      = 12'h341;
  localparam CSR_MCAUSE    = 12'h342;

  reg [3:0]  state;
  reg [31:0] pc;
  reg [31:0] inst;
  reg [31:0] inst_pc;

  reg [31:0] regs [0:15];
  reg [31:0] csr_mtvec;
  reg [31:0] csr_mepc;
  reg [31:0] csr_mcause;
  reg [63:0] mtime;

  reg        debug_halt /* verilator public_flat */;
  reg [31:0] debug_halt_code /* verilator public_flat */;
  reg [63:0] cycle_count /* verilator public_flat */;
  reg [63:0] instret_count /* verilator public_flat */;
  reg [63:0] icache_accesses /* verilator public_flat */;
  reg [63:0] icache_misses /* verilator public_flat */;
  reg [63:0] icache_miss_cycles /* verilator public_flat */;

  reg [1:0]  ic_valid;
  reg [26:0] ic_tag0;
  reg [26:0] ic_tag1;
  reg [31:0] ic0_word0;
  reg [31:0] ic0_word1;
  reg [31:0] ic0_word2;
  reg [31:0] ic0_word3;
  reg [31:0] ic1_word0;
  reg [31:0] ic1_word1;
  reg [31:0] ic1_word2;
  reg [31:0] ic1_word3;

  reg [31:0] miss_addr;
  reg        miss_index;
  reg [26:0] miss_tag;
  reg [1:0]  miss_word;
  reg [1:0]  miss_target_word;
  reg [31:0] miss_saved_inst;

  reg [31:0] mem_addr;
  reg [31:0] mem_wdata;
  reg [3:0]  mem_wstrb;
  reg [4:0]  mem_rd;
  reg [1:0]  mem_size;
  reg        mem_unsigned;

  reg [31:0] alu_a;
  reg [31:0] alu_b;
  reg [31:0] alu_y;
  reg [31:0] tmp_imm;
  reg [31:0] tmp_addr;
  reg [31:0] tmp_old_csr;
  reg [31:0] tmp_new_csr;
  reg        tmp_do_write;
  reg        tmp_take_branch;
  integer i;

  wire [6:0]  opcode = inst[6:0];
  wire [4:0]  rd     = inst[11:7];
  wire [2:0]  funct3 = inst[14:12];
  wire [4:0]  rs1    = inst[19:15];
  wire [4:0]  rs2    = inst[24:20];
  wire [6:0]  funct7 = inst[31:25];
  wire [11:0] csr_id = inst[31:20];

  wire if_hit0 = ic_valid[0] && (ic_tag0 == pc[31:5]);
  wire if_hit1 = ic_valid[1] && (ic_tag1 == pc[31:5]);
  wire if_hit  = pc[4] ? if_hit1 : if_hit0;

  function [31:0] sext;
    input [31:0] value;
    input integer width;
    begin
      sext = (value ^ (32'h1 << (width - 1))) - (32'h1 << (width - 1));
    end
  endfunction

  function [31:0] reg_read;
    input [4:0] idx;
    begin
      if (idx == 5'd0) begin
        reg_read = 32'b0;
      end else if (idx < 5'd16) begin
        reg_read = regs[idx[3:0]];
      end else begin
        reg_read = 32'b0;
      end
    end
  endfunction

  function [31:0] csr_read;
    input [11:0] csr;
    begin
      case (csr)
        CSR_MVENDORID: csr_read = 32'b0;
        CSR_MARCHID:   csr_read = 32'b0;
        CSR_MSTATUS:   csr_read = 32'h00001800;
        CSR_MTVEC:     csr_read = csr_mtvec;
        CSR_MEPC:      csr_read = csr_mepc;
        CSR_MCAUSE:    csr_read = csr_mcause;
        default:       csr_read = 32'b0;
      endcase
    end
  endfunction

  function csr_implemented;
    input [11:0] csr;
    begin
      case (csr)
        CSR_MVENDORID,
        CSR_MARCHID,
        CSR_MSTATUS,
        CSR_MTVEC,
        CSR_MEPC,
        CSR_MCAUSE: csr_implemented = 1'b1;
        default:    csr_implemented = 1'b0;
      endcase
    end
  endfunction

  function csr_write_allowed;
    input [11:0] csr;
    begin
      case (csr)
        CSR_MSTATUS,
        CSR_MTVEC,
        CSR_MEPC,
        CSR_MCAUSE: csr_write_allowed = 1'b1;
        default:    csr_write_allowed = 1'b0;
      endcase
    end
  endfunction

  function [31:0] ic_word;
    input index;
    input [1:0] word;
    begin
      if (index == 1'b0) begin
        case (word)
          2'd0: ic_word = ic0_word0;
          2'd1: ic_word = ic0_word1;
          2'd2: ic_word = ic0_word2;
          default: ic_word = ic0_word3;
        endcase
      end else begin
        case (word)
          2'd0: ic_word = ic1_word0;
          2'd1: ic_word = ic1_word1;
          2'd2: ic_word = ic1_word2;
          default: ic_word = ic1_word3;
        endcase
      end
    end
  endfunction

  function [31:0] load_extract;
    input [31:0] word;
    input [31:0] addr;
    input [1:0] size;
    input is_unsigned;
    reg [31:0] shifted;
    begin
      shifted = word >> {addr[1:0], 3'b000};
      case (size)
        2'd0: load_extract = is_unsigned ? {24'b0, shifted[7:0]} : sext({24'b0, shifted[7:0]}, 8);
        2'd1: load_extract = is_unsigned ? {16'b0, shifted[15:0]} : sext({16'b0, shifted[15:0]}, 16);
        default: load_extract = word;
      endcase
    end
  endfunction

  function [31:0] branch_imm;
    input [31:0] raw;
    begin
      branch_imm = sext({19'b0, raw[31], raw[7], raw[30:25], raw[11:8], 1'b0}, 13);
    end
  endfunction

  function [31:0] jal_imm;
    input [31:0] raw;
    begin
      jal_imm = sext({11'b0, raw[31], raw[19:12], raw[20], raw[30:21], 1'b0}, 21);
    end
  endfunction

  function [31:0] store_imm;
    input [31:0] raw;
    begin
      store_imm = sext({20'b0, raw[31:25], raw[11:7]}, 12);
    end
  endfunction

  function clint_addr;
    input [31:0] addr;
    begin
      clint_addr = (addr >= CLINT_BASE) && (addr <= (CLINT_BASE + 32'h0000ffff));
    end
  endfunction

  function [31:0] clint_read;
    input [31:0] addr;
    begin
      if (addr == (CLINT_BASE + 32'h0000bff8)) begin
        clint_read = mtime[31:0];
      end else if (addr == (CLINT_BASE + 32'h0000bffc)) begin
        clint_read = mtime[63:32];
      end else begin
        clint_read = 32'b0;
      end
    end
  endfunction

  task write_reg;
    input [4:0] idx;
    input [31:0] value;
    begin
      if ((idx != 5'd0) && (idx < 5'd16)) begin
        regs[idx[3:0]] <= value;
      end
    end
  endtask

  task write_csr;
    input [11:0] csr;
    input [31:0] value;
    begin
      case (csr)
        CSR_MSTATUS: begin
        end
        CSR_MTVEC: begin
          csr_mtvec <= value & 32'hfffffffc;
        end
        CSR_MEPC: begin
          csr_mepc <= value & 32'hfffffffc;
        end
        CSR_MCAUSE: begin
          csr_mcause <= value;
        end
        default: begin
        end
      endcase
    end
  endtask

  task raise_exception;
    input [31:0] cause;
    begin
      csr_mcause <= cause;
      csr_mepc <= inst_pc & 32'hfffffffc;
      pc <= csr_mtvec;
      state <= ST_FETCH;
    end
  endtask

  task invalidate_icache;
    begin
      ic_valid <= 2'b00;
    end
  endtask

  assign io_master_arvalid = (state == ST_IF_AR) || (state == ST_LD_AR);
  assign io_master_araddr  = (state == ST_LD_AR) ? (mem_addr & 32'hfffffffc) : miss_addr;
  assign io_master_arid    = 4'b0000;
  assign io_master_arlen   = (state == ST_IF_AR) ? 8'd3 : 8'd0;
  assign io_master_arsize  = 3'b010;
  assign io_master_arburst = 2'b01;
  assign io_master_rready  = (state == ST_IF_R) || (state == ST_LD_R);

  assign io_master_awvalid = (state == ST_ST_AW);
  assign io_master_awaddr  = mem_addr & 32'hfffffffc;
  assign io_master_awid    = 4'b0000;
  assign io_master_awlen   = 8'd0;
  assign io_master_awsize  = 3'b010;
  assign io_master_awburst = 2'b01;
  assign io_master_wvalid  = (state == ST_ST_AW);
  assign io_master_wdata   = mem_wdata;
  assign io_master_wstrb   = mem_wstrb;
  assign io_master_wlast   = 1'b1;
  assign io_master_bready  = (state == ST_ST_B);

  assign io_slave_awready  = 1'b0;
  assign io_slave_wready   = 1'b0;
  assign io_slave_bvalid   = 1'b0;
  assign io_slave_bresp    = 2'b00;
  assign io_slave_bid      = 4'b0000;
  assign io_slave_arready  = 1'b0;
  assign io_slave_rvalid   = 1'b0;
  assign io_slave_rresp    = 2'b00;
  assign io_slave_rdata    = 32'b0;
  assign io_slave_rlast    = 1'b0;
  assign io_slave_rid      = 4'b0000;

  wire _unused_inputs = io_interrupt ^
      io_master_bid[0] ^ io_master_rid[0] ^
      io_slave_awvalid ^ io_slave_awaddr[0] ^ io_slave_awid[0] ^
      io_slave_awlen[0] ^ io_slave_awsize[0] ^ io_slave_awburst[0] ^
      io_slave_wvalid ^ io_slave_wdata[0] ^ io_slave_wstrb[0] ^
      io_slave_wlast ^ io_slave_bready ^ io_slave_arvalid ^
      io_slave_araddr[0] ^ io_slave_arid[0] ^ io_slave_arlen[0] ^
      io_slave_arsize[0] ^ io_slave_arburst[0] ^ io_slave_rready;

  always @(posedge clock) begin
    if (reset) begin
      state <= ST_FETCH;
      pc <= RESET_VECTOR;
      inst <= 32'b0;
      inst_pc <= RESET_VECTOR;
      csr_mtvec <= 32'b0;
      csr_mepc <= 32'b0;
      csr_mcause <= 32'b0;
      mtime <= 64'b0;
      debug_halt <= 1'b0;
      debug_halt_code <= 32'b0;
      cycle_count <= 64'b0;
      instret_count <= 64'b0;
      icache_accesses <= 64'b0;
      icache_misses <= 64'b0;
      icache_miss_cycles <= 64'b0;
      ic_valid <= 2'b00;
      ic_tag0 <= 27'b0;
      ic_tag1 <= 27'b0;
      ic0_word0 <= 32'b0;
      ic0_word1 <= 32'b0;
      ic0_word2 <= 32'b0;
      ic0_word3 <= 32'b0;
      ic1_word0 <= 32'b0;
      ic1_word1 <= 32'b0;
      ic1_word2 <= 32'b0;
      ic1_word3 <= 32'b0;
      miss_addr <= 32'b0;
      miss_index <= 1'b0;
      miss_tag <= 27'b0;
      miss_word <= 2'b0;
      miss_target_word <= 2'b0;
      miss_saved_inst <= 32'b0;
      mem_addr <= 32'b0;
      mem_wdata <= 32'b0;
      mem_wstrb <= 4'b0;
      mem_rd <= 5'b0;
      mem_size <= 2'b0;
      mem_unsigned <= 1'b0;
      for (i = 0; i < 16; i = i + 1) begin
        regs[i] <= 32'b0;
      end
    end else begin
      cycle_count <= cycle_count + 64'd1;
      mtime <= mtime + 64'd1;
      regs[0] <= 32'b0;

      case (state)
        ST_FETCH: begin
          inst_pc <= pc;
          if (pc[1:0] != 2'b00) begin
            raise_exception(CAUSE_INST_MISALIGNED);
          end else begin
            icache_accesses <= icache_accesses + 64'd1;
            if (if_hit) begin
              inst <= ic_word(pc[4], pc[3:2]);
              state <= ST_EXEC;
            end else begin
              icache_misses <= icache_misses + 64'd1;
              miss_addr <= {pc[31:4], 4'b0000};
              miss_index <= pc[4];
              miss_tag <= pc[31:5];
              miss_word <= 2'd0;
              miss_target_word <= pc[3:2];
              miss_saved_inst <= 32'b0;
              state <= ST_IF_AR;
            end
          end
        end

        ST_IF_AR: begin
          icache_miss_cycles <= icache_miss_cycles + 64'd1;
          if (io_master_arready) begin
            state <= ST_IF_R;
          end
        end

        ST_IF_R: begin
          icache_miss_cycles <= icache_miss_cycles + 64'd1;
          if (io_master_rvalid) begin
            if (io_master_rresp != 2'b00) begin
              raise_exception(CAUSE_INST_FAULT);
            end else begin
              if (miss_index == 1'b0) begin
                case (miss_word)
                  2'd0: ic0_word0 <= io_master_rdata;
                  2'd1: ic0_word1 <= io_master_rdata;
                  2'd2: ic0_word2 <= io_master_rdata;
                  default: ic0_word3 <= io_master_rdata;
                endcase
              end else begin
                case (miss_word)
                  2'd0: ic1_word0 <= io_master_rdata;
                  2'd1: ic1_word1 <= io_master_rdata;
                  2'd2: ic1_word2 <= io_master_rdata;
                  default: ic1_word3 <= io_master_rdata;
                endcase
              end

              if (miss_word == miss_target_word) begin
                miss_saved_inst <= io_master_rdata;
              end

              if (io_master_rlast) begin
                if (miss_index == 1'b0) begin
                  ic_valid[0] <= 1'b1;
                  ic_tag0 <= miss_tag;
                end else begin
                  ic_valid[1] <= 1'b1;
                  ic_tag1 <= miss_tag;
                end
                inst <= (miss_word == miss_target_word) ? io_master_rdata : miss_saved_inst;
                state <= ST_EXEC;
              end else begin
                miss_word <= miss_word + 2'd1;
              end
            end
          end
        end

        ST_EXEC: begin
          instret_count <= instret_count + 64'd1;
          tmp_take_branch = 1'b0;
          tmp_imm = 32'b0;
          tmp_addr = 32'b0;
          tmp_old_csr = 32'b0;
          tmp_new_csr = 32'b0;
          tmp_do_write = 1'b0;
          alu_a = reg_read(rs1);
          alu_b = reg_read(rs2);
          alu_y = 32'b0;

          case (opcode)
            7'b0110111: begin
              if (rd >= 5'd16) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                write_reg(rd, {inst[31:12], 12'b0});
                pc <= inst_pc + 32'd4;
                state <= ST_FETCH;
              end
            end

            7'b0010111: begin
              if (rd >= 5'd16) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                write_reg(rd, inst_pc + {inst[31:12], 12'b0});
                pc <= inst_pc + 32'd4;
                state <= ST_FETCH;
              end
            end

            7'b1101111: begin
              if (rd >= 5'd16) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                write_reg(rd, inst_pc + 32'd4);
                pc <= inst_pc + jal_imm(inst);
                state <= ST_FETCH;
              end
            end

            7'b1100111: begin
              if ((funct3 != 3'b000) || (rd >= 5'd16) || (rs1 >= 5'd16)) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                write_reg(rd, inst_pc + 32'd4);
                pc <= (alu_a + sext({20'b0, inst[31:20]}, 12)) & 32'hfffffffe;
                state <= ST_FETCH;
              end
            end

            7'b1100011: begin
              if ((rs1 >= 5'd16) || (rs2 >= 5'd16)) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                case (funct3)
                  3'b000: tmp_take_branch = (alu_a == alu_b);
                  3'b001: tmp_take_branch = (alu_a != alu_b);
                  3'b100: tmp_take_branch = ($signed(alu_a) < $signed(alu_b));
                  3'b101: tmp_take_branch = ($signed(alu_a) >= $signed(alu_b));
                  3'b110: tmp_take_branch = (alu_a < alu_b);
                  3'b111: tmp_take_branch = (alu_a >= alu_b);
                  default: tmp_take_branch = 1'b0;
                endcase
                if ((funct3 == 3'b010) || (funct3 == 3'b011)) begin
                  raise_exception(CAUSE_ILLEGAL);
                end else begin
                  pc <= tmp_take_branch ? (inst_pc + branch_imm(inst)) : (inst_pc + 32'd4);
                  state <= ST_FETCH;
                end
              end
            end

            7'b0000011: begin
              if ((rd >= 5'd16) || (rs1 >= 5'd16)) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                tmp_addr = alu_a + sext({20'b0, inst[31:20]}, 12);
                mem_addr <= tmp_addr;
                mem_rd <= rd;
                mem_unsigned <= (funct3 == 3'b100) || (funct3 == 3'b101);
                case (funct3)
                  3'b000, 3'b100: begin
                    mem_size <= 2'd0;
                    if (clint_addr(tmp_addr)) begin
                      write_reg(rd, clint_read(tmp_addr));
                      pc <= inst_pc + 32'd4;
                      state <= ST_FETCH;
                    end else begin
                      state <= ST_LD_AR;
                    end
                  end
                  3'b001, 3'b101: begin
                    mem_size <= 2'd1;
                    if (tmp_addr[0]) begin
                      raise_exception(CAUSE_LOAD_MISALIGN);
                    end else if (clint_addr(tmp_addr)) begin
                      write_reg(rd, clint_read(tmp_addr));
                      pc <= inst_pc + 32'd4;
                      state <= ST_FETCH;
                    end else begin
                      state <= ST_LD_AR;
                    end
                  end
                  3'b010: begin
                    mem_size <= 2'd2;
                    if (tmp_addr[1:0] != 2'b00) begin
                      raise_exception(CAUSE_LOAD_MISALIGN);
                    end else if (clint_addr(tmp_addr)) begin
                      write_reg(rd, clint_read(tmp_addr));
                      pc <= inst_pc + 32'd4;
                      state <= ST_FETCH;
                    end else begin
                      state <= ST_LD_AR;
                    end
                  end
                  default: begin
                    raise_exception(CAUSE_ILLEGAL);
                  end
                endcase
              end
            end

            7'b0100011: begin
              if ((rs1 >= 5'd16) || (rs2 >= 5'd16)) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                tmp_addr = alu_a + store_imm(inst);
                mem_addr <= tmp_addr;
                case (funct3)
                  3'b000: begin
                    mem_size <= 2'd0;
                    mem_wdata <= alu_b << {tmp_addr[1:0], 3'b000};
                    mem_wstrb <= 4'b0001 << tmp_addr[1:0];
                    if (clint_addr(tmp_addr)) begin
                      pc <= inst_pc + 32'd4;
                      state <= ST_FETCH;
                    end else begin
                      state <= ST_ST_AW;
                    end
                  end
                  3'b001: begin
                    mem_size <= 2'd1;
                    mem_wdata <= alu_b << {tmp_addr[1], 4'b0000};
                    mem_wstrb <= tmp_addr[1] ? 4'b1100 : 4'b0011;
                    if (tmp_addr[0]) begin
                      raise_exception(CAUSE_STORE_MISALIGN);
                    end else if (clint_addr(tmp_addr)) begin
                      pc <= inst_pc + 32'd4;
                      state <= ST_FETCH;
                    end else begin
                      state <= ST_ST_AW;
                    end
                  end
                  3'b010: begin
                    mem_size <= 2'd2;
                    mem_wdata <= alu_b;
                    mem_wstrb <= 4'b1111;
                    if (tmp_addr[1:0] != 2'b00) begin
                      raise_exception(CAUSE_STORE_MISALIGN);
                    end else if (clint_addr(tmp_addr)) begin
                      pc <= inst_pc + 32'd4;
                      state <= ST_FETCH;
                    end else begin
                      state <= ST_ST_AW;
                    end
                  end
                  default: begin
                    raise_exception(CAUSE_ILLEGAL);
                  end
                endcase
              end
            end

            7'b0010011: begin
              if ((rd >= 5'd16) || (rs1 >= 5'd16)) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                tmp_imm = sext({20'b0, inst[31:20]}, 12);
                case (funct3)
                  3'b000: alu_y = alu_a + tmp_imm;
                  3'b010: alu_y = ($signed(alu_a) < $signed(tmp_imm)) ? 32'd1 : 32'd0;
                  3'b011: alu_y = (alu_a < tmp_imm) ? 32'd1 : 32'd0;
                  3'b100: alu_y = alu_a ^ tmp_imm;
                  3'b110: alu_y = alu_a | tmp_imm;
                  3'b111: alu_y = alu_a & tmp_imm;
                  3'b001: alu_y = (funct7 == 7'b0000000) ? (alu_a << inst[24:20]) : 32'b0;
                  3'b101: begin
                    if (funct7 == 7'b0000000) begin
                      alu_y = alu_a >> inst[24:20];
                    end else if (funct7 == 7'b0100000) begin
                      alu_y = $signed(alu_a) >>> inst[24:20];
                    end else begin
                      alu_y = 32'b0;
                    end
                  end
                  default: alu_y = 32'b0;
                endcase

                if (((funct3 == 3'b001) && (funct7 != 7'b0000000)) ||
                    ((funct3 == 3'b101) && (funct7 != 7'b0000000) && (funct7 != 7'b0100000))) begin
                  raise_exception(CAUSE_ILLEGAL);
                end else begin
                  write_reg(rd, alu_y);
                  pc <= inst_pc + 32'd4;
                  state <= ST_FETCH;
                end
              end
            end

            7'b0110011: begin
              if ((rd >= 5'd16) || (rs1 >= 5'd16) || (rs2 >= 5'd16)) begin
                raise_exception(CAUSE_ILLEGAL);
              end else begin
                case ({funct7, funct3})
                  10'b0000000_000: alu_y = alu_a + alu_b;
                  10'b0100000_000: alu_y = alu_a - alu_b;
                  10'b0000000_001: alu_y = alu_a << alu_b[4:0];
                  10'b0000000_010: alu_y = ($signed(alu_a) < $signed(alu_b)) ? 32'd1 : 32'd0;
                  10'b0000000_011: alu_y = (alu_a < alu_b) ? 32'd1 : 32'd0;
                  10'b0000000_100: alu_y = alu_a ^ alu_b;
                  10'b0000000_101: alu_y = alu_a >> alu_b[4:0];
                  10'b0100000_101: alu_y = $signed(alu_a) >>> alu_b[4:0];
                  10'b0000000_110: alu_y = alu_a | alu_b;
                  10'b0000000_111: alu_y = alu_a & alu_b;
                  default: alu_y = 32'hxxxxxxxx;
                endcase

                if (alu_y === 32'hxxxxxxxx) begin
                  raise_exception(CAUSE_ILLEGAL);
                end else begin
                  write_reg(rd, alu_y);
                  pc <= inst_pc + 32'd4;
                  state <= ST_FETCH;
                end
              end
            end

            7'b0001111: begin
              if (funct3 == 3'b001) begin
                invalidate_icache();
              end
              pc <= inst_pc + 32'd4;
              state <= ST_FETCH;
            end

            7'b1110011: begin
              if (funct3 == 3'b000) begin
                case (inst[31:20])
                  12'h000: begin
                    raise_exception(CAUSE_ECALL_M);
                  end
                  12'h001: begin
                    debug_halt <= 1'b1;
                    debug_halt_code <= reg_read(5'd10);
                    raise_exception(CAUSE_BREAKPOINT);
                  end
                  12'h302: begin
                    pc <= csr_mepc;
                    state <= ST_FETCH;
                  end
                  default: begin
                    raise_exception(CAUSE_ILLEGAL);
                  end
                endcase
              end else begin
                if ((rd >= 5'd16) ||
                    (((funct3 == 3'b001) || (funct3 == 3'b010) || (funct3 == 3'b011)) && (rs1 >= 5'd16)) ||
                    !csr_implemented(csr_id)) begin
                  raise_exception(CAUSE_ILLEGAL);
                end else begin
                  tmp_old_csr = csr_read(csr_id);
                  tmp_do_write = 1'b1;
                  case (funct3)
                    3'b001: tmp_new_csr = reg_read(rs1);
                    3'b010: begin
                      tmp_new_csr = tmp_old_csr | reg_read(rs1);
                      tmp_do_write = (rs1 != 5'd0);
                    end
                    3'b011: begin
                      tmp_new_csr = tmp_old_csr & ~reg_read(rs1);
                      tmp_do_write = (rs1 != 5'd0);
                    end
                    3'b101: tmp_new_csr = {27'b0, rs1};
                    3'b110: begin
                      tmp_new_csr = tmp_old_csr | {27'b0, rs1};
                      tmp_do_write = (rs1 != 5'd0);
                    end
                    3'b111: begin
                      tmp_new_csr = tmp_old_csr & ~{27'b0, rs1};
                      tmp_do_write = (rs1 != 5'd0);
                    end
                    default: begin
                      tmp_new_csr = 32'b0;
                      tmp_do_write = 1'b0;
                    end
                  endcase

                  if ((funct3 == 3'b000) || (tmp_do_write && !csr_write_allowed(csr_id))) begin
                    raise_exception(CAUSE_ILLEGAL);
                  end else begin
                    write_reg(rd, tmp_old_csr);
                    if (tmp_do_write) begin
                      write_csr(csr_id, tmp_new_csr);
                    end
                    pc <= inst_pc + 32'd4;
                    state <= ST_FETCH;
                  end
                end
              end
            end

            default: begin
              raise_exception(CAUSE_ILLEGAL);
            end
          endcase
        end

        ST_LD_AR: begin
          if (io_master_arready) begin
            state <= ST_LD_R;
          end
        end

        ST_LD_R: begin
          if (io_master_rvalid) begin
            if (io_master_rresp != 2'b00) begin
              raise_exception(CAUSE_LOAD_FAULT);
            end else begin
              write_reg(mem_rd, load_extract(io_master_rdata, mem_addr, mem_size, mem_unsigned));
              pc <= inst_pc + 32'd4;
              state <= ST_FETCH;
            end
          end
        end

        ST_ST_AW: begin
          if (io_master_awready && io_master_wready) begin
            state <= ST_ST_B;
          end
        end

        ST_ST_B: begin
          if (io_master_bvalid) begin
            if (io_master_bresp != 2'b00) begin
              raise_exception(CAUSE_STORE_FAULT);
            end else begin
              pc <= inst_pc + 32'd4;
              state <= ST_FETCH;
            end
          end
        end

        ST_HALT: begin
          state <= ST_HALT;
        end

        default: begin
          state <= ST_FETCH;
        end
      endcase
    end
  end

endmodule
