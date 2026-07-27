/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include "local-include/reg.h"
#include <stdio.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  int nr = MUXDEF(CONFIG_RVE, 16, 32);
  for (int i = 0; i < nr; i ++) {
    printf("%-3s " FMT_WORD "%c", regs[i], cpu.gpr[i], (i + 1) % 4 == 0 ? '\n' : ' ');
  }
  printf("pc  " FMT_WORD "\n", cpu.pc);
  printf("mstatus " FMT_WORD " mtvec " FMT_WORD " mepc " FMT_WORD " mcause " FMT_WORD "\n",
      cpu.mstatus, cpu.mtvec, cpu.mepc, cpu.mcause);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if (success) *success = true;
  if (strcmp(s, "pc") == 0 || strcmp(s, "$pc") == 0) return cpu.pc;

  const char *name = (s[0] == '$') ? s + 1 : s;
  int nr = MUXDEF(CONFIG_RVE, 16, 32);
  for (int i = 0; i < nr; i ++) {
    if (strcmp(name, regs[i]) == 0) return cpu.gpr[i];
  }

  if (success) *success = false;
  return 0;
}
