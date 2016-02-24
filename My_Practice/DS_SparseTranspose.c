#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int row;
    int col;
    int val;
}Matrix;

void TransposeAtB(Matrix *A, Matrix *B)
{
    int currentB = 1;
    int i, j;

    B[0].row = A[0].col;
    B[0].col = A[0].row;
    B[0].val = A[0].val;

    if( A[0].val == 0)   return;

    for(i=0;i < A[0].col;i++)
    {
        for(j=1;j <= A[0].val;j++)
        {
            if(A[j].col==i)
            {
                B[currentB].row = A[j].col;
                B[currentB].col = A[j].row;
                B[currentB].val = A[j].val;
                currentB++;
            }
        }
    }

}

int main(void)
{
    int i;
    Matrix A[MAX] = {{4,5,6},{0,1,1},{0,4,2},{1,3,3},{2,0,4},{2,2,5},{3,4,6}};
    Matrix B[MAX];

    TransposeAtB(&A, &B);

    printf("%d\n",B[0].val);

    for(i=0;i<=A[0].val;i++)
    {
        printf("\t%d",A[i].row);
    }
    puts("");
    for(i=0;i<=A[0].val;i++)
    {
        printf("\t%d",A[i].col);
    }
    puts("");
    for(i=0;i<=A[0].val;i++)
    {
        printf("\t%d",A[i].val);
    }
    puts("\n");

    for(i=0;i<=B[0].val;i++)
    {
        printf("\t%d",B[i].row);
    }
    puts("");
    for(i=0;i<=B[0].val;i++)
    {
        printf("\t%d",B[i].col);
    }
    puts("");
    for(i=0;i<=B[0].val;i++)
    {
        printf("\t%d",B[i].val);
    }
    puts("");

    return 0;
}
