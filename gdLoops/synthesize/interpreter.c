#define PROGRAM_MAX_SIZE 6
#define EXAMPLE_MAX_SIZE 4

#define STR_R_CHR 'r'
#define STR_CHR 'c'
#define STR_SPAN 'p'
#define STR_P_BRK 'b'
#define IS_NULL 'z'
#define SET_TO_START 's'
#define SET_TO_END 'e'
#define END '\0'

#include<assert.h>


char *interpreter(char* s, char* prog) {
    int i = 0;
    int j;
    char *result;
    //If this flag is set to 0 the next instruction should be skipped
    int condition_flag = 1;

    char str_buf[PROGRAM_MAX_SIZE] = {0};

#define condition_check {if(condition_flag == 0) {condition_flag = 1; break;}}
    while((i < (PROGRAM_MAX_SIZE - 1))) {
        switch(prog[i]) {
            case STR_CHR: 
              condition_check
              i++;
              result = strchr(s, prog[i]);
              break;
            case STR_R_CHR: 
              condition_check
              i++;
              result = strrchr(s, prog[i]);
              break;
            case STR_P_BRK: 
              condition_check
              i++;
              j = 0;
              do {
                str_buf[j] = prog[i];
                i++, j++;
              } while(str_buf[j] != '\0' && j < PROGRAM_MAX_SIZE);
              result = strchr(s, str_buf);

              memset(str_buf, 0, PROGRAM_MAX_SIZE);
              break;
            case STR_SPAN: 
              condition_check
              i++;
              j = 0;
              do {
                str_buf[j] = prog[i];
                i++, j++;
              } while(str_buf[j] != '\0' && j < PROGRAM_MAX_SIZE);
              result =  s + strspn(s, str_buf);

              memset(str_buf, 0, PROGRAM_MAX_SIZE);
              break;
           case IS_NULL:
              condition_check
              condition_flag = (result == NULL);
              break;
            case SET_TO_START:
              condition_check
              result = s;
              break;
            case SET_TO_END:
              condition_check
              result = s + strlen(s);
              break;
            case END:
              return result;
            default:
              return 3243;
        }
        i++;
    }
#undef condition_check
    return 3243;
}

#define MAX_TESTCASES 100
