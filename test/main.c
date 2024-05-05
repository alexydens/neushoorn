/* Base */
#include "../nh_base.h"
/* Other headers */
#include "../ext/nh_logging.h"
#include "../ext/nh_arena.h"

/* Entry point */
int main(void) {
  nh_arena_t arena = nh_arena_create(3 * sizeof(i32), 0);
  i32 *a = nh_arena_alloc(&arena, 2 * sizeof(i32));
  i32 *b = nh_arena_alloc(&arena, 1 * sizeof(i32));
  NH_INFO("a:");
  NH_LOG_ENTRY("0: %d", a[0]);
  NH_LOG_ENTRY("1: %d", a[1]);
  NH_INFO("b:");
  NH_LOG_ENTRY("0: %d", b[0]);
  nh_arena_free(&arena);
  return 0;
}
