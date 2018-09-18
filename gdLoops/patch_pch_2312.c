#include <stdio.h>
#include <string.h>
#define N 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *p) {
  // patch-2.7/src/pch.c:2312:4
  while (ISDIGIT(*++p))
    /* do nothing */;
  return p;
}

void driver() {
  char str[N];
  klee_make_symbolic(str, sizeof(str), "str");

  char *p = loopFunction(str);
#ifdef DRIVER
#include "driver.c"
#endif
}

#ifdef MAIN_FUNC
#include "main.c"
#endif
