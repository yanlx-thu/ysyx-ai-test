#include <am.h>
#include <klib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

typedef struct {
  char *buf;
  size_t size;
  size_t count;
} out_t;

static void emit(out_t *out, char ch) {
  if (out->buf == NULL) {
    putch(ch);
  } else if (out->size != 0 && out->count + 1 < out->size) {
    out->buf[out->count] = ch;
  }
  out->count++;
}

static void emit_repeat(out_t *out, char ch, int count) {
  while (count-- > 0) {
    emit(out, ch);
  }
}

static int str_len_limit(const char *s, int limit) {
  int len = 0;
  while (s[len] != '\0' && (limit < 0 || len < limit)) {
    len++;
  }
  return len;
}

static void emit_str(out_t *out, const char *s, int width, int precision, bool left) {
  if (s == NULL) {
    s = "(null)";
  }
  int len = str_len_limit(s, precision);
  if (!left) emit_repeat(out, ' ', width - len);
  for (int i = 0; i < len; i++) emit(out, s[i]);
  if (left) emit_repeat(out, ' ', width - len);
}

static void emit_uint(out_t *out, uint64_t value, bool negative, unsigned base,
                      bool upper, int width, int precision, bool left,
                      bool zero, const char *prefix) {
  char digits[32];
  int ndigits = 0;
  const char *alphabet = upper ? "0123456789ABCDEF" : "0123456789abcdef";

  if (value == 0) {
    if (precision != 0) digits[ndigits++] = '0';
  } else {
    while (value != 0) {
      digits[ndigits++] = alphabet[value % base];
      value /= base;
    }
  }

  int prefix_len = prefix == NULL ? 0 : str_len_limit(prefix, -1);
  int sign_len = negative ? 1 : 0;
  int zeroes = precision > ndigits ? precision - ndigits : 0;
  int total = sign_len + prefix_len + zeroes + ndigits;
  char pad = (zero && precision < 0 && !left) ? '0' : ' ';

  if (!left && pad == ' ') emit_repeat(out, ' ', width - total);
  if (negative) emit(out, '-');
  for (int i = 0; i < prefix_len; i++) emit(out, prefix[i]);
  if (!left && pad == '0') emit_repeat(out, '0', width - total);
  emit_repeat(out, '0', zeroes);
  while (ndigits-- > 0) emit(out, digits[ndigits]);
  if (left) emit_repeat(out, ' ', width - total);
}

static uint64_t read_unsigned_arg(va_list *ap, int length) {
  if (length >= 2) return va_arg(*ap, unsigned long long);
  if (length == 1) return va_arg(*ap, unsigned long);
  return va_arg(*ap, unsigned int);
}

static int64_t read_signed_arg(va_list *ap, int length) {
  if (length >= 2) return va_arg(*ap, long long);
  if (length == 1) return va_arg(*ap, long);
  return va_arg(*ap, int);
}

static int kvformat(out_t *out, const char *fmt, va_list ap) {
  for (; *fmt != '\0'; fmt++) {
    if (*fmt != '%') {
      emit(out, *fmt);
      continue;
    }

    fmt++;
    if (*fmt == '%') {
      emit(out, '%');
      continue;
    }

    bool left = false;
    bool zero = false;
    bool more_flags = true;
    while (more_flags) {
      switch (*fmt) {
        case '-': left = true; fmt++; break;
        case '0': zero = true; fmt++; break;
        case '+':
        case ' ':
        case '#': fmt++; break;
        default: more_flags = false; break;
      }
    }

    int width = 0;
    if (*fmt == '*') {
      width = va_arg(ap, int);
      if (width < 0) {
        left = true;
        width = -width;
      }
      fmt++;
    } else {
      while (*fmt >= '0' && *fmt <= '9') {
        width = width * 10 + (*fmt++ - '0');
      }
    }

    int precision = -1;
    if (*fmt == '.') {
      fmt++;
      precision = 0;
      if (*fmt == '*') {
        precision = va_arg(ap, int);
        fmt++;
      } else {
        while (*fmt >= '0' && *fmt <= '9') {
          precision = precision * 10 + (*fmt++ - '0');
        }
      }
    }

    int length = 0;
    if (*fmt == 'l') {
      length = 1;
      fmt++;
      if (*fmt == 'l') {
        length = 2;
        fmt++;
      }
    } else if (*fmt == 'h') {
      fmt++;
      if (*fmt == 'h') fmt++;
    } else if (*fmt == 'z' || *fmt == 't' || *fmt == 'j') {
      length = 1;
      fmt++;
    }

    switch (*fmt) {
      case 'd':
      case 'i': {
        int64_t sv = read_signed_arg(&ap, length);
        bool neg = sv < 0;
        uint64_t uv = neg ? (~(uint64_t)sv + 1) : (uint64_t)sv;
        emit_uint(out, uv, neg, 10, false, width, precision, left, zero, NULL);
        break;
      }
      case 'u':
        emit_uint(out, read_unsigned_arg(&ap, length), false, 10, false,
                  width, precision, left, zero, NULL);
        break;
      case 'x':
      case 'X':
        emit_uint(out, read_unsigned_arg(&ap, length), false, 16, *fmt == 'X',
                  width, precision, left, zero, NULL);
        break;
      case 'o':
        emit_uint(out, read_unsigned_arg(&ap, length), false, 8, false,
                  width, precision, left, zero, NULL);
        break;
      case 'p':
        emit_uint(out, (uintptr_t)va_arg(ap, void *), false, 16, false,
                  width, precision, left, zero, "0x");
        break;
      case 'c': {
        char ch = (char)va_arg(ap, int);
        if (!left) emit_repeat(out, ' ', width - 1);
        emit(out, ch);
        if (left) emit_repeat(out, ' ', width - 1);
        break;
      }
      case 's':
        emit_str(out, va_arg(ap, const char *), width, precision, left);
        break;
      case '\0':
        fmt--;
        break;
      default:
        emit(out, '%');
        emit(out, *fmt);
        break;
    }
  }
  return (int)out->count;
}

int printf(const char *fmt, ...) {
  out_t out = { .buf = NULL, .size = 0, .count = 0 };
  va_list ap;
  va_start(ap, fmt);
  int ret = kvformat(&out, fmt, ap);
  va_end(ap);
  return ret;
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

int vsnprintf(char *buf, size_t n, const char *fmt, va_list ap) {
  out_t out = { .buf = buf, .size = n, .count = 0 };
  int ret = kvformat(&out, fmt, ap);
  if (buf != NULL && n != 0) {
    size_t pos = out.count < n ? out.count : n - 1;
    buf[pos] = '\0';
  }
  return ret;
}

#endif
