/* Include guard */
#if !defined (NH_MEM_ALLOC_H)
#define NH_MEM_ALLOC_H

/* Base library */
#include "nh_base.h"

/* Alloc 1 - from C Stdlib */
#include <stdlib.h>
/* Alloc 2 - from arena allocator */
#include "nh_mem_arena.h"
/* Alloc 3 - from chunk allocator */
#include "nh_mem_chunk.h"

/* Allocation type enumeration */
typedef enum {
  CSTD_ALLOC,             /* malloc() and free() */
#if defined(__cplusplus)
  CPPSTD_ALLOC,           /* Cpp's 'new type[num]' and 'delete'/'delete[]' */
#endif
  ARENA_ALLOC,            /* Arena allocator */
  CHUNK_ALLOC,            /* Chunk allocator */
} nh_alloc_type;

typedef struct {
  nh_alloc_type allocType;
  union {
    /* None needed for CSTD_ALLOC */
#if defined(__cplusplus)
    /* None needed for CPPSTD_ALLOC*/
#endif
    arena_alloc_t* arena;  /* For arena allocator */
    chunk_alloc_t* chunk;  /* For chunk allocator */
  } allocator;
} allocator_t;

#endif /* NH_MEM_ALLOC_H */
