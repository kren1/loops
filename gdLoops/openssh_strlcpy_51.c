#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *s) {
  // openssh-7.4p1/openbsd-compat/strlcpy.c:51:3
  while (*s++)
    ;
  return s;
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
#undef N
