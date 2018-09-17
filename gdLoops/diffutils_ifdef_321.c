#include <stdio.h>
#include <string.h>
#define N 10

#  define IN_CTYPE_DOMAIN(c) 1
#define ISDIGIT(c) (IN_CTYPE_DOMAIN (c) && isdigit ((unsigned char)c))
char *loopFunction(char *f) {
  char c = *f;
  // diffutils-3.6/src/ifdef.c:321:5
  while (ISDIGIT(c = *f++))
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
