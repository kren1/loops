#include <stdio.h>
#include <string.h>
#define N 10

//C: unclear input
char *loopFunction(char *str) {
  // git-2.18.0/name-hash.c:60:2
  while (namelen > 0 && !is_dir_sep(ce->name[namelen - 1]))
    namelen--;
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
