/* Base */
#include "../nh_base.h"
/* Other headers */
#include "../ext/nh_logging.h"
#include "../ext/nh_window.h"

/* Entry point */
int main(void) {
  /* Create window */
  nh_window_t window = nh_window_create((nh_ivec2_t){ 1280, 720 }, "Test");
  /* Main loop */
  while (nh_window_is_running(window)) {
    /* Update window */
    nh_window_update(window);
  }
  /* Destroy window */
  nh_window_destroy(window);
  return 0;
}
