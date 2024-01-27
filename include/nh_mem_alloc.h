/* Include guard */
#if !defined (NH_MEM_ALLOC_H)
#define NH_MEM_ALLOC_H

/* Base library */
#include "nh_base.h"

/* Alloc 1 - from C Stdlib */
#include <stdlib.h>
/* Alloc 2 - from arena allocator */
#include "nh_mem_arena.h"

/* Allocation type enumeration */
typedef enum {
  CSTD_ALLOC,             /* malloc() and free() */
#if defined(__cplusplus)
  CPPSTD_ALLOC,           /* Cpp's 'new type[num]' and 'delete'/'delete[]' */
#endif
  ARENA_ALLOC,            /* Arena allocator */
  CHUNK_ALLOC,            /* Chunk allocator */
} NhAllocType;

#endif /* NH_MEM_ALLOC_H */
