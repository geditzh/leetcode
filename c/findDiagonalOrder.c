#include <stdio.h>

/* 思路：
创建两个数组，数组1下标i保存到i之前的所有元素和，
数组2下标i保存i之后的所有元素和，循环判断，相等则为中心索引 
*/
int* findDiagonalOrder(int* matrix[][3], int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;
    int n = *matrixColSize;
    if (matrixSize == 0 || matrix == NULL || *matrixColSize == 0) {
        *returnSize = 0;
        return 0;
    }
    int i, j, o;
    *returnSize=matrixSize*(*matrixColSize);
    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    i = 0;
    j = 0;
    while (i != m - 1 || j != n - 1) {
        while (i >= 0 && j < n) {
            result[o++] = matrix[i][j];
            if (j == n - 1) {
                break;
            } 
            i -= 1;
            j += 1;
        }
        i += 1;
        while (i < m && j >= 0) {
            result[o++] = matrix[i][j];
            if (i == m - 1) {
                break;
            }
            i += 1;
            j -= 1;
        }
        j += 1;
    }
    result[o] = matrix[i][j];
    return result;
}


int main()
{
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrixSize = 3;
    int matrixColSize[3] = {3, 3, 3};
    int *result;
    int resultSize;
    result = findDiagonalOrder(matrix, matrixSize, matrixColSize, &resultSize);
    int i;
    for (i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
}
