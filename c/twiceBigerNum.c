#include <stdio.h>

/* 思路：
循环两边，第一遍存储最大元素，第二遍判断是否为两倍
*/
// int dominantIndex(int* nums, int numsSize){
//     int i, max = -65536, maxInd = 0;
//     for (i = 0; i < numsSize; i++) {
//         if (nums[i] > max) {
//             max = nums[i];
//             maxInd = i;
//         }
//     }
//     for (i = 0; i < numsSize; i++) {
//         if (i == maxInd) {
//             continue;
//         }
//         if (2 * nums[i] > max) {
//             return -1;
//         }
//     }
//     return maxInd;
// }


int main()
{  
    int nums[6] = {3, 6, 1, 0};
    int numsSize = 4;
    printf("%d", dominantIndex(nums, numsSize)); 
    getchar();
    return 0;
}