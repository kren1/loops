#include <assert.h>
#include <time.h>
void klee_make_symbolic(char* p, size_t i,  const char* c ){}
void klee_assume(int i) {}
char *loopFunctionProg(char* s);

const char* testCases[] = { 
//"a054353 345345 433,",
"054f353 34/5345 433sf,",
"/\\///\\///54f353 34/5345 433sf,",
"54f353 34/5345 433sf,",
//"054f353 34/5345/433,",
"  \ttsdfjlkssd;jfnskd.fsa",
//"fsdgfdgf\f5r\t'",
"                                                                                        s"
};

volatile char* p;
volatile int e;

#define TEST_REPS 10000000

int main(int argc, char** argv) {

    double endTime, startTime = (double)clock()/CLOCKS_PER_SEC;

    for(int j = 0; j < TEST_REPS; j++) {
        for(int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++) {
         p = loopFunction((char*)testCases[i]);
        }
    }

    endTime = (double)clock()/CLOCKS_PER_SEC;
    double timeElapse = endTime - startTime;
    printf("Loop function took %f seconds\n", timeElapse);
    startTime = (double)clock()/CLOCKS_PER_SEC;

    for(int j = 0; j < TEST_REPS; j++) {
        for(int i = 0; i < sizeof(testCases)/sizeof(testCases[0]); i++) {
          //e = strspn(testCases[i], "0123456789");
//          p = strrchr(testCases[i], '/');

            p = loopFunctionProg((char*)testCases[i]);
        }
    }
    endTime = (double)clock()/CLOCKS_PER_SEC;
    printf("Native took %f seconds\n", endTime - startTime);
    printf("Speedup %f\n", timeElapse / (endTime - startTime));
    printf("summary %f %f %f\n", timeElapse, endTime - startTime, timeElapse/(endTime - startTime));
    return 0;
}
