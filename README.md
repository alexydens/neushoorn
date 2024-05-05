# Neushoorn
## Neushoorn, a collection of headers in C11.
### File structure
- `nh_XXX.h` - Header file, nostdlib, C11 (in theory).
- `ext`:
    - `nh_XXX.h` - Header file, requires the library to be built.
- `src`:
    - `nh_XXX.c` - Implementation of header in `ext`.
- `build`:
    - `nh_XXX.o` - Object file, compiler implementation of header in `ext`.
    - `libneushoorn.a` - Static library, contains all `nh_XXX.o`s.
- `Makefile` - Contains rule `build` to build the library, and `clean` to clear
the build directory.
### Library Dependencies:
- Nothing difficult at the moment, just stdlib, and `-lm`.
### Types
#### Unsigned Integers
- `u8` - unsigned integer (8 bits).
- `u16` - unsigned integer (16 bits).
- `u32` - unsigned integer (32 bits).
- `u64` - unsigned integer (64 bits).
#### Signed Integers
- `i8` - signed integer (8 bits).
- `i16` - signed integer (16 bits).
- `i32` - signed integer (32 bits).
- `i64` - signed integer (64 bits).
#### Floating Point Numbers
- `f32` - floating point (32 bits).
- `f64` - floating point (64 bits).
#### Booleans
- `bool` - boolean.
#### Enumerations
- `nh_weekday_t` - day of the week (enum).
- `nh_month_t` - month (enum).
#### Structs - Misc
- `nh_time_t` - time (struct).
- `nh_date_t` - date (struct).
#### Structs - Vectors (f32)
- `nh_vec2_t` - 2D vector (`f32`, struct).
- `nh_vec3_t` - 3D vector (`f32`, struct).
- `nh_vec4_t` - 4D vector (`f32`, struct).
#### Structs - Vectors (i32)
- `nh_ivec2_t` - 2D vector (`i32`, struct).
- `nh_ivec3_t` - 3D vector (`i32`, struct).
- `nh_ivec4_t` - 4D vector (`i32`, struct).
#### Structs - Matrices (f32)
- `nh_mat4_t` - 4x4 matrix (`f32`, struct).
### Constants
#### Mathematical Constants
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
- `NH_DEGTORAD(x)` - Convert degrees to radians.
- `NH_RADTODEG(x)` - Convert radians to degrees.
- `NH_ARRLEN(x)` - Length of an array.
- `NH_INDEX_XY(x, y, w)` - Index an array using X and Y coordinates.
- `NH_MIN(x, y)` - Minimum of two values.
- `NH_MAX(x, y)` - Maximum of two values.
- `NH_SWAP(x, y)` - Swap two values.
- `NH_CLAMP(x, min, max)` - Clamp a value between two values.
- `NH_ABS(x)` - Absolute value of an integer.
- `NH_LERP(x, y, t)` - Linear interpolation.
### Logging
- `NH_INFO(fmt, ...)` - Log some information.
- `NH_WARN(fmt, ...)` - Log a warning.
- `NH_ERROR(fmt, ...)` - Log an error.
- `NH_FATAL(fmt, ...)` - Log a fatal error and exit.
- `NH_LOG_ENTRY(fmt, ...)` - Log an entry in a bulleted list (or rather the
following: `  ->`).
- `BOOLSTR_COL(x)` - Convert a boolean to a string and color it (ANSI escape).
##
`#if defined(DEBUG)`
##
- `NH_ASSERT(x)` - Assert a condition.
- `NH_ASSERT_MSG(x, msg)` - Assert a condition and log a message (on fail).
##
`#endif /* DEBUG */`
##
