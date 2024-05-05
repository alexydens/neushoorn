# Neushoorn
## Neushoorn, a collection of headers in C11.
### Types
- `u8` - unsigned integer (8 bits).
- `u16` - unsigned integer (16 bits).
- `u32` - unsigned integer (32 bits).
- `u64` - unsigned integer (64 bits).

- `i8` - signed integer (8 bits).
- `i16` - signed integer (16 bits).
- `i32` - signed integer (32 bits).
- `i64` - signed integer (64 bits).

- `f32` - floating point (32 bits).
- `f64` - floating point (64 bits).

- `bool` - boolean.

- `nh_weekday_t` - day of the week (enum).
- `nh_month_t` - month (enum).

- `nh_time_t` - time (struct).
- `nh_date_t` - date (struct).

- `nh_vec2_t` - 2D vector (`f32`, struct).
- `nh_vec3_t` - 3D vector (`f32`, struct).
- `nh_vec4_t` - 4D vector (`f32`, struct).

- `nh_ivec2_t` - 2D vector (`i32`, struct).
- `nh_ivec3_t` - 3D vector (`i32`, struct).
- `nh_ivec4_t` - 4D vector (`i32`, struct).

- `nh_mat4_t` - 4x4 matrix (`f32`, struct).
### Constants
#### Mathematical constants
- `NH_PI` - 3.14159265358979323846.
- `NH_E` - 2.71828182845904523536.
#### Size Prefixes
- `NH_KB` - 1024.
- `NH_MB` - 1024 * 1024.
- `NH_GB` - 1024 * 1024 * 1024.
- `NH_TB` - 1024 * 1024 * 1024 * 1024.
#### Minimums and Maximums
- `NH_MIN_I8` - -128.
- `NH_MIN_I16` - -32768.
- `NH_MIN_I32` - -2147483648.
- `NH_MIN_I64` - -9223372036854775808.
- `NH_MAX_I8` - 127.
- `NH_MAX_I16` - 32767.
- `NH_MAX_I32` - 2147483647.
- `NH_MAX_I64` - 9223372036854775807.
- `NH_MAX_U8` - 255.
- `NH_MAX_U16` - 65535.
- `NH_MAX_U32` - 4294967295.
- `NH_MAX_U64` - 18446744073709551615.
#### Infinity and NaN
- `NH_NAN` - Not a Number (in C as `(0.0 / 0.0)`).
- `NH_INFINITE` - Infinity (in C as `(1.0 / 0.0)`).
#### Misc
- `NH_NULL` - Null pointer.
- `NH_LOREM` - A sentence of lorem ipsum.
### Macros
- `NH_DEGTORAD` - Convert degrees to radians.
- `NH_RADTODEG` - Convert radians to degrees.
- `NH_ARRLEN` - Length of an array.
- `NH_INDEX_XY` - Index an array using X and Y coordinates.
- `NH_MIN` - Minimum of two values.
- `NH_MAX` - Maximum of two values.
- `NH_SWAP` - Swap two values.
- `NH_CLAMP` - Clamp a value between two values.
- `NH_ABS` - Absolute value of an integer.
- `NH_LERP` - Linear interpolation.
