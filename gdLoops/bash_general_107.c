#include <stdio.h>
#include <string.h>
#define N 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))
char *loopFunction(char *s) {
  // bash-4.4/general.c:107:3
  while (s && *s && whitespace(*s))
    s++;
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
