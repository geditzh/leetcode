#include <stdio.h>

/* 思路：
注意4个边界问题，当还没遍历到对角线，往右上移动一格，当遍历到
对角线时，往下移动一格
*/
int isPalindDrome(char *s, int left, int right) 
{
    int len = 0;
    while (left > 0 && right < strlen(s)) {
        if (s[left] != s[right]) {
            break;
        }
        left--;
        right--;
    }
    return right - left - 1; 
}
char * longestPalindrome(char * s){
    if (s == NULL || strlen(s)) {
        return "";
    }
    int left, right;
    int len = strlen(s);
    int maxSubLen = 0;
    int start = 0;
    if (len & 0x01) {
        left = 0;
        right = 0;
    } else {
        left = 0;
        right = 1;
    }

    int tempLen = 0;
    while (left < len && right < len) {
        tempLen = isPalindDrome(s, left, right);
        if (tempLen > maxSubLen) {
            maxSubLen = tempLen;
            start = left;
        }
        left++;
        right++;
    }
    char *res = (char *)malloc(maxSubLen + 1);
    memset(res, 0, maxSubLen + 1);
    memcpy(res, s + start, maxSubLen);
    return res;
}

int main()
{
    char src[6] = "babad";
    char * = longestPalindrome(src);
    printf("%d", len);
}
