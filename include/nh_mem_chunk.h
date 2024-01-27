/* Include guard */
#if !defined (NH_MEM_CHUNK_H)
#define NH_MEM_CHUNK_H

/* Base library */
#include "nh_base.h"

/* Chunk allocator struct */
typedef struct {
  u8* start;      /* The main pointer */
  i64* freed;     /* Which chunks are freed - usued after current reaches end */
  u64 current;    /* The current chunk index */
  u64 num_chunks; /* The maximum number of chunks to allocate */
  u64 chunk_size; /* The size of each chunk */
} ChunkAllocator;

/* Create a chunk allocator with num chunks of size bytes */
extern ChunkAllocator create_chunk(u64 num, u64 size);
/* Destroy a chunk allocator */
extern void destroy_chunk(ChunkAllocator* allocator);
/* Allocate 1 chunk on the allocator */
extern u8* chunk_alloc(ChunkAllocator* allocator);
/* Free 1 chunk on the allocator */
extern void chunk_free(ChunkAllocator* allocator, u8* ptr);

#endif /* NH_MEM_CHUNK_H */
