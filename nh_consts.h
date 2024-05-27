/* Include guard */
#if !defined(NH_CONSTS_H)
#define NH_CONSTS_H

/* Mathematical constants */
#define NH_PI        3.14159265358979323846f  /* Pi */
#define NH_E         2.71828182845904523536f  /* Euler's number */
/* Size prefixes */
#define NH_KB        1024                     /* 1 KiB in bytes */
#define NH_MB        NH_KB * 1024             /* 1 MiB in bytes */
#define NH_GB        NH_MB * 1024             /* 1 GiB in bytes */
#define NH_TB        NH_GB * 1024             /* 1 TiB in bytes */
/* Minimum and max for each type */
#define NH_MIN_I8    -128                     /* Minimum for i8 */
#define NH_MAX_I8     127                     /* Maximum for i8 */
#define NH_MIN_I16   -32768                   /* Minimum for i16 */
#define NH_MAX_I16    32767                   /* Maximum for i16 */
#define NH_MIN_I32   -2147483648              /* Minimum for i32 */
#define NH_MAX_I32    2147483647              /* Maximum for i32 */
#define NH_MIN_I64   -9223372036854775808     /* Minimum for i64 */
#define NH_MAX_I64    9223372036854775807     /* Maximum for i64 */
#define NH_MAX_U8    255                      /* Maximum for u8 */
#define NH_MAX_U16   65535                    /* Maximum for u16 */
#define NH_MAX_U32   4294967295               /* Maximum for u32 */
#define NH_MAX_U64   18446744073709551615     /* Maximum for u64 */
/* Infinity and NaN */
#define NH_NAN       (0.0f/0.0f)              /* NaN */
#define NH_INF       (1.0f/0.0f)              /* Infinity */
/* A null pointer */
#define NH_NULL      ((void *)0)              /* Null pointer */
/* A sentence of lorem ipsum */
#define NH_LOREM    "Lorem ipsum dolor sit "  \
                    "amet, qui minim labore " \
                    "adipisicing minim sint " \
                    "cillum sint consectetur "\
                    "cupidatat."

#endif /* NH_CONSTS_H */
