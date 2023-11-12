/* Include guard */
#if !defined(NH_ARENA_ALLOC_H)
#define NH_ARENA_ALLOC_H

/* Base library */
#include "base.h"

/* Arena struct */
typedef struct {
  char* start;
  char* pos;
  u64 size;
} Arena;

/* Create a linear allocator of size size */
NHAPI Arena create_arena(u64 size);
/* Allocate size bytes on the arena */
NHAPI void* arena_alloc(Arena* arena, u64 size);
/* Free the whole arena */
NHAPI void arena_free(Arena* arena);

#endif /* NH_ARENA_ALLOC_H */
