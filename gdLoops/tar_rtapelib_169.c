#include <stdio.h>
#include <string.h>
#define N 10

char *loopFunction(char *command_buffer) {
  // tar-1.29/lib/rtapelib.c:169:3
  char *cursor;
  for (cursor = command_buffer; *cursor; cursor++)
    if (*cursor != ' ')
      break;
  return cursor;
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
