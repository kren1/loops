#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *tmp) {
  // libosip2-4.1.0/src/osipparser2/osip_www_authenticate.c:135:5
  for (; *tmp == '\n' || *tmp == '\r'; tmp++) {
  }
  return tmp;
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