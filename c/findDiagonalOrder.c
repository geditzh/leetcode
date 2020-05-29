#include <stdio.h>

/* 思路：
注意4个边界问题，当还没遍历到对角线，往右上移动一格，当遍历到
对角线时，往下移动一格
*/
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int i, j, o;
    int m = matrixSize;
    int n = *matrixColSize;
    
    *returnSize=matrixSize*(*matrixColSize);
    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    i = 0;
    j = 0;
    o = 0;
    while (o < (*returnSize)) {
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
