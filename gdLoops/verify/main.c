#include "../synthesize/interpreter.c"
#include <assert.h>

int main(int argc, char** argv) {
    assert(argc == 2 && "verify needs a program as argument");

    char *s = malloc(EXAMPLE_MAX_SIZE);
    char *o, *m;

    klee_make_symbolic(s, EXAMPLE_MAX_SIZE, "s");
    s[EXAMPLE_MAX_SIZE - 1] = '\0';
    
    o = loopFunction(s);
    m = interpreter(s, argv[1]);

//    printf("s: %p original %p, mine %p \n",s,  o, m);
    assert(o == m && "Found a bug with  syntehesized program!");

    return 0;
}
