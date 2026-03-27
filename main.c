#include <stdio.h>
#include <string.h>
#include "mstring.h"

int main(void) {
  String *s1 = string_new(70); 
  if (s1 == NULL) return -1;

  char *name = "Mateus";
      
  string_copy(s1, name, strlen(name));
  printf("Hello, %s. Your name has %zu letters and is wasting %zu bytes!\n", s1->ptr, s1->len, s1->buffsize);
  int name_length = s1->len;

  String *s2 = string_new(2);
  if (s2 == NULL) return -1;

  string_copy(s2, s1->ptr, s1->len);

  string_free(s1);

  if (name_length == s2->len)
    printf("Hello again, %s. Your name has the same amount of letters but is wasting %zu bytes now!\n", s2->ptr, s2->buffsize);

  string_free(s2);

  return 0;
}
