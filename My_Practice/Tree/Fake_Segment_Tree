#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int ori[MAX] = {9,3,4,0,-3,100,1,10000,-10000};/*9 records*/
int seg[10000];

int cmp(const void *a, const *b)
{
    return *(int*)a-*(int*)b;
}

void init(int L, int R, int lev, int ori[], int seg[])
{
    int M = (R+L)>>1;
    if(R==L)
    {
        seg[lev]=ori[L];
        //printf("%d: %d\n",lev,seg[lev]);
        return;
    }
    init(L,M,lev<<1,ori,seg);
    init(M+1,R,(lev<<1)|1,ori,seg);
    seg[lev] = seg[lev<<1]>seg[(lev<<1)|1]?seg[lev<<1]:seg[(lev<<1)|1];
}

int query(int L, int R, int qL, int qR, int flag, int seg[])
{
    int temp1,temp2;
    int M = (L+R)>>1;
    //if(L>R)return -999;
    if(L>qR || R<qL) return -999;
    if(qL<=L&&qR>=R) return seg[flag];
    return (temp1=query(L,M,qL,qR,flag<<1,seg))>(temp2=query(M+1,R,qL,qR,(flag<<1)|1,seg))?temp1:temp2;
}

void modify(int L, int R, int m, int n, int flag, int seg[])
{
    int M = (L+R)>>1;
    if(L==R)
    {
        if(seg[flag]==m)
            seg[flag]=n;
        return;
    }
    modify(L,M,m,n,flag<<1,seg);
    modify(M+1,R,m,n,(flag<<1)|1,seg);
    seg[flag] = seg[flag<<1]>seg[(flag<<1)|1]?seg[flag<<1]:seg[(flag<<1)|1];
}

int main(void)
{
    int i;
    qsort(ori,9,sizeof(int),cmp);
    init(0,8,1,ori,seg);
    for(i=1;i<18;i++)
        printf("%d: %d\n",i,seg[i]);
    printf("%d\n",query(0,8,2,3,1,seg));
    modify(0,8,-3,200000,1,seg);
    printf("%d\n",query(0,8,0,8,1,seg));
    return 0;
}
