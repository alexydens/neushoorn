#if !defined(NH_MEM_STRING_H)
#define NH_MEM_STRING_H

/* Base libray */
#include "nh_base.h"
#include "nh_mem_alloc.h"

/* String struct - rather than null-terminated, uses a start and a size */
typedef struct {
  u8* start;              /* The pointer to the string in memory */
  u64 size;               /* Then size of the string in chars/bytes */
  NhAllocType allocType;  /* What is used for the dynamic allocation */
} str;

/* Create dynamically allocated string from literal (or other const char*) */
extern str str_from(const char* text, NhAllocType allocType);
/* Free dynaimcally allocated string */
extern void str_free(str* string);
/* Get dynamically allocated const char* from string literal */
extern const char* to_chararr(str string);

/* How big is the string (just returns size) */
extern u64 str_len(str string);
/* Return bool - are the strings equal (NOT LIKE STDLIB) */
extern bool str_cmp(str a, str b);
/* Copies a string to another string */
extern str str_cpy(str src, str dest, NhAllocType allocType);
/* Concatenates two strings - fellowshipOfTheString() */
extern str str_cat(str first, str last, NhAllocType allocType);

#endif /* NH_MEM_STRING_H */
