#define PROGRAM_MAX_SIZE 10
#define EXAMPLE_MAX_SIZE 4

#define STR_R_CHR 'r'
#define STR_CHR 'c'
#define MEM_CHR 'm'
#define STR_SPAN 'p'
#define STR_C_SPAN 'n'
#define STR_P_BRK 'b'
#define IS_NULL 'z'
#define SET_TO_START 's'
#define SET_TO_END 'e'
#define INC 'i'
#define END 'f'

#include<assert.h>
char *parse_string(char* prog, int* i) {

    int j = -1;
    int init_limit = 20;
    char *str_buf = malloc(init_limit);
    do {
      j++;
      (*i)++;
      str_buf[j] = prog[*i];
//  printf("i: %d j: %d buf: %s, str_BUF[J] %c\n",i,j, str_buf, str_buf[j]);
    } while(str_buf[j] != 'f' && j < init_limit);
    str_buf[j] = '\0';
    return str_buf;
}

char *interpreter(char* s, char* prog) {
    int i = 0;
    char *result = s, *str_buf;
    //If this flag is set to 0 the next instruction should be skipped
    int condition_flag = 1;


#define condition_check {if(condition_flag == 0) {condition_flag = 1; break;}}
    while((i < (PROGRAM_MAX_SIZE - 1))) {
        switch(prog[i]) {
//            case STR_CHR: 
//              condition_check
//              i++;
//              result = strchr(s, prog[i]);
//              break;
            case MEM_CHR: 
              condition_check
              i++;
              result = memchr(result, prog[i], EXAMPLE_MAX_SIZE);
              break;
            case STR_R_CHR: 
              condition_check
              i++;
              result = strrchr(result, prog[i]);
              break;
            case STR_P_BRK: 
              condition_check
              str_buf = parse_string(prog, &i);
              result = strpbrk(result, str_buf);
              free(str_buf);
              break;
            case STR_SPAN: 
              condition_check
              str_buf = parse_string(prog, &i);
              result =  result + strspn(result, str_buf);
              free(str_buf);
              break;
            case STR_C_SPAN: 
              condition_check
              str_buf = parse_string(prog, &i);
              result = result + strcspn(result, str_buf);
              free(str_buf);
              break;
           case IS_NULL:
              condition_check
              condition_flag = (result < 0x10);
              break;
            case INC:
              condition_check
              result++;
              break;
//            case SET_TO_START:
//              condition_check
//              result = s;
//              break;
            case SET_TO_END:
              condition_check
              result = s + strlen(s);
//              printf("s %p, len %d\n", s, strlen(s));
              break;
            case END:
              return result;
            default:
              return 3243;
        }
//        printf("result %p, prog[i] %c\n ", result, prog[i], i);
        i++;
    }
#undef condition_check
    return 3243;
}

#define MAX_TESTCASES 100
