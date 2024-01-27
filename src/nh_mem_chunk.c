#include <nh_mem_chunk.h>

/* Create a chunk allocator with num chunks of size bytes */
ChunkAllocator create_chunk(u64 num, u64 size) {
  ChunkAllocator allocator;

  /* Populate fields */
  allocator.start = malloc(num * size);         /* The memory used */
  /* Available chunks before current */
  allocator.freed = malloc(num * sizeof(i64));
  allocator.current = 0;                        /* Index of next chunk */
  allocator.num_chunks = num;                   /* How many chunks there are */
  allocator.chunk_size = size;                  /* The size of each chunk */

  return allocator;
}
/* Destroy a chunk allocator */
void destroy_chunk(ChunkAllocator* allocator) {
  free(allocator->start);
  free(allocator->freed);
  allocator->start = NULL;
  allocator->freed = NULL;
  allocator->current = 0;
  allocator->num_chunks = 0;
  allocator->chunk_size = 0;
}

/* Allocate 1 chunk on the allocator */
u8* chunk_alloc(ChunkAllocator* allocator) {
  u64 i;
  if (allocator->current <= allocator->num_chunks) {
    u8* res = allocator->start + (allocator->current * allocator->chunk_size);
    allocator->current++;
    return res;
  }
  for (i = 0; i < allocator->num_chunks; i++) {
    if (allocator->freed[i] != -1) {
      u8* res = allocator->start + (allocator->freed[i] * allocator->chunk_size);
      allocator->freed[i] = -1;
      return res;
    }
  }
  return -1;
}
/* Free 1 chunk on the allocator */
void chunk_free(ChunkAllocator* allocator, u8* ptr) {
  u64 i;
  u64 chunk_index = (ptr-start)/allocator->num_chunks;
  for (i = 0; i < allocator->numChunks; i++) {
    if (allocator->freed[i] == -1)
      allocator->freed[i] = chunk_index;
  }
}
