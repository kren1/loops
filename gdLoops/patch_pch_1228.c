#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *s) {
  // patch-2.7/src/pch.c:1228:6
  while (*s != '\n')
    s++;
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