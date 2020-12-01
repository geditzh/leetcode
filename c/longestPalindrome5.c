#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsPalindrome(char *s, int left, int right, int *tempStart)
{
    int len = strlen(s);
    while (left >= 0 && right < len) {
        if (s[left] != s[right]) {
            break;
        }
        left--;
        right++;
    }
    *tempStart = left + 1;
    return right - left - 1;
}

char * longestPalindrome(char * s)
{
    if (strlen(s) == 0 || s == NULL) {
        return "";
    }
    int start = 0;
    int len = -1;

    int tempLen, tempStart, i;
    for (i = 0; i < strlen(s); i++) {
        tempLen = IsPalindrome(s, i, i, &tempStart);
        if (tempLen > len) {
            start = tempStart;
            len = tempLen;
        }

        tempLen = IsPalindrome(s, i, i + 1, &tempStart);
        if (tempLen > len) {
            start = tempStart;
            len = tempLen;
        }
    }
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    memset(res, 0, sizeof(char) * (len + 1));
    memcpy(res, s + start, len);
    return res;
}