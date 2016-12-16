#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAXN 100000

typedef int HDATA_T;
typedef struct{
    int rear, full;
    HDATA_T *data;
    int (*comp)(const void *a, const void*b);
}HEAP_t;

void memswap(char *src, char *tar, size_t len){
    char *temp = (char*)malloc(len);
    memcpy(temp,src,len);
    memcpy(src,tar,len);
    memcpy(tar,temp,len);
}
int init_HEAP_t(HEAP_t *ptr, int size, int (*comp)(const void *a, const void*b)){
    if(!ptr->data){
        ptr->data = (HDATA_T*)malloc(sizeof(HDATA_T)*size);
        ptr->full = size;
        ptr->comp = comp;
        return ptr->data?size:-1;
    }
    return -2;
}

void des_HEAP_T(HEAP_t *h){
    free(h->data);
    h->data = NULL;
    h->rear = h->full = 0;
}

void pushHEAP(int key, HEAP_t *h){
    int ch, pa;
    if(h->rear==h->full){
        fprintf(stderr,"HEAP Full!");
        exit(-1);
    }
    ch=h->rear; pa=(ch-1)>>1;
    h->data[h->rear++] = key;
    while( ch>0 && h->comp(&h->data[ch], &h->data[pa])){ //child < parent
        memswap(&h->data[ch], &h->data[pa], sizeof(HDATA_T));// swap it
        ch=pa;
        pa=(ch-1)>>1;
    }
}

HDATA_T topHEAP(HEAP_t *h){
    if(!h||!h->data) exit(-1);
    return h->data[0];
}
HDATA_T popHEAP(HEAP_t *h){
    if(!h||!h->data||h->rear==0) exit(-1);
    HDATA_T output = h->data[0];
    h->data[0] = h->data[--h->rear];
    int pos=0, ch;
    while((ch = (pos<<1)+1) < h->rear){
        if( ch+1<h->rear && h->comp(&h->data[ch+1], &h->data[ch]) ) ++ch;
        if( h->comp(&h->data[ch], &h->data[pos])){
            memswap(&h->data[ch],&h->data[pos], sizeof(h->data[ch]));
            pos = ch;
        }else break;
    }
    return output;
}
char emptyHEAP(HEAP_t *h){
    return (!h->data || h->rear==0)? 1:0;
}

int cmp(const void *a, const void *b){
    HDATA_T *c=(HDATA_T*)a, *d=(HDATA_T*)b;
    return *c < *d;
}
