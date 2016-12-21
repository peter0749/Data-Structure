#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRL 10000
int failure[STRL];
char pattern[STRL];
char tstring[STRL];
int Pos[STRL];

int MorrisPratt(char *t, char *p, int *stk){
    int i, j, top=0;
    int tlen = strlen(t);
    int plen = strlen(p);
    if(plen > tlen) return 0;

    for(i=1, j=failure[0]=-1; i<plen; ++i){
        while(j>=0 && p[j+1]!=p[i])
            j = failure[j];
        if(p[j+1]==p[i]) ++j;
        failure[i] = j;
    }

    for(i=0, j=-1; i<tlen; ++i){
        while(j>=0 && p[j+1]!=t[i])
            j = failure[j];

        if(p[j+1]==t[i]) ++j;

        if(j==plen-1){
            //printf("at: %d\n", i-plen+1);
            j=failure[j];//Optional
            stk[top++] = i-plen+1;
        }
    }
    return top;
}

int main(void){
    int succCount, i;
    while(scanf("%s %s", tstring, pattern)!=EOF){
        succCount = MorrisPratt(tstring, pattern, Pos);
        printf("Total: %d\n", succCount);
        for(i=0; i<succCount; ++i){
            printf("at: %d\n", Pos[i]);
        }
    }
    return 0;
}
