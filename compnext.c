#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int large(int a, int b) {
    if (a > b) {
        return a;
    }
    else return b;
}
void compnext(char* pat, int* next, int patlen) {
    int pat_index = 1;
    int cmp_index;
    next[0] = 0;
    while(pat_index < patlen) {
        cmp_index = 0;
        next[pat_index] = 0;
        while(cmp_index <=  pat_index) {
            int i;
            for(i=0; i < cmp_index; i++) {
                if(pat[i] != pat[pat_index-cmp_index+i]) break;
            }
            if(pat[cmp_index] != pat[pat_index] && i == cmp_index) {
                next[pat_index] = large(next[pat_index], i+1);
            }
            cmp_index += 1;
        }
        pat_index += 1;
    }
}
