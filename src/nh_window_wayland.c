/* Implements nh_window.h */
#include "../ext/nh_window.h"

/* Wayland */
#include <wayland-client.h>
#include "xdg-shell-protocol.h"

/* stdlib headers */
#include <stdlib.h>
#include <string.h>

/* Base */
#include "../nh_base.h"
#include "../ext/nh_logging.h"

/* Window data */
typedef struct _window_state_t {
  /* Misc */
  bool running;                               /* Is the window running? */
  nh_ivec2_t size;                            /* Window size */
  /* Wayland */
  struct wl_display *display;                 /* Wayland display */
  struct wl_registry *registry;               /* Wayland registry */
  struct wl_compositor *compositor;           /* Wayland compositor */
  struct wl_surface *surface;                 /* Wayland surface */
  struct xdg_wm_base *xdg_base;               /* XDG base */
  struct xdg_surface *xdg_surface;            /* XDG surface */
  struct xdg_toplevel *xdg_toplevel;          /* XDG toplevel */
  struct wl_registry_listener registry_list;  /* LISTENER: Wayland registry */
  struct xdg_wm_base_listener xdg_base_list;  /* LISTENER: XDG base */
  struct xdg_surface_listener xdg_surf_list;  /* LISTENER: XDG surface */
  struct xdg_toplevel_listener xdg_top_list;  /* LISTENER: XDG toplevel */
} _window_state_t;

/* Callback definitions */
/* Registry - global */
static void _reg_glob(
    void *data,
    struct wl_registry *registry,
    u32 name,
    const char *interface,
    u32 version
);
/* Registry - global remove */
static void _reg_glob_rem(
    void *data,
    struct wl_registry *registry,
    u32 name
);
/* XDG base - ping */
static void _xdg_base_ping(
    void *data,
    struct xdg_wm_base *xdg_wm_base,
    u32 serial
);
/* XDG surface - configure */
static void _xdg_surf_conf(
    void *data,
    struct xdg_surface *xdg_surface,
    u32 serial
);
/* XDG toplevel - configure */
static void _xdg_top_conf(
  void *data,
  struct xdg_toplevel *xdg_toplevel,
  int32_t width,
  int32_t height,
  struct wl_array *states
);
/* XDG toplevel - close */
static void _xdg_top_close(
  void *data,
  struct xdg_toplevel *xdg_toplevel
);

/* Create a new window */
nh_window_t nh_window_create(nh_ivec2_t size, const char *title) {
  NH_INFO("Creating window:");
  NH_LOG_ENTRY("size: (%d, %d)", size.x, size.y);
  if (title) NH_LOG_ENTRY("title: %s", title);
  else NH_LOG_ENTRY("title: NULL");
  _window_state_t *state = malloc(sizeof(_window_state_t));
  NH_ASSERT(state != NH_NULL);
  /* Get display */
  state->display = wl_display_connect(NH_NULL);
  NH_ASSERT(state->display != NH_NULL);
  /* Get registry */
  state->registry = wl_display_get_registry(state->display);
  NH_ASSERT(state->registry != NH_NULL);
  /* Set registry listener */
  state->registry_list.global_remove = _reg_glob_rem;
  state->registry_list.global = _reg_glob;
  wl_registry_add_listener(state->registry, &state->registry_list, state);
  /* Dispatch display once, to get the registry */
  wl_display_dispatch(state->display);
  NH_ASSERT_MSG(state->compositor != NH_NULL, "Not found compositor interface");
  NH_ASSERT_MSG(state->xdg_base != NH_NULL, "Not found XDG base interface");
  /* Create surface */
  state->surface = wl_compositor_create_surface(state->compositor);
  NH_ASSERT(state->surface != NH_NULL);
  /* Get XDG surface */
  state->xdg_surface =
    xdg_wm_base_get_xdg_surface(state->xdg_base, state->surface);
  NH_ASSERT(state->xdg_surface != NH_NULL);
  /* Set XDG surface listener */
  state->xdg_surf_list.configure = _xdg_surf_conf;
  xdg_surface_add_listener(state->xdg_surface, &state->xdg_surf_list, state);
  /* Create XDG toplevel */
  state->xdg_toplevel = xdg_surface_get_toplevel(state->xdg_surface);
  NH_ASSERT(state->xdg_toplevel != NH_NULL);
  /* Set XDG toplevel listener */
  state->xdg_top_list.configure = _xdg_top_conf;
  state->xdg_top_list.close = _xdg_top_close;
  xdg_toplevel_add_listener(state->xdg_toplevel, &state->xdg_top_list, state);
  /* Set title */
  if (title) xdg_toplevel_set_title(state->xdg_toplevel, title);
  else xdg_toplevel_set_title(state->xdg_toplevel, "Neushoorn Window");
  /* Commit surface */
  wl_surface_commit(state->surface);
  /* Size can't be changed easily on wayland, and it doesn't make much sense to 
   * do so anyway. */
  (void)size; /* TODO: Check for !size */
  /* Set running to true */
  state->running = true;
  return state;
}
/* Destroy a window */
void nh_window_destroy(nh_window_t window) {
  NH_ASSERT_MSG(window != NH_NULL, "Can't destroy window: window is NULL");
  NH_INFO("Destroying window...");
  _window_state_t *state = (_window_state_t*)window;
  wl_surface_destroy(state->surface);
  wl_display_disconnect(state->display);
  /* TODO: Implement */
  free((_window_state_t*)window);
}

/* Set the window's title */
void nh_window_set_title(nh_window_t window, const char *title) {
  NH_ASSERT_MSG(window != NH_NULL, "Can't set title: window is NULL");
  NH_ASSERT_MSG(title != NH_NULL, "Can't set title: title is NULL");
  _window_state_t *state = (_window_state_t*)window;
  xdg_toplevel_set_title(state->xdg_toplevel, title);
}
/* Set the window's size */
void nh_window_set_size(nh_window_t window, nh_ivec2_t size) {
  NH_ASSERT_MSG(window != NH_NULL, "Can't set size: window is NULL");
  /* Can't set size on wayland */
  (void)size;
}

/* Get the window's size */
nh_ivec2_t nh_window_get_size(nh_window_t window) {
  NH_ASSERT_MSG(window != NH_NULL, "Can't get size: window is NULL");
  _window_state_t *state = (_window_state_t*)window;
  return state->size;
}

/* Check if the window is running */
bool nh_window_is_running(nh_window_t window) {
  NH_ASSERT_MSG(window != NH_NULL, "Can't check running: window is NULL");
  _window_state_t *state = (_window_state_t*)window;
  return state->running;
}

/* Update the window */
void nh_window_update(nh_window_t window) {
  NH_ASSERT_MSG(window != NH_NULL, "Can't update window: window is NULL");
  _window_state_t *state = (_window_state_t*)window;
  /* state->running = wl_display_dispatch(state->display) != -1; */
  /* wl_display_dispatch(state->display); */
  wl_display_dispatch_pending(state->display);
}

/* Some methods if Vulkan included */
#if defined(NH_WINDOW_INCLUDE_VULKAN)
/* Create a Vulkan surface for the window */
VkSurfaceKHR nh_window_create_surface(
    nh_window_t window,
    VkInstance instance
) {
  _window_state_t *state = (_window_state_t*)window;
  VkSurfaceKHR surface;
  VkWaylandSurfaceCreateInfoKHR surf_info = {
    .sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR,
    .pNext = NH_NULL,
    .flags = 0,
    .display = state->display,
    .surface = state->surface
  };
  vkCreateWaylandSurfaceKHR(
      instance,
      &surf_info,
      NH_NULL,
      &surface
  );
  return surface;
}
/* Get required instance extensions */
void nh_window_get_instance_extensions(
    nh_window_t window,
    u32 *extension_count,
    char **extensions
) {
  if (!extensions) {
    *extension_count = 2;
  }
  else {
    *extension_count = 2;
    extensions[0] = VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME;
    extensions[1] = VK_KHR_SURFACE_EXTENSION_NAME;
  }
  (void)window;
}
#endif

/* Callback declarations */
/* Registry - global */
static void _reg_glob(
    void *data,
    struct wl_registry *registry,
    u32 name,
    const char *interface,
    u32 version
) {
  _window_state_t *state = (_window_state_t*)data;
  if (strcmp(interface, wl_compositor_interface.name) == 0) {
    state->compositor = (struct wl_compositor*)wl_registry_bind(
        registry,
        name,
        &wl_compositor_interface,
        4
    );
  }
  if (strcmp(interface, xdg_wm_base_interface.name) == 0) {
    state->xdg_base = (struct xdg_wm_base*)wl_registry_bind(
        registry,
        name,
        &xdg_wm_base_interface,
        1
    );
    /* Add listener */
    state->xdg_base_list.ping = _xdg_base_ping;
    xdg_wm_base_add_listener(state->xdg_base, &state->xdg_base_list, state);
  }
  (void)registry;
  (void)name;
  (void)interface;
  (void)version;
}
/* Registry - global remove */
static void _reg_glob_rem(
    void *data,
    struct wl_registry *registry,
    u32 name
) {
  (void)data;
  (void)registry;
  (void)name;
}
/* XDG base - ping */
static void _xdg_base_ping(
    void *data,
    struct xdg_wm_base *xdg_wm_base,
    u32 serial
) {
  xdg_wm_base_pong(xdg_wm_base, serial);
  (void)data;
}
/* XDG surface - configure */
static void _xdg_surf_conf(
    void *data,
    struct xdg_surface *xdg_surface,
    u32 serial
) {
  xdg_surface_ack_configure(xdg_surface, serial);
  (void)data;
}
/* XDG toplevel - configure */
static void _xdg_top_conf(
  void *data,
  struct xdg_toplevel *xdg_toplevel,
  int32_t width,
  int32_t height,
  struct wl_array *states
) {
  _window_state_t *state = (_window_state_t*)data;
  state->size.x = width;
  state->size.y = height;
  (void)xdg_toplevel;
  (void)states;
}
/* XDG toplevel - close */
static void _xdg_top_close(
  void *data,
  struct xdg_toplevel *xdg_toplevel
) {
  _window_state_t *state = (_window_state_t*)data;
  state->running = false;
  NH_INFO("Window closed");
  (void)xdg_toplevel;
}
