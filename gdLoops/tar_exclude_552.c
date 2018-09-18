#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *pattern) {
  // tar-1.29/gnu/exclude.c:552:8
  int len = strlen(pattern);
  while (len > 0 && ISSLASH(pattern[len - 1]))
    --len;
  return pattern + len;
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
