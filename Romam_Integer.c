#include<stdio.h>
int romanToInt(char * s){
    int value[256] = {0};
    value['I'] = 1;
    value['V'] = 5;
    value['X'] = 10;
    value['L'] = 50;
    value['C'] = 100;
    value['D'] = 500;
    value['M'] = 1000;
    int total = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int curr = value[(int)s[i]];
        int next = value[(int)s[i + 1]];
        if (next > curr)
            total -= curr;
        else
            total += curr;
    }
    return total;
}
