
#ifndef MSTRING_H
#define MSTRING_H 1

#include <stddef.h>
typedef struct {
  char *ptr;        // C string
  size_t len;       // string length
  size_t buffsize;   // size of buffer to ptr
} String;

// Initialize a 'struct String' with a given buffsize to 'String->ptr'.
/// buffsize => Used to allocate memomry to 'String->ptr'
/// @return  => A pointer to a 'String struct' or NULL if allocation fails
String *string_new(size_t bufsize);

// Calls free to 'struct String' and 'String->ptr'
/// *string => An allocated String pointer
void string_free(String *string);

// Copy 'new_data' to 'String->ptr', updating all fields of 'String'.
/// *string   => An pointer to a 'String struct' initialized like
///              the function 'String *string_new(size_t buffsize)'  
/// *new_data => An C string, optional terminated with '\0'
///  len      => Length of new_data, excluding the terminating '\0'
/// @return   => 0 in success. -1 if string points to NULL. -2 if new_data points
///              to NULL. -3 if buffsize is not big enough and malloc could not
///              allocate memory.   
int string_copy(String *string, const char *new_data, size_t len);

#endif
