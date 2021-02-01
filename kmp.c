#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
extern bool isVerbose;
extern int Ncmp;
bool cmp(char, char);
void compnext(char*,int*, int);
int kmp(char* text, unsigned int textlen, char* pat, unsigned int patlen){
    int i=0;
    int j=0;
    int next[patlen];
    compnext(pat,next,patlen);
    printf("next: ");
    for(i;i<patlen;i++){
        printf("%d ",next[i]);
    }
    printf("\n");
    i = 0;
    while(j < textlen-1){
        cmp(pat[i],text[j]);
        while(i>=0 && pat[i] != text[j]){
            i = next[i]-1;
            if(i>=0) cmp(pat[i],text[j]);
        }
        if(i != patlen-1){
            i++;
            j++;
        }
        else{
            return j-patlen+1; //照合成功
        }
    }
    return -1; //照合失敗
}

