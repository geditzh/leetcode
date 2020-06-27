#include <stdio.h>
#include <stdlib.h>

/* 思路：
创建map存储第几列需要清零，然后用行指针存储循环的行，
如果某行元素找到为0，则记录他的列信息到map中，同时循环结束该行时清零该行。
*/
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    int map[1024] = {0};
    int flag;
    for (i = 0; i < matrixSize; i++) {
        int *temp = matrix[i];
        flag = 0;
        for (j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                map[j] = 1;
                flag = 1;
            }
        }
        if (flag == 1) {
            memset(temp, 0, sizeof(int) * matrixColSize[i]);
        }
    }
    int o;
    for (o = 0; o < 1024; o++) {
        if (map[o] != 0) {
            j = o;
            for (i = 0; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }            
        }
    }
}

class tion:
    def longestPalindrome(self, s)
    {
        if not s:
            return ""
        if_palindrome = {False, }
    }