#include <stdio.h>
#include <stdlib.h>

/* 思路：
创建map存储第几列需要清零，然后用行指针存储循环的行，
如果某行元素找到为0，则记录他的列信息到map中，同时循环结束该行时清零该行。
*/
char * longestCommonPrefix(char strs[][2], int strsSize){
    if (strsSize == 0) {
        return "";
    }
    int i, j;
    int count = 0;
    int flag = 0;
    for (i = 0; i < strlen(*strs); i++) {
        for (j = 0; j < strsSize - 1; j++) {
            if (i >= strlen(strs[j + 1])) {
                break;
            }
            if (strs[j][i] != strs[j + 1][i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        count++;
    }
    if (count == 0) {
        return "";
    }
    char *res = (char *)malloc(count + 1);
    for (i = 0; i < count; i++) {
        res[i] = strs[0][i];
    }
    res[i] = '\0';
    return res;
}

void main()
{
    char a[2][2] = {"aa", "a"};
    longestCommonPrefix(a, 2);
}