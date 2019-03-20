#include <stdio.h>
#include <string.h>
#define N 10

# define ISSLASH(C) ((C) == '/' || (C) == '\\')
char *loopFunction(char *base) {
  // tar-1.29/gnu/basename-lgpl.c:36:3
  while (ISSLASH(*base))
    base++;
  return base;
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
