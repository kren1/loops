#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *pattern) {
  int len = strlen(pattern);
  // grep-3.1/lib/exclude.c:552:8
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
