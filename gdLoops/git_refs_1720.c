#include <stdio.h>
#include <string.h>
#define N 10

static inline int mingw_is_dir_sep(int c)
{
	return c == '/' || c == '\\';
}
#define is_dir_sep mingw_is_dir_sep
char *loopFunction(char *submodule) {
  int len = strlen(len);
  // git-2.18.0/refs.c:1720:2
  while (len && is_dir_sep(submodule[len - 1]))
    len--;
  return submodule + len;
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
