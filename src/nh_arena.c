/* Implements nh_arena.h */
#include "../ext/nh_arena.h"

/* stdlib headers */
#include <stdlib.h>

/* Create an arena of size bytes. If start is NULL, malloc() will be used */
nh_arena_t nh_arena_create(u32 size, u8 *start) {
  nh_arena_t arena;
  arena.start = start == NH_NULL ? malloc(size) : start;
  arena.current = arena.start;
  arena.size = size;
  arena.allocated = (start == NH_NULL);
  return arena;
}
/* Free all of an arena's memory */
void nh_arena_free(nh_arena_t *arena) {
  if (arena->allocated)
    free(arena->start);
  arena->start = NH_NULL;
  arena->current = NH_NULL;
  arena->size = 0;
  arena->allocated = false;
}
/* Allocate size bytes from an arena */
void *nh_arena_alloc(nh_arena_t *arena, u32 size) {
  if (arena->current + size > arena->start + arena->size) {
    return NH_NULL;
  }
  void *ptr = arena->current;
  arena->current += size;
  return ptr;
}
