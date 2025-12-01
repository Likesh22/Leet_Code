// Given a string s, find the length of the longest substring without duplicate characters.

#include<stdio.h>
int lengthOfLongestSubstring(char * s){

    int last[256];
    for (int i = 0; i < 256; ++i) last[i] = -1;

    int maxlen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)s[i];

        if (last[c] >= start) {
            start = last[c] + 1;
        }

        last[c] = i;

        int len = i - start + 1;
        if (len > maxlen) maxlen = len;
    }

    return maxlen;
}
