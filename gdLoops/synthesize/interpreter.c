#define PROGRAM_MAX_SIZE 7
#define EXAMPLE_MAX_SIZE 4

#define STR_R_CHR 'r'
#define STR_CHR 'c'
#define STR_SPAN 'p'
#define STR_C_SPAN 'n'
#define STR_P_BRK 'b'
#define IS_NULL 'z'
#define SET_TO_START 's'
#define SET_TO_END 'e'
#define END 'f'

#include<assert.h>


char *interpreter(char* s, char* prog) {
    int i = 0;
    int j, init_limit;
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
              j = -1;
              init_limit = PROGRAM_MAX_SIZE - i;
              do {
                j++;
                i++;
                str_buf[j] = prog[i];
              } while(str_buf[j] != 'f' && j < init_limit);
              str_buf[j] = '\0';
              result = strpbrk(s, str_buf);

              memset(str_buf, 0, PROGRAM_MAX_SIZE);
              break;
            case STR_SPAN: 
              condition_check
              j = -1;
              init_limit = PROGRAM_MAX_SIZE - i;
              do {
                j++;
                i++;
                str_buf[j] = prog[i];
//                printf("j: %d buf: %s, str_BUF[J] %c\n",j, str_buf, str_buf[j]);
              } while(str_buf[j] != 'f' && j < init_limit);
              str_buf[j] = '\0';
              result =  s + strspn(s, str_buf);

              memset(str_buf, 0, PROGRAM_MAX_SIZE);
              break;
            case STR_C_SPAN: 
              condition_check
              j = -1;
              init_limit = PROGRAM_MAX_SIZE - i;
              do {
                j++;
                i++;
                str_buf[j] = prog[i];
              //  printf("i: %d j: %d buf: %s, str_BUF[J] %c\n",i,j, str_buf, str_buf[j]);
              } while(str_buf[j] != 'f' && j < init_limit);
              str_buf[j] = '\0';
              result = s + strcspn(s, str_buf);
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
