#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *buf) {
  // git-2.18.0/ref-filter.c:1081:2
  while (*buf == '\n')
    buf++;
  return buf;
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