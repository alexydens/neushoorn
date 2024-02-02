#include "test.h"

i32 main() {
  test_base();
  test_arena_alloc();
  test_chunk_alloc();

  test_logging(); /* Testing fatal involves a crash, so needs to come last */
  return 0;
}
