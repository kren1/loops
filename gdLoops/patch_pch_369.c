#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *sha1) {
  // patch-2.7/src/pch.c:369:3
  char*s;
  for (s = sha1; *s; s++)
    if (*s != '0')
      break;
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
