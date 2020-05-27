#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

int g_col = 0;
int result[1024][1024];
bool dfs(struct TreeNode* root, int sum, int total, int** returnColumnSizes, int* temp, int num)
{
    if (root == NULL) {
        return false;
    }

    if (root->right == NULL && root->left == NULL) {
        total += root->val;
        if (total == sum) {
            temp[num++] = root->val;
            int i;
            for (i = 0; i < num; i++) {
                result[g_col][i] = temp[i];
            }
            returnColumnSizes[0][g_col++] = num;
            return true;
        }
    }
    temp[num++] = root->val;
    total += root->val;
    bool a = dfs(root->left, sum, total, returnColumnSizes, temp, num);
    bool b = dfs(root->right, sum, total, returnColumnSizes, temp, num);   
    return a || b;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes)
{
    g_col = 0;
    *returnSize = 0;

    *returnColumnSizes = malloc(sizeof(int) * 1024);
    int total = 0;
    int nums = 0;
    int temp[1024] = {0};

    if (dfs(root, sum, total, returnColumnSizes, temp, nums)) {  // 能找到和等于给定值
        *returnSize = g_col;
        return result;
    }

    return NULL;
}

void main()
{
    TreeNode tree1, tree2, tree3;
    tree1.val = 5;
    tree1.left = &tree2;
    tree1.right = &tree3;
    tree2.val=3;
    tree2.left = NULL;
    tree2.right = NULL;
    tree3.val=3;
    tree3.left = NULL;
    tree3.right = NULL;
    int num;
    int num1[10];
    pathSum(&tree1, 8, &num, &num1);
}