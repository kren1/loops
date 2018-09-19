#define PROGRAM_MAX_SIZE 10
#define EXAMPLE_MAX_SIZE 6

#define STR_R_CHR 'r'
#define IS_NULL 'z'
#define SET_TO_START 's'
#define END '\0'

#include<assert.h>


char *interpreter(char* s, char* prog) {
    int i = 0;
    char *result;
    //If this flag is set to 0 the next instruction should be skipped
    int condition_flag = 1;

#define condition_check {if(condition_flag == 0) {condition_flag = 1; break;}}
    while((i < (PROGRAM_MAX_SIZE - 1))) {
        switch(prog[i]) {
            case STR_R_CHR: 
              condition_check
              i++;
              result = strrchr(s, prog[i]);
              break;
            case IS_NULL:
              condition_check
              condition_flag = (result == NULL);
              break;
            case SET_TO_START:
              condition_check
              result = s;
              break;
            case END:
              return result;
        }
        i++;
    }
#undef condition_check
    return 3243;
}

#define MAX_TESTCASES 100
int main() {
    char **counterexample = calloc(sizeof(char*), MAX_TESTCASES);
    int next_test_case = 0;
    char *prog;

    char *s, *o, *m;

    do {
        printf("Attempt #%d\n", next_test_case);

        prog = malloc(PROGRAM_MAX_SIZE);
        klee_make_symbolic(prog, PROGRAM_MAX_SIZE, "program");

        //Constrain prog to current counter examples
        for(int j = 0; j < next_test_case; j++) {
            char* cex = counterexample[j];
            klee_assume(loopFunction(cex) ==  interpreter(cex, prog));
        }
        //Concretize prog
        printf("PROG: ");
        for(int k = 0; k < PROGRAM_MAX_SIZE; k++) {
            prog[k] = klee_get_valuel(prog[k]);
            printf("%c", prog[k]);
        }
        printf("END\n");

        //Find new counterexample
        s = malloc(EXAMPLE_MAX_SIZE);
        klee_make_symbolic(s, EXAMPLE_MAX_SIZE, "s");
        s[EXAMPLE_MAX_SIZE - 1] = '\0';
        
        klee_open_merge();
        o = loopFunction(s);
        m = interpreter(s, prog);
        klee_close_merge();

        int results_the_same = (o == m);

        //If there is a single solution to 0 == m and that
        //solution is that they are equal, we are done!
        if ((klee_is_symbolic(results_the_same) == 0)
            & (o == m)) {
            break;
        }
        
        free(prog);
        //otherwise we add a counterexample
        if(results_the_same == 0) {
            //concretize the counterexample
            for(int n = 0; n < EXAMPLE_MAX_SIZE; n++) {
                s[n] = klee_get_valuel(s[n]);
            }
            counterexample[next_test_case] = s;
            next_test_case++;
            if(next_test_case >= MAX_TESTCASES) 
                assert(0 && "Too small counterexample array");
        
        } else {
            //prune the paths where results are the same
            klee_silent_exit(0);
        }

    } while(1);


    printf("FOUND the program: ");
    for(int k = 0; k < PROGRAM_MAX_SIZE; k++) {
        prog[k] = klee_get_valuel(prog[k]);
        printf("%c", prog[k]);
    }
    printf("END!\n");


    assert(0 && "Found it! Stopping!");

    return 0;
}
