/* Include guard */
#if !defined(NH_MACROS_H)
#define NH_MACROS_H

/* Macro to convert degrees to radians */
#define NH_DEGTORAD(x)        ((x) * NH_PI / 180.0f)
/* Macro to convert radians to degrees */
#define NH_RADTODEG(x)        ((x) * 180.0f / NH_PI)

/* Macro to get the number of elements in an array */
#define NH_ARRLEN(x)          (sizeof(x) / sizeof(x[0]))
/* Macro to get an index of an array from an x and a y */
#define NH_INDEX_XY(x, y, w)  ((y) * (w) + (x))

/* Macro to get the minimum of two values */
#define NH_MIN(x, y)          ((x) < (y) ? (x) : (y))
/* Macro to get the maximum of two values */
#define NH_MAX(x, y)          ((x) > (y) ? (x) : (y))

/* Macro to swap two values */
#define NH_SWAP(x, y)         do {\
    __typeof(x) _tmp = (x);       \
    (x) = (y);                    \
    (y) = _tmp;                   \
  } while (0)

/* Macro to clamp a value between two bounds */
#define NH_CLAMP(x, min, max) ((x) < (min) ?\
    (min) : ((x) > (max) ? (max) : (x)))
/* Macro to get the absolute value of a number */
#define NH_ABS(x)             ((x) < 0 ? -(x) : (x))
/* Macro to perform linear interpolation between two values */
#define NH_LERP(x, y, t)      ((x) + ((y) - (x)) * (t))

#endif /* NH_MACROS_H */
