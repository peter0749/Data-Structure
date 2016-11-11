#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODE 20

typedef int _PAIR_TYPE;
typedef struct{
    _PAIR_TYPE first, second;
}_PAIR;

typedef _PAIR VEC_TYPE;
typedef struct{
    size_t usage, full;
    VEC_TYPE *arr;
}_VECTOR;

void _init_vec(_VECTOR *v){
    v->usage = 0;
    v->full = 5;
    v->arr = (VEC_TYPE*)malloc(v->full * sizeof(VEC_TYPE));
}
void _push_back(_VECTOR *v, VEC_TYPE val){
    VEC_TYPE *newptr=NULL;
    int i;
    if( v->usage==v->full ){
        v->full<<=1;
        newptr = (VEC_TYPE*)malloc(v->full*sizeof(VEC_TYPE));
        memcpy(newptr,v->arr,v->usage*sizeof(VEC_TYPE));
        free(v->arr);
        v->arr = newptr;
    }
    v->arr[v->usage++] = val;
}
void _des_vec(_VECTOR *v){
    free(v->arr);
    v->arr = NULL;
    v->usage = v->full = 0;
}

_VECTOR graph[MAX_NODE];
int edges=0;

int main(void){
    int N, u, v, w, S, T, i, j;
    _PAIR p;
    char input[1000];
    fgets(input,sizeof(input),stdin);
    N = atoi(input);
    while(N--){
        for(i=0; i<MAX_NODE; ++i) _init_vec(&graph[i]);
        fgets(input,sizeof(input),stdin);
        edges = atoi(input);
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%d %d", &S, &T);
        while(1){
            fgets(input,sizeof(input),stdin);
            if(atoi(input)==-1)break;
            sscanf(input,"%d %d %d", &u, &v, &w);
            p.first = v;p.second = w;
            _push_back(&graph[u], p);
        }
        for(i=0; i<MAX_NODE; ++i){
            for(j=0; j<graph[i].usage; ++j){
                printf("%d %d %d\n", i, graph[i].arr[j].first, graph[i].arr[j].second);
            }
        }
        for(i=0; i<MAX_NODE; ++i) _des_vec(&graph[i]);
    }
    return 0;
}
