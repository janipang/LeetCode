# include <stdio.h>

void append_str(char* dest, const char* src, int* index) {
    while (*src) {
        dest[*index] = *src;
        (*index)++;
        src++;
    }
    dest[*index] = '\0';
}

int power(int base ,int power){
    if (power == 0) return 1;
    else{
        int result = 1;
        for (int i = 0; i < power; i++){
            result *= base;
        }
        return result;
    }
}

int count_digit(int num){
    if (num >= 1) {
        num /= 10;
        return count_digit(num) + 1;
    }
    else{
        return 0;
    }
}

char* get_symbol(int digit_number, int digit_value, int i){
    // digit_value  = {1,   1,   10,  10,  100, 100, 1000};
    // value        = {1,   5,   10,  50,  100, 500, 1000};

    // digit_number = {1,   5,   1,   5,   1,   5,   1};
    // i            = {1,   1,   2,   2,   3,   3,   4};
    // i - 1        = {0,   0,   1,   1,   2,   2,   3};
    // (i - 1) * 2  = {0,   0,   2,   2,   4,   4,   6};
    // ((i-1)*2) +1if5  = {0,   1,   2,   3,   4,   5,   6};
    // index        = {0,   1,   2,   3,   4,   5,   6};
    char symbols[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    static char result[10];
    int result_index = 0;
    int value = digit_number * digit_value;
    while (value > 0){
        int isFive = 0;
        if (value >= 5 * digit_value){
            isFive = 1;
            value -= 5 * digit_value;
        }
        else{
            value -= 1 * digit_value;
        }
        int symbol_index = ((i - 1) * 2) + isFive;
        result[result_index] = symbols[symbol_index];
        result_index ++;
    }
    result[result_index] = '\0';
    return result;
}

char* get_symbol_49(int digit_number, int digit_value, int i){
    char prefix = get_symbol(1, digit_value, i)[0];
    char suffix;
    static char result[10];
    int result_index = 0;
    if (digit_number == 4) suffix = get_symbol(5, digit_value, i)[0];
    if (digit_number == 9) suffix = get_symbol(1, digit_value * 10, i + 1)[0];
    result[result_index ++] = prefix;
    result[result_index ++] = suffix;
    result[result_index] = '\0';
    return result;
}

char* intToRoman(int num) {
    int digit = count_digit(num);
    static char result[100];
    int result_index = 0;
    char *temp;
    for (int i = digit; i > 0; i--){
        int digit_value = power(10, i-1);
        int digit_number = (num / digit_value) % 10;
        // printf("digit_value: %d, digit_number: %d, i: %d\n", digit_number,digit_value, i); 
        if(digit_number == 4 || digit_number == 9) temp = get_symbol_49(digit_number, digit_value, i);
        else temp = get_symbol(digit_number, digit_value, i);
        append_str(result, temp, &result_index);
    }
    // printf("result: %s", result);
    return result;
}

int main(){
    // printf("test1: %s\n", intToRoman(3749)); // -> MMMDCCXLIX
    // printf("test2: %s\n", intToRoman(58)); // -> LVIII
    printf("test3: %s\n", intToRoman(1994)); // -> MCMXCIV
}
    