/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) {
        char *res = (char *)malloc(len + 1);
        strcpy(res, s);
        return res;
    }
    int cycleLen = 2 * numRows - 2;
    char *res = (char *)malloc(len + 1);
    int idx = 0;
    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycleLen) {
            res[idx++] = s[j];
            int diag = j + cycleLen - 2 * row;
            if (row != 0 && row != numRows - 1 && diag < len) {
                res[idx++] = s[diag];
            }
        }
    }
    res[idx] = '\0';
    return res;
}
