/* Include guard */
#if !defined (NH_BASE_H)
#define NH_BASE_H

/* C Stdlib Dependencies */
#include <stdint.h>       /* Integer types */

/* -------------------------------------------------------------------------- */
/* CONTEXT CRACKING --------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* COMPILER */
/* Check for GNU C Compiler */
#if defined (__GNUC__)
#   define COMPILER_GCC        1
#endif
/* Check for Microsoft Visual C/C++ */
#if defined (_MSC_VER)
#   define COMPILER_MSVC       1
#endif

/* Put all unset to 0 */
#if !defined (COMPILER_GCC)
#   define COMPILER_GCC        0
#endif
#if !defined (COMPILER_MSVC)
#   define COMPILER_MSVC       0
#endif

/* ARCHITECTURE */
/* As defined by the GNU C Compiler */
#if defined (COMPILER_GCC)
#   if defined (__amd64__)
#     define CPU_AMD64         1
#   endif
#   if defined (__arm__)
#     define CPU_ARM           1
#   endif
#   if defined (__aarch64__)
#     define CPU_ARM64         1
#   endif
#   if defined (__i386__) || defined (__i486__) || defined (__i586__)\
  || defined (__i686__)
#     define CPU_X86           1
#   endif
#endif
/* As defined by the Microsoft Visual C/C++ compiler */
#if defined (COMPILER_MSVC)
#   if defined (_M_AMD64)
#     define CPU_AMD64         1
#   endif
#   if defined (_M_ARM)
#     define CPU_ARM           1
#   endif
#   if defined (_M_ARM64)
#     define CPU_ARM64         1
#   endif
#   if defined (_M_I86) || defined (_M_IX86)
#     define CPU_X86           1
#   endif
#endif
/* Put all uset to 0 */
#if !defined (CPU_AMD64)
#   define CPU_AMD64           0
#endif
#if !defined (CPU_ARM)
#   define CPU_ARM             0
#endif
#if !defined (CPU_ARM64)
#   define CPU_ARM64           0
#endif
#if !defined (CPU_X86)
#   define CPU_X86             0
#endif

/* OPERATING SYSTEM */
#if defined (__gnu_linux__)
#   define OS_LINUX            1
#endif
#if defined (__APPLE__) /* I have reason to believe this is just for GCC... */
#   define OS_MACOS            1
#endif
#if defined (_WIN32)
#   define OS_WINDOWS          1
#endif
/* Put all unset to 0 */
#if !defined (OS_LINUX)
#   define OS_LINUX            0
#endif
#if !defined (OS_MACOS)
#   define OS_MACOS            0
#endif
#if !defined (OS_WINDOWS)
#   define OS_WINDOWS          0
#endif

/* -------------------------------------------------------------------------- */
/* UTILITY MACROS ----------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* Make something a statement, from a macro */
#define AS_STMT(S)          do{S}while(0)

/* Clamp v to the range min - max */
#define CLAMP(V, MIN, MAX)  ((V) < (MIN) ? (MIN) : ((V) > (MAX) ? (MAX) : (V)))
/* Swap the values of the two variables */
#define SWAP(A, B)          AS_STMT( __typeof__(A) TMP = (A); A = (B); B = TMP; )
/* Get the bigger of the two values */
#define MAX(A, B)           ((A) > (B) ? (A) : (B))
/* Get the minimum of the two values */
#define MIN(A, B)           ((A) < (B) ? (A) : (B))

#define STRFROM_(S)         #S
/* Turn into string */
#define STRFROM(S)          STRFROM_(S)
#define CONCAT_(A, B)       A##B
/* Concatenate */
#define CONCAT(A, B)        CONCAT_(A, B)

/* Assertions */
static int _expr_val; /* used in the macro, so needs to be predefined */
#define ASSERT(EXPR)        AS_STMT(_expr_val = EXPR;\
                            if (!(_expr_val)) {ASSERT_ONFAIL(EXPR);})

#if defined(ENABLE_ASSERT)
#   if !defined(ASSERT_ONFAIL)
#     define ASSERT_ONFAIL(EXPR)       AS_STMT(*(char*)0=0;) /* segfaults */
#   endif
#else
#   if !defined(ASSERT_ONFAIL)
#     define ASSERT_ONFAIL(EXPR)
#   endif
#endif

/* -------------------------------------------------------------------------- */
/* TYPEDEFS ----------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* Unsigned integers */
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;
/* Signed integers */
typedef int8_t    i8;
typedef int16_t   i16;
typedef int32_t   i32;
typedef int64_t   i64;
/* Floating point numbers */
typedef float     f32;
typedef double    f64;
/* Boolean */
#if !defined (__cplusplus)
/* I don't plan on using C++, but I can't seem to convince coc.nvim that... */
/* (ik this isn't the plugin's fault but the specific language server's) */
typedef i8 bool;
enum { false, true };
#endif

/* -------------------------------------------------------------------------- */
/* GLOBAL CONSTS ------------------------------------------------------------ */
/* -------------------------------------------------------------------------- */

/*
 * NOTE:
 * Some compilers may complain about the 0x................lu consts. Deal with
 * this however you want.
 */

/* signed int min vals */
static i8   min_i8  = (i8) 0x80;
static i16  min_i16 = (i16)0x8000;
static i32  min_i32 = (i32)0x80000000;
static i64  min_i64 = (i64)0x8000000000000000lu;
/* signed int max vals */
static i8   max_i8  = (i8) 0x7f;
static i16  max_i16 = (i16)0x7fff;
static i32  max_i32 = (i32)0x7fffffff;
static i64  max_i64 = (i64)0x7ffffffffffffffflu;
/* unsigned int max vals */
static u8   max_u8  = (u8) 0xff;
static u16  max_u16 = (u16)0xffff;
static u32  max_u32 = (u32)0xffffffff;
static u64  max_u64 = (u64)0xfffffffffffffffflu;

/* f32 consts */
static f32  pi32    = 3.14159265359f;
static f32  e32     = 2.71828182846f;
/* f64 consts */
static f64  pi64    = 3.1415965359;
static f64  e64     = 2.71828182846;

/* -------------------------------------------------------------------------- */
/* FLOATING POINT STUFF ----------------------------------------------------- */
/* -------------------------------------------------------------------------- */

/* Infinity - Wrong case, I know */
#define inf_f32         (1.0f / 0.0f)
#define neginf_f32      (-1.0f / 0.0f)
#define inf_f64         (1.0 / 0.0)
#define neginf_f64      (-1.0 / 0.0)

/* Linear interpolation */
#define LERP(A, B, X)   ((A) < (B)) ? \
  ((A) + ((B)-(A)*(X))) \
  : ((A) + ((A)-(B)*(X)))

#endif /* NH_BASE_H */
