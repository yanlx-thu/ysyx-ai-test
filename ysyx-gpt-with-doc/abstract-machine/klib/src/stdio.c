#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  char buf[1024];
  va_list ap;
  va_start(ap, fmt);
  int n = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);
  for (int i = 0; buf[i] != '\0'; i ++) putch(buf[i]);
  return n;
}

static void out_char(char *out, size_t n, int *cnt, char ch) {
  if (n > 0 && (size_t)*cnt + 1 < n) out[*cnt] = ch;
  (*cnt) ++;
}

static void out_str(char *out, size_t n, int *cnt, const char *s) {
  if (s == NULL) s = "(null)";
  while (*s) out_char(out, n, cnt, *s++);
}

static void out_uint(char *out, size_t n, int *cnt, uint64_t val, int base, bool neg, int width, char pad) {
  char buf[32];
  int pos = 0;
  if (val == 0) {
    buf[pos++] = '0';
  } else {
    while (val != 0) {
      int digit = val % base;
      buf[pos++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
      val /= base;
    }
  }
  int len = pos + (neg ? 1 : 0);
  while (width > len) {
    out_char(out, n, cnt, pad);
    width --;
  }
  if (neg) out_char(out, n, cnt, '-');
  while (pos > 0) out_char(out, n, cnt, buf[--pos]);
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, (size_t)-1, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, (size_t)-1, fmt, ap);
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  int cnt = 0;

  for (; *fmt; fmt ++) {
    if (*fmt != '%') {
      out_char(out, n, &cnt, *fmt);
      continue;
    }

    fmt ++;
    if (*fmt == '%') {
      out_char(out, n, &cnt, '%');
      continue;
    }

    char pad = ' ';
    if (*fmt == '0') {
      pad = '0';
      fmt ++;
    }

    int width = 0;
    while (*fmt >= '0' && *fmt <= '9') {
      width = width * 10 + *fmt - '0';
      fmt ++;
    }

    int long_cnt = 0;
    while (*fmt == 'l') {
      long_cnt ++;
      fmt ++;
    }

    switch (*fmt) {
      case 'c':
        out_char(out, n, &cnt, (char)va_arg(ap, int));
        break;
      case 's':
        out_str(out, n, &cnt, va_arg(ap, const char *));
        break;
      case 'd':
      case 'i': {
        int64_t v = (long_cnt >= 2) ? va_arg(ap, long long) :
                    (long_cnt == 1) ? va_arg(ap, long) : va_arg(ap, int);
        bool neg = v < 0;
        uint64_t u = neg ? -v : v;
        out_uint(out, n, &cnt, u, 10, neg, width, pad);
        break;
      }
      case 'u': {
        uint64_t v = (long_cnt >= 2) ? va_arg(ap, unsigned long long) :
                     (long_cnt == 1) ? va_arg(ap, unsigned long) : va_arg(ap, unsigned int);
        out_uint(out, n, &cnt, v, 10, false, width, pad);
        break;
      }
      case 'x':
      case 'X': {
        uint64_t v = (long_cnt >= 2) ? va_arg(ap, unsigned long long) :
                     (long_cnt == 1) ? va_arg(ap, unsigned long) : va_arg(ap, unsigned int);
        out_uint(out, n, &cnt, v, 16, false, width, pad);
        break;
      }
      case 'p': {
        uintptr_t v = (uintptr_t)va_arg(ap, void *);
        out_str(out, n, &cnt, "0x");
        out_uint(out, n, &cnt, v, 16, false, width, pad);
        break;
      }
      default:
        out_char(out, n, &cnt, '%');
        out_char(out, n, &cnt, *fmt);
        break;
    }
  }

  if (n > 0) {
    size_t pos = (size_t)cnt < n ? (size_t)cnt : n - 1;
    out[pos] = '\0';
  }
  return cnt;
}

#endif
