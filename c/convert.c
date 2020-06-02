#include <stdio.h>

/* 思路：
如果有进位，则清零进位加一，若都要进位，则创建新数组
*/
char * convert(char * s, int numRows){
    int len = strlen(s);
    if (len <= 1) {
        return s;
    }
    char **t = (char **)malloc(sizeof(char *) * numRows);
    int i, j;
    for (i = 0; i < numRows; i++) {
        t[i] = (char *)malloc(sizeof(char) * 256);
        memset(t[i], 0, sizeof(char)*256);
    }
    i = 0;
    j = 0;
    while (*s!= '\0') {
        while (*s!='\0' && i < numRows) {
            t[i][j] = *s;
            i++;
            s++;
        }
        if (*s!='\0') {
            i -= 2;
            j++;
        }
        while (*s!='\0' && i >= 0) {
            t[i][j] = *s;
            s++;
            i--;
            j++;
        }
        if (*s!='\0') {
            j--;
            i += 2;
        }
    }
    char *res = (char *)malloc(sizeof(char) + 1);
    res[len] = '\0';
    int o = 0;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < 256; j++) {
            if (t[i][j] != 0) {
                res[o++] = t[i][j];
            }
        } 
    }
    return res;
}

int main()
{
    char *s = "PAYPALISHIRING";
    int rowNum = 3;
    int *res = NULL;
    res = convert(s, rowNum);
    printf("%s", res);
    return 0;
}
