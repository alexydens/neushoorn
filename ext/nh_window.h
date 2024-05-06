/* Include guard */
#if !defined(NH_WINDOW_H)
#define NH_WINDOW_H

/* Base */
#include "../nh_base.h"

/* Find out which platform to use */
#if __has_include("windows.h")          /* If on windows, use windows */
#define NH_WINDOW_WIN32
#elif __has_include("wayland-client.h") /* Otherwise, check for wayland */
#define NH_WINDOW_WAYLAND
#elif __has_include("X11/Xlib.h")       /* If not supported, use X11 */
#define NH_WINDOW_X11
#else                                   /* None: Display error, don't compile */
#error "Can't find windowing system!"
#endif

/* If told to, include Vulkan */
#if defined(NH_WINDOW_INCLUDE_VULKAN)
#include <vulkan/vulkan.h>
#if defined(NH_WINDOW_WIN32)
#include <vulkan/vulkan_win32.h>
#elif defined(NH_WINDOW_WAYLAND)
#include <vulkan/vulkan_wayland.h>
#elif defined(NH_WINDOW_X11)
#include <vulkan/vulkan_xlib.h>
#else
#error "Something went wrong!"
#endif
#endif

/* A window handle */
typedef void *nh_window_t;

/* Create a new window */
extern nh_window_t nh_window_create(nh_ivec2_t size, const char *title);
/* Destroy a window */
extern void nh_window_destroy(nh_window_t window);

/* Set the window's title */
extern void nh_window_set_title(nh_window_t window, const char *title);
/* Set the window's size */
extern void nh_window_set_size(nh_window_t window, nh_ivec2_t size);

/* Get the window's size */
extern nh_ivec2_t nh_window_get_size(nh_window_t window);
/* Check if the window is running */
extern bool nh_window_is_running(nh_window_t window);

/* Update the window */
extern void nh_window_update(nh_window_t window);

/* Some methods if Vulkan included */
#if defined(NH_WINDOW_INCLUDE_VULKAN)
/* Create a Vulkan surface for the window */
extern VkSurfaceKHR nh_window_create_surface(
    nh_window_t window,
    VkInstance instance
);
/* Get required instance extensions */
extern void nh_window_get_instance_extensions(
    nh_window_t window,
    u32 *extension_count,
    char **extensions
);
#endif


#endif /* NH_WINDOW_H */
