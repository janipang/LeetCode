#include <stdio.h>

int value(char alp)
{
    char num_alp[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int num_val[7] = {1, 5, 10, 50, 100, 500, 1000};
    if (alp == 'I') return 1;
    else if (alp == 'V') return 5;
    else if (alp == 'X') return 10;
    else if (alp == 'L') return 50;
    else if (alp == 'C') return 100;
    else if (alp == 'D') return 500;
    else if (alp == 'M') return 1000;
    else return -1;
}

int romanToInt(char *s)
{
    char *next;
    int keep = 0;
    int result = 0;
    while (*s != '\0')
    {
        next = s + 1;
        if (*next != '\0' && value(*s) < value(*next))
            keep = value(*s);
        else
        {
            // printf("add %d\n", value(*s) - keep);
            result += value(*s) - keep;
            keep = 0;
        }
        s += 1;
    }
    return result;
}

int main()
{
    printf("test1: %d\n", romanToInt("MCMXCIV"));
}