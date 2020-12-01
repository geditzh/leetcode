#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200
int g_parent[MAX_LEN];
int g_size[MAX_LEN];
int g_count;

void Init(int n)
{
    int i;
    for (i = 0; i < MAX_LEN; i++) {
        g_parent[i] = i;
        g_size[i] = 1;
    }
    g_count = n;
}

int Find(int x)
{
    if (x == g_parent[x]) {
        return x;
    }

    g_parent[x] = g_parent[g_parent[x]];
    x = g_parent[x];
    return Find(x);
}

void Join(int a, int b)
{
    int a_parent = Find(a);
    int b_parent = Find(b);

    if (a_parent == b_parent) {
        return;
    }

    if (g_size[a_parent] > g_size[b_parent]) {
        g_parent[b_parent] = a_parent;
        g_size[a_parent] += g_size[b_parent];
    } else {
        g_parent[a_parent] = b_parent;
        g_size[b_parent] += g_size[a_parent];
    }
    g_count--;
    return;
}

int GetCount ()
{
    return g_count;
}

int Connect(int a, int b)
{
    int a_parent = Find(a);
    int b_parent = Find(b);
 
    return a_parent == b_parent;
}

int findCircleNum(int **M, int MSize, int* MColSize){
    int n = MSize;
    Init(n);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (M[i][j] == 1) {
                Join(i, j);
            }
        }
    }

    return GetCount();
}

void main(int argc, char **argv)
{
    int arr[3][3] = {{1, 1, 0},
                     {1, 1, 0},
                     {0, 0, 1}};
    int size = 3;
    int colSize[3] = {3, 3, 3};
    int *p[3];
    p[0] = arr[0];
    p[1] = arr[1];
    p[2] = arr[2];
    int res = findCircleNum(arr, size, colSize);
    printf("%d", res);
    return;
}