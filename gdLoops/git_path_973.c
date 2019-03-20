#include <stdio.h>
#include <string.h>
#define N 10

static inline int mingw_is_dir_sep(int c)
{
	return c == '/' || c == '\\';
}
#define is_dir_sep mingw_is_dir_sep
char *loopFunction(char *prefix) {
  int i = 0;
  // git-2.18.0/path.c:973:4
  while (is_dir_sep(prefix[i]))
    i++;
  return prefix + i;
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
