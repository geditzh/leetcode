#include <stdio.h>
#include <stdlib.h>

/* 思路：
首先按照对角线元素交换，然后每行元素都倒序，就是旋转90度
*/
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, temp;
    for (i = 0; i < matrixSize; i++) {
        for (j = i + 1; j < matrixColSize[i]; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (i = 0; i < matrixSize; i++) {
        int front, rear;
        front = 0; 
        rear = matrixColSize[i] - 1;
        while (front < rear) {
            temp = matrix[i][front];
            matrix[i][front] = matrix[i][rear];
            matrix[i][rear] = temp;
            front++;
            rear--;
        }
    }
    return matrix;
}
