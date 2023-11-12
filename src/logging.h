/* Include guard */
#if !defined(NH_LOGGING_H)
#define NH_LOGGING_H

#define ASSERT_ONFAIL(EXPR)       do{\
    nh_fatal(\
      "ASSERTION FAILED AT:\n"\
      "\t-> FILE:\t%s\n"\
      "\t-> LINE:\t%d\n"\
      "\t-> FUNCTION:\t%s\n"\
      "\t-> EXPR:\t%s\n",\
      __FILE__, __LINE__,\
      __PRETTY_FUNCTION__, #EXPR\
    );\
  } while(0);

/* Base library */
#include "base.h"

/* Print some info */
NHAPI void nh_info(const char* fmt, ...);
/* Print a warning */
NHAPI void nh_warn(const char* fmt, ...);
/* Print an error */
NHAPI void nh_error(const char* fmt, ...);
/* Print a fatal error, quit */
NHAPI void nh_fatal(const char* fmt, ...);

#endif /* NH_LOGGING_H */
