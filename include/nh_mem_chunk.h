/* Include guard */
#if !defined (NH_MEM_CHUNK_H)
#define NH_MEM_CHUNK_H

/* Base library */
#include "nh_base.h"

/* C Stdlib Dependencies */
#include <stdlib.h>   /* Heap allocation */

/* Chunk allocator struct */
typedef struct {
  u8* start;      /* The main pointer */
  i64* freed;     /* Which chunks are freed - usued after current reaches end */
  u64 current;    /* The current chunk index */
  u64 num_chunks; /* The maximum number of chunks to allocate */
  u64 chunk_size; /* The size of each chunk */
} chunk_alloc_t;

/* Create a chunk allocator with num chunks of size bytes */
extern chunk_alloc_t create_chunk(u64 num, u64 size);
/* Destroy a chunk allocator */
extern void destroy_chunk(chunk_alloc_t* allocator);
/* Allocate 1 chunk on the allocator */
extern u8* chunk_alloc(chunk_alloc_t* allocator);
/* Free 1 chunk on the allocator */
extern void chunk_free(chunk_alloc_t* allocator, u8* ptr);

#endif /* NH_MEM_CHUNK_H */
