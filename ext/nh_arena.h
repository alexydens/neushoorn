/* Include guard */
#if !defined(NH_ARENA_H)
#define NH_ARENA_H

/* Base */
#include "../nh_base.h"

/* Arena allocator type */
typedef struct nh_arena_t {
  u8 *start;
  u8 *current;
  u32 size;
  bool allocated;
} nh_arena_t;

/* Create an arena of size bytes. If start is NULL, malloc() will be used */
extern nh_arena_t nh_arena_create(u32 size, u8 *start);
/* Free all of an arena's memory */
extern void nh_arena_free(nh_arena_t *arena);
/* Allocate size bytes from an arena */
extern void *nh_arena_alloc(nh_arena_t *arena, u32 size);

#endif /* NH_ARENA_H */
