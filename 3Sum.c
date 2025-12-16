#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int capacity = 16;
    int **result = (int **)malloc(capacity * sizeof(int *));
    int *colSizes = (int *)malloc(capacity * sizeof(int));
    int count = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (count == capacity) {
                    capacity *= 2;
                    result = (int **)realloc(result, capacity * sizeof(int *));
                    colSizes = (int *)realloc(colSizes, capacity * sizeof(int));
                }
                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                result[count] = triplet;
                colSizes[count] = 3;
                count++;
                int lastLeftVal = nums[left];
                int lastRightVal = nums[right];
                while (left < right && nums[left] == lastLeftVal) left++;
                while (left < right && nums[right] == lastRightVal) right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    *returnSize = count;
    *returnColumnSizes = colSizes;
    return result;
}
