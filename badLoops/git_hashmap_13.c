#include <stdio.h>
#include <string.h>
#define N 10

//C: bad return value - hashing
char *loopFunction(char *str) {
  // git-2.18.0/hashmap.c:13:2
  while ((c = (unsigned char)*str++))
    hash = (hash * FNV32_PRIME) ^ c;
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
