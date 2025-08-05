#include <stdio.h>
#include <string.h>

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int capacity = 100000;
    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    if (numsSize < 3)
        return;
    for (int i = 0; i < numsSize - 2; i++)
    {
        for (int j = i + 1; j < numsSize - 1; j++)
        {
            for (int k = j + 1; k < numsSize; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0){
                    result[*returnSize] = malloc(3 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[k];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                }
            }
        }
    }
    return result;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    printf("test1: %d\n", threeSum(nums, len(nums), 3, 3));
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */