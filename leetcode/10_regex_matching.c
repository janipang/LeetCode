#include <stdio.h>

int isMatch(char* string, char* pattern) {
    char* p_start = pattern;
    char* s_start = string;
    char stack_storage[21];
    char* stack = stack_storage;
    
    while (*pattern != '\0' && *string != '\0'){
        // printf("string: %c, pattern: %c, stack %c\n", *string, *pattern, *(stack - 1));
        if (*string == *pattern || *pattern == '.'){
            *stack = *string;
            stack++;
            string++;
            pattern++;
        }
        else{
            if (*pattern == '*'){
                if (*string == *(stack - 1) || *(pattern - 1) == '.'){
                    *stack = *string;
                    stack++;
                    string++;
                }
                else {
                    pattern++;
                    if (*string == *pattern || *pattern == '.'){
                        *stack = *string;
                        stack++;
                        string++;
                        pattern++;
                    }
                    else {
                        return 0;
                    }
                }
            }
            else{
                return 0;
            }
        }
    }
    
    // printf("-- string: %c, pattern: %c, stack %c\n", *string, *pattern, *(stack - 1));
    if (*pattern == '\0' && *string == '\0') return 1;
    if (*pattern != '\0' && *string == '\0' && *pattern == '*' && *(pattern + 1) == '\0') return 1;
    return 0;
}

int main(){
    // printf("test case 1: %d\n", isMatch("aa", "a"));
    // printf("test case 2: %d\n", isMatch("aa", "aa"));
    // printf("test case 3: %d\n", isMatch("aa", "a*"));
    // printf("test case 4: %d\n", isMatch("ab", ".*"));
    // printf("test case 5: %d\n", isMatch("aab", "c*a*b"));
    return 0;
}