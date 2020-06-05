#include <stdio.h>
#include <stdlib.h>

/* 思路：
深度优先遍历，也叫回溯法
*/
void DFS(int left, int right, int n, char *temp, int index, char **result, int *returnSize)
{
    if (left == n && right == n) {
        result[(*returnSize)] = (char *)malloc(sizeof(char) * 2*n+1);
        strcpy(result[(*returnSize)++], temp);
        return;
    }
    if (left < n) {
        temp[index] = '(';
        DFS(left + 1, right, n, temp, index + 1, result, returnSize);
    }
    if (right < n && left > right) {
        temp[index] = ')';
        DFS(left, right + 1, n, temp, index + 1, result, returnSize);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    char **result = (char **)malloc(sizeof(char *) * 2048);
    char *temp = (char *)malloc(2 * n + 1);
    memset(temp, 0, 2*n+1);
    *returnSize = 0;
    DFS(0, 0, n, temp, 0, result, returnSize);
    return result;
}