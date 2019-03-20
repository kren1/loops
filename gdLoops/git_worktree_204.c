#include <stdio.h>
#include <string.h>
#define N 10

static inline int mingw_is_dir_sep(int c)
{
	return c == '/' || c == '\\';
}
#define is_dir_sep mingw_is_dir_sep
char *loopFunction(char *path) {
  int len = strlen(path);
  char * name;
  // git-2.18.0/builtin/worktree.c:204:2
  for (name = path + len - 1; name > path; name--)
    if (is_dir_sep(*name)) {
      name++;
      break;
    }
  return name;
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
