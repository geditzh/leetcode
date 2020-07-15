#include <stdio.h>
#include <stdlib.h>
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

/* 思路：
    用一个值统计总和，每次减去循环的值，就代表了右侧的值大小
*/
int pivotIndex1(int* nums, int numsSize){
    if (numsSize == 0) {
        return -1;
    }
    int i;
    int res = -1;
    int totalNum = 0;
    for (i = 0; i < numsSize; i++) {
        totalNum += nums[i];
    }
    int leftNum = 0;
    for (i = 0; i < numsSize; i++) {
        totalNum -= nums[i];
        if (totalNum == leftNum) {
            res = i;
            break;
        }
        leftNum += nums[i];
    }
    return res;
}

int main()
{  
    int nums[6] = {1, 2, 3};
    int numsSize = 3;
    printf("%d", pivotIndex(nums, numsSize)); 
    getchar();
 
    return 0;
}