/* Implements nh_logging.h */
#include "../ext/nh_logging.h"

/* stdlib headers */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

const char *LOG_LEVEL_STRINGS[] = {
  "\x1b[32mINFO\x1b[0m",
  "\x1b[93mWARNING\x1b[0m",
  "\x1b[31mERROR\x1b[0m",
  "\x1b[31;1mFATAL\x1b[0m"
};

void _nh_log(
    nh_log_level_t level,
    const char *file,
    const char *function,
    const int line,
    const char *fmt,
    ... 
) {
  printf(
      "[%s \x1b[90m%s@%s:%d\x1b[0m]: ",
      LOG_LEVEL_STRINGS[level],
      function,
      file,
      line
  );
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
  if (level == NH_LOG_FATAL) {
    exit(EXIT_FAILURE);
  }
}
void _nh_log_entry(const char *fmt, ...) {
  printf("\t-> ");
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
}
