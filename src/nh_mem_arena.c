#include <nh_mem_arena.h>

/* C Stdlib Depenedencies */
#include <stdlib.h>

arena_alloc_t create_arena(u64 size) {
  arena_alloc_t arena;

  /* Populate fields */
  arena.start = malloc(size); /* Allocated actual memory */ 
  arena.pos = arena.start;    /* Make sure pos is in the right place to start */
  arena.size = size;          /* Set directly from param */

  return arena;
}
void arena_free(arena_alloc_t* arena) {
  /* Free from malloc() */
  free(arena->start);
  /* Reset all fields */
  arena->start = NULL;
  arena->pos = NULL;
  arena->size = 0;
}

/* Allocate size bytes on the arena */
u8* arena_alloc(arena_alloc_t* arena, u64 size) {
  /* Check in range */
  ASSERT((u8*)(arena->pos + size) <= (u8*)(arena->start + arena->size));
  /* If so, increment pos by size */
  arena->pos += size;
  /* Return old pos */
  return arena->pos - size;
}
