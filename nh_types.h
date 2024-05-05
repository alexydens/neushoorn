/* Include guard */
#if !defined(NH_TYPES_H)
#define NH_TYPES_H

/* BASIC TYPES */
/* Unsigned integers */
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
/* Signed integers */
typedef signed char         i8;
typedef signed short        i16;
typedef signed int          i32;
typedef signed long long    i64;
/* Floats */
typedef float               f32;
typedef double              f64;
/* Booleans */
typedef _Bool               bool;
enum { false = 0, true = 1 };
/* ENUMERATIONS */
/* Day of the week */
typedef enum nh_weekday_t {
  MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
} nh_weekday_t;
/* Month of the year */
typedef enum nh_month_t {
  JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER,
  NOVEMBER, DECEMBER
} nh_month_t;
/* STRUCTS */
/* Vector (2D, floats) */
typedef struct nh_vec2_t {
  f32 x;
  f32 y;
} nh_vec2_t;
/* Vector (3D, floats) */
typedef struct nh_vec3_t {
  f32 x;
  f32 y;
  f32 z;
} nh_vec3_t;
/* Vector (4D, floats) */
typedef struct nh_vec4_t {
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} nh_vec4_t;
/* Vector (2D, ints) */
typedef struct nh_ivec2_t {
  i32 x;
  i32 y;
} nh_ivec2_t;
/* Vector (3D, ints) */
typedef struct nh_ivec3_t {
  i32 x;
  i32 y;
  i32 z;
} nh_ivec3_t;
/* Vector (4D, ints) */
typedef struct nh_ivec4_t {
  i32 x;
  i32 y;
  i32 z;
  i32 w;
} nh_ivec4_t;
/*
 * 4x4 matrix:
 *  0  4  8 12
 *  1  5  9 13
 *  2  6 10 14
 *  3  7 11 15
 */
typedef struct nh_mat4_t {
  f32 m[16];
} nh_mat4_t;

#endif /* NH_TYPES_H */
