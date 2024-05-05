/* Include guard */
#if !defined(NH_LOGGING_H)
#define NH_LOGGING_H

/* Log levels */
typedef enum nh_log_level_t {
  NH_LOG_INFO = 0,
  NH_LOG_WARNING = 1,
  NH_LOG_ERROR = 2,
  NH_LOG_FATAL = 3
} nh_log_level_t;

/* Macro wrappers */
/* Log some information */
#define NH_INFO(fmt, ...) _nh_log(\
    NH_LOG_INFO,                  \
    __FILE__,                     \
    __PRETTY_FUNCTION__,          \
    __LINE__,                     \
    fmt,                          \
    ##__VA_ARGS__                 \
  )
/* Log a warning */
#define NH_WARN(fmt, ...) _nh_log(\
    NH_LOG_WARNING,               \
    __FILE__,                     \
    __PRETTY_FUNCTION__,          \
    __LINE__,                     \
    fmt,                          \
    ##__VA_ARGS__                 \
  )
/* Log an error */
#define NH_ERROR(fmt, ...) _nh_log(\
    NH_LOG_ERROR,                 \
    __FILE__,                     \
    __PRETTY_FUNCTION__,          \
    __LINE__,                     \
    fmt,                          \
    ##__VA_ARGS__                 \
  )
/* Log a fatal error */
#define NH_FATAL(fmt, ...) _nh_log(\
    NH_LOG_FATAL,                 \
    __FILE__,                     \
    __PRETTY_FUNCTION__,          \
    __LINE__,                     \
    fmt,                          \
    ##__VA_ARGS__                 \
  )
/* Get a string representation of a boolean */
#define BOOLSTR_COL(x) ((x) ? "\x1b[32mtrue\x1b[0m" : "\x1b[31mfalse\x1b[0m")
/* Log an entry in a list */
#define NH_LOG_ENTRY(fmt, ...) _nh_log_entry(fmt, ##__VA_ARGS__)
/* Assertions */
#if defined(DEBUG)
#define NH_ASSERT_MSG(expr, msg)      if (!(expr)) {\
    NH_FATAL("Assertion failed: %s", msg);\
  }
#define NH_ASSERT(expr)               if (!(expr)) {\
    NH_FATAL("Assertion failed: %s", #expr);\
  }
#else
#define NH_ASSERT_MSG(expr, msg)      (void)(expr)
#define NH_ASSERT(expr)               (void)(expr)
#endif

/* Internal */
extern void _nh_log(
    nh_log_level_t level,
    const char *file,
    const char *function,
    const int line,
    const char *fmt,
    ... 
);
/* Internal */
extern void _nh_log_entry(const char *fmt, ...);

#endif /* NH_LOGGING_H */
