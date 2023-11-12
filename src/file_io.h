/* Include guard */
#if !defined (NH_FILE_IO_H)
#define NH_FILE_IO_H

/* Base library */
#include "base.h"
#include "arena_alloc.h"

/* Read text from a file into a null-terminated string stored in an arena */
NHAPI const char* read_file(Arena* arena, const char* path);

#endif /* NH_FILE_IO_H */
