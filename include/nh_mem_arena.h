/* Inclue guard */
#if !defined (NH_MEM_ARENA_H)
#define NH_MEM_ARENA_H

/* Base library */
#include "nh_base.h"

/* Arena allocator struct */
typedef struct {
  u8* start;
  u8* pos;
  u64 size;
} arena_alloc_t;

/* Create an arena of size bytes */
extern arena_alloc_t create_arena(u64 size);
/* Free the full arena */
extern void arena_free(arena_alloc_t* arena);

/* Allocate size bytes on the arena */
extern u8* arena_alloc(arena_alloc_t* arena, u64 size);

#endif /* NH_MEM_ARENA_H */
