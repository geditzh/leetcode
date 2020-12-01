#include <stdio.h>

/* 思路：
如果有进位，则清零进位加一，若都要进位，则创建新数组
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int res[2];
int BinarySearchLeft(int *nums, int numsSize, int target) 
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            right = mid - 1;
        }
    }
    if (left >= numsSize || nums[left] != target) {
        return -1;
    }
    return left;
}

int BinarySearchRight(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    if (numsSize == 0 || nums == NULL) {
        *returnSize = 2;
        res[0] = -1;
        res[1] = -1;
        return res;
    }
    // 找到最左侧
    res[0] = BinarySearchLeft(nums, numsSize, target);

    // 找到最右侧
    res[1] = BinarySearchRight(nums, numsSize, target);

    *returnSize = 2;
    return res;
}


int main()
{
    int nums[1] = {1};
    int numsSize = 1;
    int target = 0;
    int returnSize;
    int *res = searchRange(nums, numsSize, target, &returnSize);
    
    printf("[%d, %d]", res[0], res[1]);
    
    return 0;
}
