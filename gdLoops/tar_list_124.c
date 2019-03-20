#include <stdio.h>
#include <string.h>
#define STR_SIZE 10


# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *file_name) {
  // tar-1.29/src/list.c:124:3
  char* p;
  for (p = file_name; *p && (ISSLASH(*p) || *p == '.'); p++)
    ;
  return p;
}

void driver() {
  char str[STR_SIZE];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
