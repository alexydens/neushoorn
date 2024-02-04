#include <nh_mem_chunk.h>

/* Create a chunk allocator with num chunks of size bytes */
chunk_alloc_t create_chunk(u64 num, u64 size) {
  chunk_alloc_t allocator;
  u64 i;

  /* Populate fields */
  allocator.start = malloc(num * size);         /* The memory used */
  /* Available chunks before current */
  allocator.freed = malloc(num * sizeof(i64));
  for (i = 0; i < num; i++)
    allocator.freed[i] = -1;
  allocator.current = 0;                        /* Index of next chunk */
  allocator.num_chunks = num;                   /* How many chunks there are */
  allocator.chunk_size = size;                  /* The size of each chunk */

  return allocator;
}
/* Destroy a chunk allocator */
void destroy_chunk(chunk_alloc_t* allocator) {
  free(allocator->start);
  free(allocator->freed);
  allocator->start = NULL;
  allocator->freed = NULL;
  allocator->current = 0;
  allocator->num_chunks = 0;
  allocator->chunk_size = 0;
}

/* Allocate 1 chunk on the allocator */
u8* chunk_alloc(chunk_alloc_t* allocator) {
  u64 i;
  /* If possible, choose from top */
  if (allocator->current < allocator->num_chunks) {
    u8* res = allocator->start + (allocator->current * allocator->chunk_size);
    allocator->current++;
    return res;
  }
  /* Otherwise, check from freed array */
  for (i = 0; i < allocator->num_chunks; i++) {
    if (allocator->freed[i] != -1) {
      u8* res = allocator->start + (allocator->freed[i] * allocator->chunk_size);
      allocator->freed[i] = -1;
      return res;
    }
  }
  /* Allocation failed: out of room */
  return NULL;
}
/* Free 1 chunk on the allocator */
void chunk_free(chunk_alloc_t* allocator, u8* ptr) {
  u64 i;
  u64 chunk_index = (ptr-allocator->start)/allocator->chunk_size;
  for (i = 0; i < allocator->num_chunks; i++) {
    if (allocator->freed[i] == -1)
      allocator->freed[i] = chunk_index;
  }
}
