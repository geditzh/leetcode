#include <stdio.h>

/* 思路：
如果有进位，则清零进位加一，若都要进位，则创建新数组
*/
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i;
    if (digits[digitsSize-1] != 9) {
        digits[digitsSize-1]++; 
        *returnSize = digitsSize;
        return digits;  
    }
    i = digitsSize - 1;
    while (i >= 0 && digits[i] == 9) {
        digits[i] = 0;
        i--;
    }
    if (i >= 0) {
        digits[i]++;
        *returnSize = digitsSize;
        return digits;
    }

    int *digitTemp = (int *)malloc(sizeof(int) * (digitsSize+1));
    digitTemp[0] = 1;
    memset(digitTemp+1, 0, sizeof(int)*digitsSize);
    // for (i = 1; i < digitsSize+1; i++) {
    //     digitTemp[i] = 0;
    // }
    *returnSize = digitsSize + 1;
    return digitTemp;
}

int main()
{
    int nums[2] = {3, 9};
    int numsSize = 2;
    int returnSize = 0;
    int *temp = plusOne(nums, numsSize, &returnSize);
    int i;
    for (i = 0; i < returnSize; i++) {
        printf("%d ", temp[i]);
    }
    if (temp != nums) {
        free(temp);
    }
    getchar();
    return 0;
}