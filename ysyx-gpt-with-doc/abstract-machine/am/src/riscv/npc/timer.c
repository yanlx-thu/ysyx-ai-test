#include <am.h>

#if defined(__PLATFORM_YSYXSOC)
#define YSYXSOC_TIMER_ADDR 0x3fffff00u

static inline uint32_t timer_read(uintptr_t addr) {
  return *(volatile uint32_t *)addr;
}
#endif

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
#if defined(__PLATFORM_YSYXSOC)
  uint32_t lo = timer_read(YSYXSOC_TIMER_ADDR);
  uint32_t hi = timer_read(YSYXSOC_TIMER_ADDR + 4);
  uptime->us = ((uint64_t)hi << 32) | lo;
#else
  uptime->us = 0;
#endif
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
