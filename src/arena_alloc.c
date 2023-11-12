#include "arena_alloc.h"

/* C stdlib dependencies */
#include <stdlib.h>

Arena create_arena(u64 size) {
  Arena arena;
  arena.start = malloc(size);
  arena.size = size;
  arena.pos = arena.start;
  return arena;
}
void* arena_alloc(Arena* arena, u64 size) {
  arena->pos += size;
  ASSERT(arena->pos <= arena->start + arena->size);
  return arena->pos - size;
}
void arena_free(Arena* arena) {
  free(arena->start);
  arena->start = NULL;
}
