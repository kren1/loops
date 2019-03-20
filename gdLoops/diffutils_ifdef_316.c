#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *f) {
  // diffutils-3.6/src/ifdef.c:316:3
  char c;
  while ((c = *f++) == '-' || c == '\'' || c == '0')
    continue;
  return f;
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
