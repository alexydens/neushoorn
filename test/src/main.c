/* C Stdlib Dependencies */
#include <string.h>           /* For strcmp() */

/* Project headers */
#include <nh_base.h>          /* Base typedefs, macros and utils */
#include <nh_logging.h>       /* Logging, assertion messages */
#include <nh_mem_alloc.h>     /* Allocation type enumeration */
#include <nh_mem_arena.h>     /* Arena allocator */
#include <nh_mem_chunk.h>     /* Chunk allocator */

/* To test each header */
void test_base();
void test_logging();
void test_arena_alloc();
void test_chunk_alloc();

i32 main() {
  test_base();
  test_arena_alloc();
  test_chunk_alloc();

  test_logging(); /* Testing fatal involves a crash, so needs to come last */
  return 0;
}

void test_base() {
  /* Compiler */
  nh_info("Compiler GCC: %s", STRBOOL(NH_COMPILER_GCC));
  nh_info("Compiler MSVC: %s\n", STRBOOL(NH_COMPILER_MSVC));
  /* Architecture */
  nh_info("Architecture amd64: %s", STRBOOL(NH_CPU_AMD64));
  nh_info("Architecture arm: %s", STRBOOL(NH_CPU_ARM));
  nh_info("Architecture arm64: %s", STRBOOL(NH_CPU_ARM64));
  nh_info("Architecture x86: %s\n", STRBOOL(NH_CPU_X86));
  /* Operating System */
  nh_info("Operating System Windows: %s", STRBOOL(NH_OS_WINDOWS));
  nh_info("Operating System Linux: %s", STRBOOL(NH_OS_LINUX));
  nh_info("Operating System MacOS: %s\n", STRBOOL(NH_OS_MACOS));

  /* Clamp */
  ASSERT(CLAMP(11, 0, 10) == 10);
  nh_info("Clamp above range: success!");
  ASSERT(CLAMP(-1, 0, 10) == 0);
  nh_info("Clamp below range: success!");
  ASSERT(CLAMP(5, 0, 10) == 5);
  nh_info("Clamp within range: success!");
  ASSERT(CLAMP(5.0f, 0.5, (char)10) == 5);
  nh_info("Clamp varying types: success!\n");

  /* Swap */
  {
    i32 a = 1;
    i32 b = 2;
    SWAP(a, b);
    ASSERT(b == 1 && a == 2);
    nh_info("Swap basic use case: success!\n");
  }

  /* Max */
  ASSERT(MAX(5, 0) == 5);
  nh_info("Max 1st value: success!");
  ASSERT(MAX(0, 5) == 5);
  nh_info("Max 2nd value: success!");
  ASSERT(MAX('\0', 5.0f) == 5);
  nh_info("Max varying types: success!\n");
  /* Min */
  ASSERT(MIN(5, 0) == 0);
  nh_info("Min 1st value: success!");
  ASSERT(MIN(0, 5) == 0);
  nh_info("Min 2nd value: success!");
  ASSERT(MIN('\0', 5.0f) == 0);
  nh_info("Min varying types: success!\n");

  /* StrFrom */
  ASSERT(strcmp("test", STRFROM(test)) == 0);
  nh_info("StrFrom: success!");
  
  /* Concat */
  ASSERT(strcmp("ab", STRFROM(CONCAT(a,b))) == 0);
  nh_info("Concat: success\n");

  /* TODO: add test for typedefs? */

  /* Consts */
  /* Min ints */
  nh_info("min_i8: %d", min_i8);
  nh_info("min_i16: %d", min_i16);
  nh_info("min_i32: %d", min_i32);
  nh_info("min_i64: %ld\n", min_i64);
  /* Max ints */
  nh_info("max_i8: %d", max_i8);
  nh_info("max_i16: %d", max_i16);
  nh_info("max_i32: %d", max_i32);
  nh_info("max_i64: %ld\n", max_i64);
  /* Max uints */
  nh_info("max_u8: %u", max_u8);
  nh_info("max_u16: %u", max_u16);
  nh_info("max_u32: %u", max_u32);
  nh_info("max_u64: %lu\n", max_u64);
  /* 32 bit float consts */
  nh_info("pi32: %f", pi32);
  nh_info("e32: %f\n", e32);
  /* 64 bit float consts */
  nh_info("pi64: %lf", pi64);
  nh_info("e64: %lf\n", e64);

  /* Infinity, -infinity */
  nh_info("inf_f32: %f", inf_f32);
  nh_info("neginf_f32: %f", neginf_f32);
  nh_info("inf_f64: %lf", inf_f64);
  nh_info("neginf_f64: %lf\n", neginf_f64);

  /* Linear interpolation */
  ASSERT(LERP(0, 1, 0.5) == 0.5);
  nh_info("Linear interpolation: success!\n");
}
void test_logging() {
  nh_info("Testing info!");
  nh_warn("Testing warn!");
  nh_error("Testing error!");
  nh_fatal("Testing fatal!");
}
void test_arena_alloc() {
  ArenaAllocator arena;
  u32 i;
  u64* a;
  u64* b;
  arena = create_arena(100);
  a = (u64*)arena_alloc(&arena, 2 * sizeof(u64));
  a[0] = 1;
  a[1] = 2;
  b = (u64*)arena_alloc(&arena, 3 * sizeof(u64));
  b[0] = 1;
  b[1] = 2;
  b[2] = 3;
  nh_info("Arena contents (Should be: 1, 2, 1, 2, 3):");
  for (i = 0; i < 5; i++) {
    nh_info("Arena contents at %d: %d", i, ((u64*)arena.start)[i]);
  }
  nh_info("End of arena contents.\n");
  arena_free(&arena);
}
void test_chunk_alloc() {
  ChunkAllocator chunker;
  u64 i;
  u64* a;
  u64* b;
  u64* c;
  chunker = create_chunk(2, 2 * sizeof(u64));
  a = (u64*)chunk_alloc(&chunker);
  b = (u64*)chunk_alloc(&chunker);
  ASSERT(chunk_alloc(&chunker) == NULL);
  nh_info("Chunk full = NULL: success!");
  chunk_free(&chunker, (u8*)b);
  c = (u64*)chunk_alloc(&chunker);
  ASSERT(c != NULL);
  nh_info("Using freed array: success!");
  a[0] = 1;
  a[1] = 2;
  c[0] = 1;
  c[1] = 2;
  nh_info("Chunker contents (Should be: 1, 2, 1, 2):");
  for (i = 0; i < 4; i++) {
    nh_info("Chunker contents at %d: %d", i, ((u64*)chunker.start)[i]);
  }
  nh_info("End of chunker contents.\n");
  destroy_chunk(&chunker);
}
