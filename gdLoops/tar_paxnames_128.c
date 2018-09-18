#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *p) {
  // tar-1.29/lib/paxnames.c:128:7
  for (; ISSLASH(*p); p++)
    continue;
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
