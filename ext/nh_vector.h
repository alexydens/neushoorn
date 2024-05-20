/* Include guard */
#if !defined(NH_VECTOR_H)
#define NH_VECTOR_H

/* Base */
#include "../nh_base.h"

/* Add two nh_vec2_ts */
extern nh_vec2_t nh_vec2_add(nh_vec2_t a, nh_vec2_t b);
/* Add two nh_vec3_ts */
extern nh_vec3_t nh_vec3_add(nh_vec3_t a, nh_vec3_t b);
/* Add two nh_vec4_ts */
extern nh_vec4_t nh_vec4_add(nh_vec4_t a, nh_vec4_t b);

/* Add two nh_ivec2_ts */
extern nh_ivec2_t nh_ivec2_add(nh_ivec2_t a, nh_ivec2_t b);
/* Add two nh_ivec3_ts */
extern nh_ivec3_t nh_ivec3_add(nh_ivec3_t a, nh_ivec3_t b);
/* Add two nh_ivec4_ts */
extern nh_ivec4_t nh_ivec4_add(nh_ivec4_t a, nh_ivec4_t b);

/* Add a scalar to an nh_vec2_t */
extern nh_vec2_t nh_vec2_add_scalar(nh_vec2_t v, f32 s);
/* Add a scalar to an nh_vec3_t */
extern nh_vec3_t nh_vec3_add_scalar(nh_vec3_t v, f32 s);
/* Add a scalar to an nh_vec4_t */
extern nh_vec4_t nh_vec4_add_scalar(nh_vec4_t v, f32 s);

/* Add a scalar to an nh_ivec2_t */
extern nh_ivec2_t nh_ivec2_add_scalar(nh_ivec2_t v, i32 s);
/* Add a scalar to an nh_ivec3_t */
extern nh_ivec3_t nh_ivec3_add_scalar(nh_ivec3_t v, i32 s);
/* Add a scalar to an nh_ivec4_t */
extern nh_ivec4_t nh_ivec4_add_scalar(nh_ivec4_t v, i32 s);

/* Multiply an nh_vec2_t by a scalar */
extern nh_vec2_t nh_vec2_mul_scalar(nh_vec2_t v, f32 s);
/* Multiply an nh_vec3_t by a scalar */
extern nh_vec3_t nh_vec3_mul_scalar(nh_vec3_t v, f32 s);
/* Multiply an nh_vec4_t by a scalar */
extern nh_vec4_t nh_vec4_mul_scalar(nh_vec4_t v, f32 s);

/* Multiply an nh_ivec2_t by a scalar */
extern nh_ivec2_t nh_ivec2_mul_scalar(nh_ivec2_t v, i32 s);
/* Multiply an nh_ivec3_t by a scalar */
extern nh_ivec3_t nh_ivec3_mul_scalar(nh_ivec3_t v, i32 s);
/* Multiply an nh_ivec4_t by a scalar */
extern nh_ivec4_t nh_ivec4_mul_scalar(nh_ivec4_t v, i32 s);

/* Dot product of two nh_vec2_ts */
extern f32 nh_vec2_dot(nh_vec2_t a, nh_vec2_t b);
/* Dot product of two nh_vec3_ts */
extern f32 nh_vec3_dot(nh_vec3_t a, nh_vec3_t b);
/* Dot product of two nh_vec4_ts */
extern f32 nh_vec4_dot(nh_vec4_t a, nh_vec4_t b);

/* Dot product of two nh_ivec2_ts */
extern i32 nh_ivec2_dot(nh_ivec2_t a, nh_ivec2_t b);
/* Dot product of two nh_ivec3_ts */
extern i32 nh_ivec3_dot(nh_ivec3_t a, nh_ivec3_t b);
/* Dot product of two nh_ivec4_ts */
extern i32 nh_ivec4_dot(nh_ivec4_t a, nh_ivec4_t b);

/* Cross product of two nh_vec3_ts */
extern nh_vec3_t nh_vec3_cross(nh_vec3_t a, nh_vec3_t b);

/* Cross product of two nh_ivec3_ts */
extern nh_ivec3_t nh_ivec3_cross(nh_ivec3_t a, nh_ivec3_t b);

/* Length of an nh_vec2_t */
extern f32 nh_vec2_length(nh_vec2_t v);
/* Length of an nh_vec3_t */
extern f32 nh_vec3_length(nh_vec3_t v);
/* Length of an nh_vec4_t */
extern f32 nh_vec4_length(nh_vec4_t v);

/* Length of an nh_ivec2_t */
extern f32 nh_ivec2_length(nh_ivec2_t v);
/* Length of an nh_ivec3_t */
extern f32 nh_ivec3_length(nh_ivec3_t v);
/* Length of an nh_ivec4_t */
extern f32 nh_ivec4_length(nh_ivec4_t v);

/* Normalize an nh_vec2_t */
extern nh_vec2_t nh_vec2_normalize(nh_vec2_t v);
/* Normalize an nh_vec3_t */
extern nh_vec3_t nh_vec3_normalize(nh_vec3_t v);
/* Normalize an nh_vec4_t */
extern nh_vec4_t nh_vec4_normalize(nh_vec4_t v);

/* Linear interpolation between two nh_vec2_ts */
extern nh_vec2_t nh_vec2_lerp(nh_vec2_t a, nh_vec2_t b, f32 t);
/* Linear interpolation between two nh_vec3_ts */
extern nh_vec3_t nh_vec3_lerp(nh_vec3_t a, nh_vec3_t b, f32 t);
/* Linear interpolation between two nh_vec4_ts */
extern nh_vec4_t nh_vec4_lerp(nh_vec4_t a, nh_vec4_t b, f32 t);

#endif /* NH_VECTOR_H */
