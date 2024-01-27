#include <nh_base.h>
#include <nh_mem_arena.h>

#include <stdio.h>

i32 main() {
  ArenaAllocator arena;
  u8* a;
  arena = create_arena(0xffff);
  a = arena_alloc(&arena, 0x10000);
  arena_free(&arena);
  return 0;
}
