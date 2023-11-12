/*
 * NOTES:
 * -  make sure to add -lm(oe) to linker flags when compiling.
 * -  define DEBUG for assertions, etc.
 */

/* Include guard */
#if !defined(NH_BASE_H)
#define NH_BASE_H

/* C stdlib dependencies */
#include <stdint.h>     /* For the right sized integer types */

/* Using static and extern - making them sound more meaningful */
#define NHAPI   extern
#define NHCONST static

/* If debug defined */
#if defined(DEBUG)
#   define(ENABLE_ASSERT)
#endif

/*
 * Operating system:
 * -  The OS_ and CPU_ macros have two versions: the regular, which is a bool val,
 *    and the NOVAL_ version, which is either defined or not
 */
#if defined(_WIN32)
#   define OS_WINDOWS   1
#   define OS_NOVAL_WINDOWS
#else
#   define OS_WINDOWS   0
#endif
#if defined(__linux__)
#   define OS_LINUX     1
#   define OS_NOVAL_LINUX
#else
#   define OS_LINUX     0
#endif
#if defined(__APPLE__)
#   define OS_MACOS     1
#   define OS_NOVAL_MACOS
#else
#   define OS_MACOS     0
#endif

/*
 * System architecture:
 */
#if defined(__arm__)
#   define CPU_ARM      1
#   define CPU_NOVAL_ARM
#else
#   define CPU_ARM      0
#endif
#if defined(__aarch64__)
#   define CPU_ARM64    1
#   define CPU_NOVAL_ARM64
#else
#   define CPU_ARM64    0
#endif
#if defined(__i386__)
#   define CPU_X86      1
#   define CPU_NOVAL_X86
#else
#   define CPU_X86      0
#endif
#if defined(__x86_64)
#   define CPU_X86_64   1
#   define CPU_NOVAL_X86_64
#else
#   define CPU_X86_64   0
#endif

/*
 * Utility macros:
 * -  AS_STMT is used for other macros, so that they can be used as a statement.
 * -  STRFROM_ and CONCAT_ are there to make the macros do what they say.
 */
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

/* The length of an array */
#define ARRLEN(A)           (sizeof(A)/sizeof(*A))

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
#     define ASSERT_ONFAIL(EXPR)       AS_STMT(*(i32*)0=0;)
#   endif
#else
#   if !defined(ASSERT_ONFAIL)
#     define ASSERT_ONFAIL(EXPR)
#   endif
#endif

/*
 * Typedefs:
 * -  The simple types.
 * -  Signed and unsigned integers, real numbers and booleans.
 * - A specific VoidFunc type, used becuase passing a function pointer as void*
 *   is technically not correct. Instead use VoidFunc*.
 */
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
typedef i8 bool;
enum { false, true };

/* When passing a function pointer to a function, do not use void, use this */
typedef void VoidFunc(void);

/*
 * Compound types:
 * -  2D and 3D vectors, with types i32 and f32.
 * -  m4f32, a 4 by 4 matrix.
 * - A color structure, which can be interpreted as an unsigned integer and will
 *   still hold the same color.
 */
/* i32 vectors */
typedef struct {
    i32 x;
    i32 y;
} v2i32;
typedef struct {
    i32 x;
    i32 y;
    i32 z;
} v3i32;
/* f32 vectors */
typedef struct {
    f32 x;
    f32 y;
} v2f32;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} v3f32;

/* 
 * Indexing:
 *  0  4  8 12
 *  1  5  9 13
 *  2  6 10 14
 *  3  7 11 15
 */
typedef struct {
  f32 vals[16];
} m4f32;

typedef union {
  struct {
    u8 a;
    u8 b;
    u8 g;
    u8 r;
  } col;
  u32 uint;
} Color;

/*
 * Global consts:
 * -  Min and max for all the types where it is relevant.
 * -  The Minimum prescision for floats and doubles.
 * -  Pi, and euler's number.
 */
/* signed int min vals */
NHCONST i8   min_i8  = (i8) 0x80;
NHCONST i16  min_i16 = (i16)0x8000;
NHCONST i32  min_i32 = (i32)0x80000000;
NHCONST i64  min_i64 = (i64)0x8000000000000000lu;
/* signed int max vals */
NHCONST i8   max_i8  = (i8) 0x7f;
NHCONST i16  max_i16 = (i16)0x7fff;
NHCONST i32  max_i32 = (i32)0x7fffffff;
NHCONST i64  max_i64 = (i64)0x7ffffffffffffffflu;
/* unsigned int max vals */
NHCONST u8   max_u8  = (u8) 0xff;
NHCONST u16  max_u16 = (u16)0xffff;
NHCONST u32  max_u32 = (u32)0xffffffff;
NHCONST u64  max_u64 = (u64)0xfffffffffffffffflu;

/* f32 consts */
NHCONST f32  m_epsilon32 = 1.1920929e-7f;
NHCONST f32  pi32    = 3.14159265359f;
NHCONST f32  e32     = 2.71828182846f;
/* f64 consts */
NHCONST f64  m_epsilon64 = 2.220446e-16;
NHCONST f64  pi64    = 3.1415965359;
NHCONST f64  e64     = 2.71828182846;

/*
 * Floating point functions:
 * -  A way to easily get inf and -inf values for floats.
 * -  Absolute value for floats, as you cannot easily use bitwise operations on
 *    floats.
 * - Linear interpolation between two numbers.
 */
/* Get infinity as an f32 */
NHAPI f32 inf_f32();
/* Get -infinity as an f32 */
NHAPI f32 neginf_f32();
/* Get infinity as an f64 */
NHAPI f64 inf_f64();
/* Get -infinity as an f64 */
NHAPI f64 neginf_f64();

/*
 * Linear interpolation between a and b, by the amount t (a float between 0 and
 * 1) 
 */
NHAPI f32 lerp_f32(f32 a, f32 b, f32 t);
/*
 * Linear interpolation between a and b, by the amount t (a float between 0 and
 * 1) 
 */
NHAPI f64 lerp_f64(f64 a, f64 b, f64 t);

/*
 * Vector functions:
 * -  Dot products of all vectors.
 * - Cross product of two 3D vectors, and the z component of an imaginary cross
 *   product between two 2D vecctors with a z added.
 * - Normalizing the float vectors (no fast inv sqrt, I'm not sure the accuracy
 *   of that is worth the faster calculation, so I am going to trust the C
 *   stdlib on this one.
 * - Scaling a vector to a particular scale.
 * - Adding two vectors
 * - Subtracting two vectors
 */
/* Dot product of two v2i32(s) */
NHAPI i32 dot_v2i32(v2i32 a, v2i32 b);
/* Dot product of two v3i32(s) */
NHAPI i32 dot_v3i32(v3i32 a, v3i32 b);
/* Dot product of two v2f32(s) */
NHAPI f32 dot_v2f32(v2f32 a, v2f32 b);
/* Dot product of two v3f32(s) */
NHAPI f32 dot_v3f32(v3f32 a, v3f32 b);

/* The z coordinate of a hypothetical cross product of a and b */
NHAPI i32 cross_v2i32(v2i32 a, v2i32 b);
/* The cross product of two v3i32(s) */
NHAPI v3i32 cross_v3i32(v3i32 a, v3i32 b);
/* The z coordinate of a hypothetical cross product of a and b */
NHAPI f32 cross_v2f32(v2f32 a, v2f32 b);
/* The cross product of two v3f32(s) */
NHAPI v3f32 cross_v3f32(v3f32 a, v3f32 b);

/* Normalize the vector v */
NHAPI v2f32 normalize_v2f32(v2f32 v);
/* Normalize the vector v */
NHAPI v3f32 normalize_v3f32(v3f32 v);

/* Scale the vector v */
NHAPI v2i32 scale_v2i32(v2i32 v, i32 scale);
/* Scale the vector v */
NHAPI v3i32 scale_v3i32(v3i32 v, i32 scale);
/* Scale the vector v */
NHAPI v2f32 scale_v2f32(v2f32 v, f32 scale);
/* Scale the vector v */
NHAPI v3f32 scale_v3f32(v3f32 v, f32 scale);

/* Add vectors a and b */
NHAPI v2i32 add_v2i32(v2i32 a, v2i32 b);
/* Add vectors a and b */
NHAPI v3i32 add_v3i32(v3i32 a, v3i32 b);
/* Add vectors a and b */
NHAPI v2f32 add_v2f32(v2f32 a, v2f32 b);
/* Add vectors a and b */
NHAPI v3f32 add_v3f32(v3f32 a, v3f32 b);

/* Subtract vectors a and b */
NHAPI v2i32 subtract_v2i32(v2i32 a, v2i32 b);
/* Subtract vectors a and b */
NHAPI v3i32 subtract_v3i32(v3i32 a, v3i32 b);
/* Subtract vectors a and b */
NHAPI v2f32 subtract_v2f32(v2f32 a, v2f32 b);
/* Subtract vectors a and b */
NHAPI v3f32 subtract_v3f32(v3f32 a, v3f32 b);

/*
 * Matrix functions
 */
/* Creates a "blank" matrix - an identity */
NHAPI m4f32 identity_m4f32();
/* Creates a translation matrx */
NHAPI m4f32 translation_m4f32(f32 x, f32 y, f32 z);
/* Creates a rotation matrix for the x axis */
NHAPI m4f32 rotationX_m4f32(f32 thetaRadians);
/* Creates a rotation matrix for the y axis */
NHAPI m4f32 rotationY_m4f32(f32 thetaRadians);
/* Creates a rotation matrix for the z axis */
NHAPI m4f32 rotationZ_m4f32(f32 thetaRadians);
/* Multiplies two mat4s, so that the result has both effects */
NHAPI m4f32 multiply_m4f32(m4f32 a, m4f32 b);
/* see glm::lookAt(), or gluLookAt(), oe */
NHAPI m4f32 lookAt_m4f32(v3f32 eye, v3f32 centre, v3f32 up);
/* Creates a perspective projection matrix */
NHAPI m4f32 perspectiveProjection_m4f32(
    f32 fovDegrees, f32 aspectRatio,
    f32 near, f32 far);

#endif /* NH_BASE_H */
