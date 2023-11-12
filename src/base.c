#include "base.h"

/* C stdlib dependencies */
#include <math.h>
#include <string.h>

f32 inf_f32() {
  return 1.0f / 0.0f;
}
f32 neginf_f32() {
  return -1.0f / 0.0f;
}
f64 inf_f64() {
  return 1.0 / 0.0;
}
f64 neginf_f64() {
  return -1.0 / 0.0;
}

f32 lerp_f32(f32 a, f32 b, f32 t) {
  f32 a_, b_;
  a_ = MIN(a, b);
  b_ = MAX(a, b);
  return a_ + (t * (b_-a_));
}
f64 lerp_f64(f64 a, f64 b, f64 t) {
  f64 a_, b_;
  a_ = MIN(a, b);
  b_ = MAX(a, b);
  return a_ + (t * (b_-a_));
}

i32 dot_v2i32(v2i32 a, v2i32 b) {
  return (a.x*b.x)+(a.y*b.y);
}
i32 dot_v3i32(v3i32 a, v3i32 b) {
  return (a.x*b.x)+(a.y*b.y)+(a.z*b.z);
}
f32 dot_v2f32(v2f32 a, v2f32 b) {
  return (a.x*b.x)+(a.y*b.y);
}
f32 dot_v3f32(v3f32 a, v3f32 b) {
  return (a.x*b.x)+(a.y*b.y)+(a.z*b.z);
}

i32 cross_v2i32(v2i32 a, v2i32 b) {
  return (a.x * b.y) - (a.y * b.x);
}
v3i32 cross_v3i32(v3i32 a, v3i32 b) {
  v3i32 res;
  res.x = a.y*b.z - a.z*b.y;
  res.y = a.z*b.x - a.x*b.z;
  res.z = a.x*b.y - a.y*b.x;
  return res;
}
f32 cross_v2f32(v2f32 a, v2f32 b) {
  return (a.x * b.y) - (a.y * b.x);
}
v3f32 cross_v3f32(v3f32 a, v3f32 b) {
  v3f32 res;
  res.x = a.y*b.z - a.z*b.y;
  res.y = a.z*b.x - a.x*b.z;
  res.z = a.x*b.y - a.y*b.x;
  return res;
}

v2f32 normalize_v2f32(v2f32 v) {
  v2f32 res;
  f32 divideBy = sqrt(v.x * v.x + v.y * v.y);
  res.x = v.x / divideBy;
  res.y = v.y / divideBy;
  return res;
}
v3f32 normalize_v3f32(v3f32 v) {
  v3f32 res;
  f32 divideBy = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  res.x = v.x / divideBy;
  res.y = v.y / divideBy;
  res.z = v.z / divideBy;
  return res;
}

v2i32 scale_v2i32(v2i32 v, i32 scale) {
  v2i32 res;
  res.x = v.x * scale;
  res.y = v.y * scale;
  return res;
}
v3i32 scale_v3i32(v3i32 v, i32 scale) {
  v3i32 res;
  res.x = v.x * scale;
  res.y = v.y * scale;
  res.z = v.y * scale;
  return res;
}
v2f32 scale_v2f32(v2f32 v, f32 scale) {
  v2f32 res;
  res.x = v.x * scale;
  res.y = v.y * scale;
  return res;
}
v3f32 scale_v3f32(v3f32 v, f32 scale) {
  v3f32 res;
  res.x = v.x * scale;
  res.y = v.y * scale;
  res.z = v.y * scale;
  return res;
}

v2i32 add_v2i32(v2i32 a, v2i32 b) {
  v2i32 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  return res;
}
v3i32 add_v3i32(v3i32 a, v3i32 b) {
  v3i32 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  res.z = a.z + b.z;
  return res;
}
v2f32 add_v2f32(v2f32 a, v2f32 b) {
  v2f32 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  return res;
}
v3f32 add_v3f32(v3f32 a, v3f32 b) {
  v3f32 res;
  res.x = a.x + b.x;
  res.y = a.y + b.y;
  res.z = a.z + b.z;
  return res;
}

v2i32 subtract_v2i32(v2i32 a, v2i32 b) {
  v2i32 res;
  res.x = a.x - b.x;
  res.y = a.y - b.y;
  return res;
}
v3i32 subtract_v3i32(v3i32 a, v3i32 b) {
  v3i32 res;
  res.x = a.x - b.x;
  res.y = a.y - b.y;
  res.z = a.z - b.z;
  return res;
}
v2f32 subtract_v2f32(v2f32 a, v2f32 b) {
  v2f32 res;
  res.x = a.x - b.x;
  res.y = a.y - b.y;
  return res;
}
v3f32 subtract_v3f32(v3f32 a, v3f32 b) {
  v3f32 res;
  res.x = a.x - b.x;
  res.y = a.y - b.y;
  res.z = a.z - b.z;
  return res;
}

m4f32 identity_m4f32() {
  m4f32 res;

  memset(res.vals, 0, 16 * sizeof(f32)); /* 16 * 32, one would assume */
  res.vals[0] = 1;
  res.vals[5] = 1;
  res.vals[10] = 1;
  res.vals[15] = 1;

  return res;
}
m4f32 translation_m4f32(f32 x, f32 y, f32 z) {
  m4f32 res = identity_m4f32();

  res.vals[12] = x;
  res.vals[13] = y;
  res.vals[14] = z;

  return res;
}
m4f32 rotationX_m4f32(f32 thetaRadians) {
  m4f32 res = identity_m4f32();
  res.vals[5] = cos((f64)thetaRadians);
  res.vals[6] = sin((f64)thetaRadians);
  res.vals[9] = -sin((f64)thetaRadians);
  res.vals[10] = cos((f64)thetaRadians);
  return res;
}
m4f32 rotationY_m4f32(f32 thetaRadians) {
  m4f32 res = identity_m4f32();
  res.vals[0] = cos((f64)thetaRadians);
  res.vals[2] = -sin((f64)thetaRadians);
  res.vals[8] = sin((f64)thetaRadians);
  res.vals[10] = cos((f64)thetaRadians);
  return res;
}
m4f32 rotationZ_m4f32(f32 thetaRadians) {
  m4f32 res = identity_m4f32();
  res.vals[0] = cos((f64)thetaRadians);
  res.vals[1] = sin((f64)thetaRadians);
  res.vals[4] = -sin((f64)thetaRadians);
  res.vals[5] = cos((f64)thetaRadians);
  return res;
}
m4f32 multiply_m4f32(m4f32 a, m4f32 b) {
  m4f32 res;

  f32* mat = res.vals;
  f32* m1 = a.vals;
  f32* m2 = b.vals;

  mat[0] = m1[0] * m2[0] + m1[4] * m2[1] + m1[8] * m2[2] + m1[12] * m2[3];
	mat[1] = m1[1] * m2[0] + m1[5] * m2[1] + m1[9] * m2[2] + m1[13] * m2[3];
	mat[2] = m1[2] * m2[0] + m1[6] * m2[1] + m1[10] * m2[2] + m1[14] * m2[3];
	mat[3] = m1[3] * m2[0] + m1[7] * m2[1] + m1[11] * m2[2] + m1[15] * m2[3];

	mat[4] = m1[0] * m2[4] + m1[4] * m2[5] + m1[8] * m2[6] + m1[12] * m2[7];
	mat[5] = m1[1] * m2[4] + m1[5] * m2[5] + m1[9] * m2[6] + m1[13] * m2[7];
	mat[6] = m1[2] * m2[4] + m1[6] * m2[5] + m1[10] * m2[6] + m1[14] * m2[7];
	mat[7] = m1[3] * m2[4] + m1[7] * m2[5] + m1[11] * m2[6] + m1[15] * m2[7];

	mat[8] = m1[0] * m2[8] + m1[4] * m2[9] + m1[8] * m2[10] + m1[12] * m2[11];
	mat[9] = m1[1] * m2[8] + m1[5] * m2[9] + m1[9] * m2[10] + m1[13] * m2[11];
	mat[10] = m1[2] * m2[8] + m1[6] * m2[9] + m1[10] * m2[10] + m1[14] * m2[11];
	mat[11] = m1[3] * m2[8] + m1[7] * m2[9] + m1[11] * m2[10] + m1[15] * m2[11];

	mat[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8] * m2[14] + m1[12] * m2[15];
	mat[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9] * m2[14] + m1[13] * m2[15];
	mat[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];
	mat[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];

  return res;
}
m4f32 lookAt_m4f32(v3f32 eye, v3f32 centre, v3f32 up) {
  v3f32 f, s, u;
  m4f32 res = identity_m4f32();
  f = subtract_v3f32(centre, eye);
  f = normalize_v3f32(f);

  s = cross_v3f32(f, up);
  s = normalize_v3f32(s);

  u = cross_v3f32(f, s);

  res.vals[0] = s.x;
  res.vals[1] = u.x;
  res.vals[2] = -f.x;

  res.vals[4] = s.y;
  res.vals[5] = u.y;
  res.vals[6] = -f.y;

  res.vals[8] = s.z;
  res.vals[9] = u.z;
  res.vals[10] = -f.z;

  res.vals[12] = -dot_v3f32(s, eye);
  res.vals[13] = -dot_v3f32(u, eye);
  res.vals[14] = dot_v3f32(f, eye);

  return res;
}
m4f32 perspectiveProjection_m4f32(
    f32 fovDegrees, f32 aspectRatio,
    f32 near, f32 far) {
  m4f32 res = identity_m4f32();

  f32 r = (fovDegrees/2) * (pi32/180);
  f32 deltaZ = near - far;
  f32 s = sin((f64)r);
  f32 cotangent = 0;

  if (deltaZ == 0 || s == 0 || aspectRatio == 0) {
		return res;
	}
  
  cotangent = cos(r) / s;

  res.vals[0] = cotangent / aspectRatio;
  res.vals[5] = cotangent;
  res.vals[10] = (far+near) / deltaZ;
  res.vals[11] = -1;
  res.vals[14] = (2 * far * near) / deltaZ;
  res.vals[15] = 0;

  return res;
}
