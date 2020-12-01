#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 26
int g_parent[MAX_LEN];
int g_size[MAX_LEN];
int g_count;

void Init()
{
    int i;
    for (i = 0; i < MAX_LEN; i++) {
        g_parent[i] = i;
        g_size[i] = 1;
    }
    g_count = MAX_LEN;
}

int Find(int i)
{
    if (g_parent[i] == i) {
        return i;
    }
    g_parent[i] = g_parent[g_parent[i]];
    i = g_parent[i];

    return Find(i);
}

void Join(int a, int b)
{
    int aParent = Find(a);
    int bParent = Find(b);

    if (aParent == bParent) {
        return;
    }
    if (g_size[aParent] > g_size[bParent]) {
        g_parent[bParent] = aParent;
        g_size[aParent] += g_size[bParent];
    } else {
        g_parent[aParent] = bParent;
        g_size[bParent] += g_size[aParent];
    }
    g_count--;
    return;
}

int GetCount()
{
    return g_count;
}

int Connect(int a, int b)
{
    return g_parent[a] == g_parent[b];
}

bool equationsPossible(char ** equations, int equationsSize){
{
    bool res = true;

    if (equationsSize == 0 || equations == NULL) {
        return res;
    }
    
    Init();
    int i;
    for (i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            continue;
        }
        if (equations[i][0] == equations[i][3]) {
            continue;
        }

        Join(equations[i][0] - 'a', equations[i][3] - 'a');
    }

    for (i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!') {
            if (Find(equations[i][0]) == Find(equations[i][3])) {
                res = false;
                break;
            }
        }
    }
    return res;
}

int main()
{

    char str[3][5] = {"a==b", "b==a", "a==c"};

    char *pStr[3];
    pStr[0] = &str[0][0];
    pStr[1] = str[1];
    pStr[2] = str[2];
    equationPossible(pStr, 3);
    return 0;
}