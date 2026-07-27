#include <am.h>

#define CLINT_MTIME 0x0200bff8u
#define TIMER_FREQ  1000000u

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  volatile uint32_t *mtime = (volatile uint32_t *)CLINT_MTIME;
  uint32_t hi0, lo, hi1;
  do {
    hi0 = mtime[1];
    lo = mtime[0];
    hi1 = mtime[1];
  } while (hi0 != hi1);
  uint64_t ticks = ((uint64_t)hi1 << 32) | lo;
  uptime->us = ticks * 1000000ull / TIMER_FREQ;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
