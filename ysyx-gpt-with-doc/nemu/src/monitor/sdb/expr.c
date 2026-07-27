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
#include <memory/vaddr.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NEQ, TK_AND, TK_OR, TK_NUM, TK_HEX, TK_REG,
  TK_NEG, TK_DEREF,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},    // spaces
  {"0[xX][0-9a-fA-F]+", TK_HEX},
  {"[0-9]+", TK_NUM},
  {"\\$?[a-zA-Z][a-zA-Z0-9]*", TK_REG},
  {"==", TK_EQ},
  {"!=", TK_NEQ},
  {"&&", TK_AND},
  {"\\|\\|", TK_OR},
  {"\\+", '+'},         // plus
  {"-", '-'},
  {"\\*", '*'},
  {"/", '/'},
  {"!", '!'},
  {"\\(", '('},
  {"\\)", ')'},
};

#define NR_REGEX ARRLEN(rules)
#define NR_TOKEN 256

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[NR_TOKEN] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;

        int type = rules[i].token_type;
        if (type != TK_NOTYPE) {
          Assert(nr_token < NR_TOKEN, "too many tokens in expression");
          tokens[nr_token].type = type;
          Assert(substr_len < (int)sizeof(tokens[nr_token].str), "token is too long: %.*s", substr_len, substr_start);
          memcpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token ++;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  for (int i = 0; i < nr_token; i ++) {
    bool unary = (i == 0) ||
      !(tokens[i - 1].type == ')' || tokens[i - 1].type == TK_NUM ||
          tokens[i - 1].type == TK_HEX || tokens[i - 1].type == TK_REG);
    if (unary && tokens[i].type == '-') tokens[i].type = TK_NEG;
    if (unary && tokens[i].type == '*') tokens[i].type = TK_DEREF;
  }

  return true;
}

static bool check_parentheses(int l, int r) {
  if (tokens[l].type != '(' || tokens[r].type != ')') return false;

  int depth = 0;
  for (int i = l; i <= r; i ++) {
    if (tokens[i].type == '(') depth ++;
    else if (tokens[i].type == ')') {
      depth --;
      if (depth == 0 && i < r) return false;
      if (depth < 0) return false;
    }
  }
  return depth == 0;
}

static int precedence(int type) {
  switch (type) {
    case TK_OR: return 1;
    case TK_AND: return 2;
    case TK_EQ: case TK_NEQ: return 3;
    case '+': case '-': return 4;
    case '*': case '/': return 5;
    case TK_NEG: case TK_DEREF: case '!': return 6;
    default: return 0;
  }
}

static bool is_operator(int type) {
  return precedence(type) != 0;
}

static int dominant_operator(int l, int r) {
  int depth = 0;
  int op = -1;
  int min_prec = 100;

  for (int i = r; i >= l; i --) {
    int type = tokens[i].type;
    if (type == ')') {
      depth ++;
    } else if (type == '(') {
      depth --;
    } else if (depth == 0 && is_operator(type)) {
      int prec = precedence(type);
      if (prec < min_prec) {
        min_prec = prec;
        op = i;
      }
    }
  }

  return op;
}

static word_t eval(int l, int r, bool *success) {
  if (l > r) {
    *success = false;
    return 0;
  }

  if (l == r) {
    char *end = NULL;
    switch (tokens[l].type) {
      case TK_NUM:
        return strtoull(tokens[l].str, &end, 10);
      case TK_HEX:
        return strtoull(tokens[l].str, &end, 16);
      case TK_REG:
        return isa_reg_str2val(tokens[l].str, success);
      default:
        *success = false;
        return 0;
    }
  }

  if (check_parentheses(l, r)) {
    return eval(l + 1, r - 1, success);
  }

  int op = dominant_operator(l, r);
  if (op < 0) {
    *success = false;
    return 0;
  }

  int type = tokens[op].type;
  if (type == TK_NEG || type == TK_DEREF || type == '!') {
    word_t val = eval(op + 1, r, success);
    if (!*success) return 0;
    if (type == TK_NEG) return -val;
    if (type == TK_DEREF) return vaddr_read(val, 4);
    return !val;
  }

  word_t val1 = eval(l, op - 1, success);
  if (!*success) return 0;
  word_t val2 = eval(op + 1, r, success);
  if (!*success) return 0;

  switch (type) {
    case '+': return val1 + val2;
    case '-': return val1 - val2;
    case '*': return val1 * val2;
    case '/':
      if (val2 == 0) {
        *success = false;
        return 0;
      }
      return val1 / val2;
    case TK_EQ: return val1 == val2;
    case TK_NEQ: return val1 != val2;
    case TK_AND: return val1 && val2;
    case TK_OR: return val1 || val2;
    default:
      *success = false;
      return 0;
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  *success = true;
  return eval(0, nr_token - 1, success);
}
