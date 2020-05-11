#include <stdio.h>

/* 思路：
创建两个数组，数组1下标i保存到i之前的所有元素和，
数组2下标i保存i之后的所有元素和，循环判断，相等则为中心索引 
*/
int pivotIndex(int* nums, int numsSize){
    int num1[numsSize]; 
    int num2[numsSize];
    int i;
    num1[0] = 0;
    num2[numsSize-1] = 0;
    for (i = 1; i < numsSize; i++) {
        num1[i] = num1[i-1] + nums[i-1];
    }
    for (i = numsSize-2; i > -1; i--) {
        num2[i] = num2[i+1] + nums[i+1];
    }
    for (i = 0; i < numsSize; i++) {
        if (num1[i] == num2[i]) {
            return i;
        }
    }
    return -1;

}

int main()
{  
    int nums[6] = {1, 2, 3};
    int numsSize = 3;
    printf("%d", pivotIndex(nums, numsSize)); 
    getchar();
    return 0;
}