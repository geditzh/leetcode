#include <stdio.h>

/* 思路：
利用hash函数计算得到字符串是否相等
*/
int strStr(char * haystack, char * needle){
    int besa = 1000000;
    if (haystack == NULL || needle == NULL) {
        return -1;
    }

    int m = strlen(needle);
    if (m == 0) {
        return 0;
    }

    int power = 1;
    int i;
    for (i = 0; i < m - 1; i++) {
        power = (power * 31) % besa;
    }

    int targetCode = 0;
    for (i = 0; i < m; i++) {
        targetCode = (targetCode * 31 + needle[i]) % besa;
    }

    int hashCode = 0;
    for (i = 0; i < strlen(haystack); i++) {
        hashCode = (hashCode * 31 + haystack[i]) % besa;
        
        if (i < m - 1) {
            continue;
        }

        if (hashCode == targetCode) {
            int flag = 1;
            int j;
            for (j = 0; j < strlen(needle); j++) {
                if (haystack[i - m + 1 + j] == needle[j]) {
                    continue;
                }
                flag = 0;
            }
            if (flag) {
                return i - m + 1;
            }
        }

        hashCode = hashCode - (haystack[i - m + 1] * power) % besa;
        if (hashCode < 0) {
            hashCode += besa;
        } 
    }
    return -1;
}


int main()
{
    char *a = "hello";
    char *b = "ll";
    strStr(a, b);
}
