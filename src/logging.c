#include "logging.h"

/* C stdlib dependencies */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

void nh_info(const char* fmt, ...) {
  va_list ap;
  time_t current_time;
  struct tm * time_info;
  char timeString[9];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
  printf("[INFO:    %s]: ", timeString);
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
  printf("\n");
}
void nh_warn(const char* fmt, ...) {
  va_list ap;
  time_t current_time;
  struct tm * time_info;
  char timeString[9];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
  printf("[WARNING: %s]: ", timeString);
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
  printf("\n");
}
void nh_error(const char* fmt, ...) {
  va_list ap;
  time_t current_time;
  struct tm * time_info;
  char timeString[9];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
  printf("[ERROR:   %s]: ", timeString);
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
  printf("\n");
}
void nh_fatal(const char* fmt, ...) {
  va_list ap;
  time_t current_time;
  struct tm * time_info;
  char timeString[9];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);
  printf("[FATAL:   %s]: ", timeString);
  va_start(ap, fmt);
  vprintf(fmt, ap);
  va_end(ap);
  printf("\n");
  exit(-1);
}
