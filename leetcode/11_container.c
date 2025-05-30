#include <stdio.h>

int min(int a, int b){
    return a < b ? a : b;
}

int maxArea(int* height, int heightSize) {
    int max_area = 0;
    int cur_area = 0;
    for ( int start = 0; start < heightSize - 1; start++){
        int max_possible = height[start] * (heightSize - start - 1);
        if ( max_possible < max_area ) continue;
        for ( int stop = start + 1; stop < heightSize; stop ++){
            cur_area = (stop - start) * min(height[start], height[stop]);
            // printf("start %d, stop %d, height1 %d, height2 %d, area %d\n", start, stop, height[start], height[stop], cur_area);
            if (cur_area > max_area) max_area = cur_area;
        }
        // printf("---------------\n");
    }
    return max_area;
}

int main()
{
    int length = 9;
    int array[100] = {1,8,6,2,5,4,8,3,7};
    // printf("test1: %d\n", maxArea(array, length));
    return 0;
}