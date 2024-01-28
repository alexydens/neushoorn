#include <nh_mem_string.h>

/* Create dynamically allocated string from literal (or other const char*) */
str str_from(const char* text, Allocator allocator) {
  str string;

  /* Get string length */
  u64 len = 0;
  const char* pos = text;
  do {
    len++;
    pos++;
  } while (*pos != '\0');

  /* Allocate memory */
  switch (allocator.allocType) {
    case CSTD_ALLOC:
      {
        string.start = malloc(len);
        string.size = len;
      } break;
  }

  return string;
}
/* Free dynaimcally allocated string */
void str_free(str* string);
/* Get dynamically allocated const char* from string literal */
const char* to_chararr(str string);

/* How big is the string (just returns size) */
u64 str_len(str string);
/* Return bool - are the strings equal (NOT LIKE STDLIB) */
bool str_cmp(str a, str b);
/* Copies a string to another string */
str str_cpy(str src, str dest, Allocator allocator);
/* Concatenates two strings - fellowshipOfTheString() */
str str_cat(str first, str last, Allocator allocator);
