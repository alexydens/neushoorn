/* Get an implementation of nh_window.h */
#include "../ext/nh_window.h"

/* Pick source file */
#if defined(NH_WINDOW_WIN32)
#include "nh_window_win32.c"
#elif defined(NH_WINDOW_WAYLAND)
#include "nh_window_wayland.c"
#elif defined(NH_WINDOW_X11)
#include "nh_window_x11.c"
#endif
