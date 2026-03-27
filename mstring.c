#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mstring.h"


// Initialize a 'struct String' with a given buffsize to 'String->ptr'.
/// buffsize => Used to allocate memomry to 'String->ptr'
/// @return  => A pointer to a 'String struct' or NULL if allocation fails
String *string_new(size_t buffsize) {
  String *string = malloc(sizeof(String));
  if (string == NULL) {
    return NULL;
  }

  char *s = malloc(buffsize);
  if (s == NULL) {
    free(string);
    return NULL;
  }

  string->ptr      = s;
  string->buffsize = buffsize;
  string->len      = 0;

  return string;
}

// Calls free to 'struct String' and 'String->ptr != NULL', does nothing if 'String'
// points to NULL.
/// *string => An allocated String pointer
void string_free(String *string) {
  free(string->ptr);
  string->ptr = NULL;
  free(string);
}

// Copy 'new_data' to 'String->ptr', updating all fields of 'String'.
/// *string   => An pointer to a 'String struct' initialized like
///              the function 'String *string_new(size_t buffsize)'  
/// *new_data => An C string, optional terminated with '\0'
///  len      => Length of new_data, excluding the terminating '\0'
/// @return   => 0 in success. -1 if string points to NULL. -2 if new_data points
///              to NULL. -3 if buffsize is not big enough and malloc could not
///              allocate memory.   
int string_copy(String *string, const char *new_data, size_t len) {
  size_t new_data_buffsize = len + 1;

  if (string == NULL) {
    return -1;
  }

  if (new_data == NULL) {
    return -2;
  }

  if (string->buffsize < new_data_buffsize) {
    char *tmp = realloc(string->ptr, new_data_buffsize);
    if (tmp == NULL) return -3;

    string->ptr = tmp;
    string->buffsize = new_data_buffsize;
  }


  memcpy(string->ptr, new_data, len);
  string->ptr[len] = '\0';
  string->len = len;

  return 0;
}
