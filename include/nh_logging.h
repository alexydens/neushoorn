/* Include guard */
#if !defined(NH_LOGGING_H)
#define NH_LOGGING_H

#if defined(ENABLE_ASSERT)
#undef ASSERT_ONFAIL
#define ASSERT_ONFAIL(EXPR)       do{\
    nh_fatal(\
      "ASSERTION FAILED AT:\n"\
      "\t-> FILE:\t%s\n"\
      "\t-> LINE:\t%d\n"\
      "\t-> EXPR:\t%s\n",\
      __FILE__, __LINE__,\
      #EXPR\
    );\
  } while(0);
#endif
#define STRBOOL(VAL) ((VAL) ? "true" : "false")

/* Base library */
#include "nh_base.h"

/* C Stdlib Dependencies */
#include <stdio.h>    /* For input and output */
#include <stdarg.h>   /* For va_args */
#include <stdlib.h>   /* For exit() */
#include <time.h>     /* For current time */

/* Print some info */
extern void nh_info(const char* fmt, ...);
/* Print a warning */
extern void nh_warn(const char* fmt, ...);
/* Print an error */
extern void nh_error(const char* fmt, ...);
/* Print a fatal error, quit */
extern void nh_fatal(const char* fmt, ...);

#endif /* NH_LOGGING_H */
