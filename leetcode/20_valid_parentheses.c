# include <stdio.h>

int symIndex(char sym){
    if (sym == '(' || sym == ')') return 0;
    else if (sym == '{' || sym == '}') return 1;
    else if (sym == '[' || sym == ']') return 2;
    else return -1;
}

int isValid(char* s) {
    char stack[10000];
    char* stack_ptr = stack;
    char open_sym[4] = "({[";
    char close_sym[4] = ")}]";
    while (*s != '\0'){
        if (*s == '(' || *s == '{' || *s == '['){
            stack_ptr++;
            *stack_ptr = *s;
        }
        if (*s == ')' || *s == '}' || *s == ']'){
            if (symIndex(*s) == symIndex(*(stack_ptr))){
                stack_ptr --;
            }
            else{
                return 0;
            }
        }
        s++;
    }
    return 1;
}

int main(){
    printf("test1: %d\n", isValid("["));
}
    