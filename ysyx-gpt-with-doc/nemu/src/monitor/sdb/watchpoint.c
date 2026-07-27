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

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  char expr[128];
  word_t old_val;

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

int watchpoint_add(char *e) {
  if (e == NULL || *e == '\0') {
    printf("Usage: w EXPR\n");
    return -1;
  }

  if (free_ == NULL) {
    printf("No free watchpoint.\n");
    return -1;
  }

  bool success = false;
  word_t val = expr(e, &success);
  if (!success) {
    printf("Bad expression: %s\n", e);
    return -1;
  }

  WP *wp = free_;
  free_ = free_->next;
  wp->next = head;
  head = wp;
  snprintf(wp->expr, sizeof(wp->expr), "%s", e);
  wp->old_val = val;
  printf("Watchpoint %d: %s = " FMT_WORD "\n", wp->NO, wp->expr, wp->old_val);
  return wp->NO;
}

void watchpoint_delete(int no) {
  WP **p = &head;
  while (*p) {
    WP *wp = *p;
    if (wp->NO == no) {
      *p = wp->next;
      wp->next = free_;
      free_ = wp;
      printf("Delete watchpoint %d\n", no);
      return;
    }
    p = &wp->next;
  }
  printf("No watchpoint %d\n", no);
}

void watchpoint_display() {
  if (head == NULL) {
    printf("No watchpoints.\n");
    return;
  }

  for (WP *wp = head; wp; wp = wp->next) {
    printf("%d: %s = " FMT_WORD "\n", wp->NO, wp->expr, wp->old_val);
  }
}

bool watchpoint_check() {
  bool hit = false;
  for (WP *wp = head; wp; wp = wp->next) {
    bool success = false;
    word_t new_val = expr(wp->expr, &success);
    if (success && new_val != wp->old_val) {
      printf("Watchpoint %d hit: %s\n", wp->NO, wp->expr);
      printf("old value = " FMT_WORD ", new value = " FMT_WORD "\n", wp->old_val, new_val);
      wp->old_val = new_val;
      hit = true;
    }
  }
  return hit;
}
