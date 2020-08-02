#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char res[50] = {0};
void GetSubStr(char subArray[][4], int i, int num)
{
    if (i == num) {
        printf("%s\n", res);
        return;
    }

    int j;
    for (j = 0; j < strlen(subArray[i]); j++) {
        if (!isalpha(subArray[i][j])) {
            continue;
        }
        res[i] = subArray[i][j];
        GetSubStr(subArray, i+1, num);
        res[i] = '\0';
    }
}
int main()
{
    char subArray[4][4] = {"abx", "c", "d,e", "f,z"};
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d", strlen(subArray[i]));
    }

    for (i = 0; i < strlen(subArray[0]); i++) {
        if (!isalpha(subArray[0][i])) {
            continue;
        }
        res[0] = subArray[0][i];
        GetSubStr(subArray, 1, 4);
        res[0] = '\0';
    }
    getchar();
    return 0;
}