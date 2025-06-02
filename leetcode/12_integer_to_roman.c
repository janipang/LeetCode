# include <stdio.h>

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
        if (digit_number == 4 || digit_number == 9){

        }else{
            int isFive = digit_number == 5;
            int symbol_index = ((i - 1) * 2) + isFive;
            return symbols[symbol_index];
        }

}

char* intToRoman(int num) {
    int digit = count_digit(num);
    for (int i = digit; i > 0; i--){
        int digit_value = power(10, i-1); //ค่าประจำหลัก
        int digit_number = num /= digit_value; //เลขที่หลักนั้น
        get_symbol(digit_number, digit_value, i);
    }
}

int main(){
//     printf("test1: %d\n", intToRoman(3749)); // -> MMMDCCXLIX
//     printf("test2: %d\n", intToRoman(58)); // -> LVIII
//     printf("test3: %d\n", intToRoman(1994)); // -> MCMXCIV
}
    