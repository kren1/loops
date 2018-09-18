#include <stdio.h>
#include <string.h>
#define N 10

//C: return in loop
char *loopFunction(char *str) {
  // libosip2-4.1.0/src/osipparser2/osip_message_parse.c:217:5
  while ((*hp != '\r') && (*hp != '\n')) {
    if (*hp)
      hp++;
    else {
      OSIP_TRACE(
          osip_trace(__FILE__, __LINE__, OSIP_ERROR, NULL, "No crlf found\n"));
      return OSIP_SYNTAXERROR;
    }
  }
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
