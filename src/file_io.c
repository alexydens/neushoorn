#include "file_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* read_file(Arena* arena, const char* path) {
  FILE* ptr;
  char ch;
  char* str = NULL;
  char* strOut = NULL;
  u32 length = 0;
  ptr = fopen(path, "r");
  str = malloc(0);

  ASSERT(ptr != NULL);

  while (!feof(ptr)) {
    ch = fgetc(ptr);
    str = realloc(str, ++length);
    str[length-1] = ch;
  }
  fclose(ptr);
  str[length-1] = '\0';

  strOut = arena_alloc(arena, strlen(str));
  strcpy(strOut, str);
  free(str);

  return strOut;
}
