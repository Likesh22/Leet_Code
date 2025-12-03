//Given a string s, return the longest palindromic substring in s.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) {
        char *empty = (char *)malloc(1);
        empty[0] = '\0';
        return empty;
    }
    int start = 0;
    int maxLen = 1;
    for (int i = 0; i < n; i++) {
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                start = left;
            }
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
                start = left;
            }
            left--;
            right++;
        }
    }
    char *res = (char *)malloc(maxLen + 1);
    strncpy(res, s + start, maxLen);
    res[maxLen] = '\0';

    return res;
}
