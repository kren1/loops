#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *p) {
  // patch-2.7/src/pch.c:2342:3
  while (*p == ' ' || *p == '\t')
    p++;
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
