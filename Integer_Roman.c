#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num){
    int values[]={1000, 900, 500, 400, 100,  90,  50,  40,  10,   9,   5,   4,   1};
    char* symbols[]={"M",  "CM","D", "CD","C", "XC","L", "XL","X", "IX","V", "IV","I"};
    char* result=(char*)malloc(20 * sizeof(char));
    int pos=0;
    for(int i = 0; i < 13 && num > 0; i++) {
        while(num >= values[i]) {
            int len = 0;
            while(symbols[i][len] != '\0') {
                result[pos++] = symbols[i][len++];
            }
            num -= values[i];
    }   }
    result[pos] = '\0';
    return result;
}
