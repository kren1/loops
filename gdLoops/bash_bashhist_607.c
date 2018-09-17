#include <stdio.h>
#include <string.h>
#define N 10

#define whitespace(c) (((c) == ' ') || ((c) == '\t'))

char* loopFunction(char* line) {
// bash-4.4/bashhist.c:607:3 
for (char *p = line; p && *p && whitespace (*p); p++)
    ;


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