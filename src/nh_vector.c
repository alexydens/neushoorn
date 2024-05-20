/* Implements nh_vector.h */
#include "../ext/nh_vector.h"

/* stdlib headers */
#include <math.h>

/* Add two nh_vec2_ts */
nh_vec2_t nh_vec2_add(nh_vec2_t a, nh_vec2_t b) {
  nh_vec2_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  return v;
}
/* Add two nh_vec3_ts */
nh_vec3_t nh_vec3_add(nh_vec3_t a, nh_vec3_t b) {
  nh_vec3_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  return v;
}
/* Add two nh_vec4_ts */
nh_vec4_t nh_vec4_add(nh_vec4_t a, nh_vec4_t b) {
  nh_vec4_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  v.w = a.w + b.w;
  return v;
}

/* Add two nh_ivec2_ts */
nh_ivec2_t nh_ivec2_add(nh_ivec2_t a, nh_ivec2_t b) {
  nh_ivec2_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  return v;
}
/* Add two nh_ivec3_ts */
nh_ivec3_t nh_ivec3_add(nh_ivec3_t a, nh_ivec3_t b) {
  nh_ivec3_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  return v;
}
/* Add two nh_ivec4_ts */
nh_ivec4_t nh_ivec4_add(nh_ivec4_t a, nh_ivec4_t b) {
  nh_ivec4_t v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  v.w = a.w + b.w;
  return v;
}

/* Add a scalar to an nh_vec2_t */
nh_vec2_t nh_vec2_add_scalar(nh_vec2_t v, f32 s) {
  nh_vec2_t v2;
  v2.x = v.x + s;
  v2.y = v.y + s;
  return v2;
}
/* Add a scalar to an nh_vec3_t */
nh_vec3_t nh_vec3_add_scalar(nh_vec3_t v, f32 s) {
  nh_vec3_t v3;
  v3.x = v.x + s;
  v3.y = v.y + s;
  v3.z = v.z + s;
  return v3;
}
/* Add a scalar to an nh_vec4_t */
nh_vec4_t nh_vec4_add_scalar(nh_vec4_t v, f32 s) {
  nh_vec4_t v4;
  v4.x = v.x + s;
  v4.y = v.y + s;
  v4.z = v.z + s;
  v4.w = v.w + s;
  return v4;
}

/* Add a scalar to an nh_ivec2_t */
nh_ivec2_t nh_ivec2_add_scalar(nh_ivec2_t v, i32 s) {
  nh_ivec2_t v2;
  v2.x = v.x + s;
  v2.y = v.y + s;
  return v2;
}
/* Add a scalar to an nh_ivec3_t */
nh_ivec3_t nh_ivec3_add_scalar(nh_ivec3_t v, i32 s) {
  nh_ivec3_t v3;
  v3.x = v.x + s;
  v3.y = v.y + s;
  v3.z = v.z + s;
  return v3;
}
/* Add a scalar to an nh_ivec4_t */
nh_ivec4_t nh_ivec4_add_scalar(nh_ivec4_t v, i32 s) {
  nh_ivec4_t v4;
  v4.x = v.x + s;
  v4.y = v.y + s;
  v4.z = v.z + s;
  v4.w = v.w + s;
  return v4;
}

/* Multiply an nh_vec2_t by a scalar */
nh_vec2_t nh_vec2_mul_scalar(nh_vec2_t v, f32 s) {
  nh_vec2_t v2;
  v2.x = v.x * s;
  v2.y = v.y * s;
  return v2;
}
/* Multiply an nh_vec3_t by a scalar */
nh_vec3_t nh_vec3_mul_scalar(nh_vec3_t v, f32 s) {
  nh_vec3_t v3;
  v3.x = v.x * s;
  v3.y = v.y * s;
  v3.z = v.z * s;
  return v3;
}
/* Multiply an nh_vec4_t by a scalar */
nh_vec4_t nh_vec4_mul_scalar(nh_vec4_t v, f32 s) {
  nh_vec4_t v4;
  v4.x = v.x * s;
  v4.y = v.y * s;
  v4.z = v.z * s;
  v4.w = v.w * s;
  return v4;
}

/* Multiply an nh_ivec2_t by a scalar */
nh_ivec2_t nh_ivec2_mul_scalar(nh_ivec2_t v, i32 s) {
  nh_ivec2_t v2;
  v2.x = v.x * s;
  v2.y = v.y * s;
  return v2;
}
/* Multiply an nh_ivec3_t by a scalar */
nh_ivec3_t nh_ivec3_mul_scalar(nh_ivec3_t v, i32 s) {
  nh_ivec3_t v3;
  v3.x = v.x * s;
  v3.y = v.y * s;
  v3.z = v.z * s;
  return v3;
}
/* Multiply an nh_ivec4_t by a scalar */
nh_ivec4_t nh_ivec4_mul_scalar(nh_ivec4_t v, i32 s) {
  nh_ivec4_t v4;
  v4.x = v.x * s;
  v4.y = v.y * s;
  v4.z = v.z * s;
  v4.w = v.w * s;
  return v4;
}

/* Dot product of two nh_vec2_ts */
f32 nh_vec2_dot(nh_vec2_t a, nh_vec2_t b) {
  return a.x * b.x + a.y * b.y;
}
/* Dot product of two nh_vec3_ts */
f32 nh_vec3_dot(nh_vec3_t a, nh_vec3_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
/* Dot product of two nh_vec4_ts */
f32 nh_vec4_dot(nh_vec4_t a, nh_vec4_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

/* Dot product of two nh_ivec2_ts */
i32 nh_ivec2_dot(nh_ivec2_t a, nh_ivec2_t b) {
  return a.x * b.x + a.y * b.y;
}
/* Dot product of two nh_ivec3_ts */
i32 nh_ivec3_dot(nh_ivec3_t a, nh_ivec3_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
/* Dot product of two nh_ivec4_ts */
i32 nh_ivec4_dot(nh_ivec4_t a, nh_ivec4_t b) {
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

/* Cross product of two nh_vec3_ts */
nh_vec3_t nh_vec3_cross(nh_vec3_t a, nh_vec3_t b) {
  nh_vec3_t v;
  v.x = a.y * b.z - a.z * b.y;
  v.y = a.z * b.x - a.x * b.z;
  v.z = a.x * b.y - a.y * b.x;
  return v;
}

/* Cross product of two nh_ivec3_ts */
nh_ivec3_t nh_ivec3_cross(nh_ivec3_t a, nh_ivec3_t b) {
  nh_ivec3_t v;
  v.x = a.y * b.z - a.z * b.y;
  v.y = a.z * b.x - a.x * b.z;
  v.z = a.x * b.y - a.y * b.x;
  return v;
}

/* Length of an nh_vec2_t */
f32 nh_vec2_length(nh_vec2_t v) {
  return sqrtf(nh_vec2_dot(v, v));
}
/* Length of an nh_vec3_t */
f32 nh_vec3_length(nh_vec3_t v) {
  return sqrtf(nh_vec3_dot(v, v));
}
/* Length of an nh_vec4_t */
f32 nh_vec4_length(nh_vec4_t v) {
  return sqrtf(nh_vec4_dot(v, v));
}

/* Length of an nh_ivec2_t */
f32 nh_ivec2_length(nh_ivec2_t v) {
  return sqrtf(nh_ivec2_dot(v, v));
}
/* Length of an nh_ivec3_t */
f32 nh_ivec3_length(nh_ivec3_t v) {
  return sqrtf(nh_ivec3_dot(v, v));
}
/* Length of an nh_ivec4_t */
f32 nh_ivec4_length(nh_ivec4_t v) {
  return sqrtf(nh_ivec4_dot(v, v));
}

/* Normalize an nh_vec2_t */
nh_vec2_t nh_vec2_normalize(nh_vec2_t v) {
  f32 l = nh_vec2_length(v);
  if (l != 0.0) {
    v.x /= l;
    v.y /= l;
  }
  return v;
}
/* Normalize an nh_vec3_t */
nh_vec3_t nh_vec3_normalize(nh_vec3_t v) {
  f32 l = nh_vec3_length(v);
  if (l != 0.0) {
    v.x /= l;
    v.y /= l;
    v.z /= l;
  }
  return v;
}
/* Normalize an nh_vec4_t */
nh_vec4_t nh_vec4_normalize(nh_vec4_t v) {
  f32 l = nh_vec4_length(v);
  if (l != 0.0) {
    v.x /= l;
    v.y /= l;
    v.z /= l;
    v.w /= l;
  }
  return v;
}

/* Linear interpolation between two nh_vec2_ts */
nh_vec2_t nh_vec2_lerp(nh_vec2_t a, nh_vec2_t b, f32 t) {
  nh_vec2_t v;
  v.x = a.x + (b.x - a.x) * t;
  v.y = a.y + (b.y - a.y) * t;
  return v;
}
/* Linear interpolation between two nh_vec3_ts */
nh_vec3_t nh_vec3_lerp(nh_vec3_t a, nh_vec3_t b, f32 t) {
  nh_vec3_t v;
  v.x = a.x + (b.x - a.x) * t;
  v.y = a.y + (b.y - a.y) * t;
  v.z = a.z + (b.z - a.z) * t;
  return v;
}
/* Linear interpolation between two nh_vec4_ts */
nh_vec4_t nh_vec4_lerp(nh_vec4_t a, nh_vec4_t b, f32 t) {
  nh_vec4_t v;
  v.x = a.x + (b.x - a.x) * t;
  v.y = a.y + (b.y - a.y) * t;
  v.z = a.z + (b.z - a.z) * t;
  v.w = a.w + (b.w - a.w) * t;
  return v;
}

