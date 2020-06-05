#include <stdio.h>
#include <stdlib.h>

/* 思路：
暴力求解方法，存储数据，然后读取
*/

int mycmp(void *a, void *b)
{
    int *num1 = (int *)a;
    int *num2 = (int *)b;
    return *num2 - *num1;
}

int main()
{
    int nums[10] = {8,7,6,5,3,2,4,5,6,8};
    qsort(nums, 10, sizeof(int), mycmp);    
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
