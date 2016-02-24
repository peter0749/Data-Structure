#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

/*
*Add two polynomials by merge two structs:
*Step 1: Initialize three structs of Polynomial by init()
*Step 2: Enter two Polynomials' exponential and coefficient
*Step 3: Add two Polynomials by calling addPoly()
*Step 4: Printout the result
*Step 5: The program is finished.
*/

typedef struct
{
    int exp;
    int coef;
}NonZeroTerm;

typedef struct
{
    int count;//Number of the Polynomial's exp & coefficient
    NonZeroTerm terms[MAXSIZE];
}Polynomial;

int cmp(const int a, const int b)
{
    return (a==b? 0:(a>b?1:-1));
}

void init(Polynomial *poly)
{
    poly->count = 0;
}

void addterm(Polynomial *poly, const int coef, const int exp)
{
    poly->terms[poly->count].exp = exp;
    poly->terms[poly->count].coef = coef;
    poly->count++;
}

void addPoly(Polynomial *A, Polynomial *B, Polynomial *C)   /*C = A+B*/
{
/*
*Add A & B into C:
*Step 1: While A or B is not empty, merge A and B into C
*Step 2: If A is not empty or B is not empty, merge the one into C
*/
    int currentA = 0, currentB = 0;
    while(currentA<A->count && currentB<B->count)
    {
        switch(cmp(A->terms[currentA].exp, B->terms[currentB].exp))
        {
        case 0:
            addterm(C, A->terms[currentA].coef + B->terms[currentB].coef, A->terms[currentA].exp);
            currentA++;
            currentB++;
            break;
        case 1:
            addterm(C, A->terms[currentA].coef, A->terms[currentA].exp);
            currentA++;
            break;
        case -1:
            addterm(C, B->terms[currentB].coef, B->terms[currentB].exp);
            currentB++;
            break;
        }
    }
    while(currentA < A->count)
    {
        addterm(C, A->terms[currentA].coef, A->terms[currentA].exp);
            currentA++;
    }
    while(currentB < B->count)
    {
        addterm(C, B->terms[currentB].coef, B->terms[currentB].exp);
            currentB++;
    }
}

int main(void)
{
    int i;
    Polynomial A,B,C;
    init(&A);
    init(&B);
    init(&C);

    printf("Format: coef exp\n");

    printf("Term of A: ");
    scanf("%d", &(A.count));
    for(i=A.count-1;i>=0;i--)
    {
        printf("term %d:\n",i+1);
        scanf("%d %d", &A.terms[i].coef, &A.terms[i].exp);
    }

    printf("Term of B: ");
    scanf("%d", &(B.count));
    for(i=B.count-1;i>=0;i--)
    {
        printf("term %d:\n",i+1);
        scanf("%d %d", &B.terms[i].coef, &B.terms[i].exp);
    }

    addPoly(&A,&B,&C);

    printf("A+B =");

    if(C.count>0)
    {
        if(C.terms[C.count-1].coef>=0)
            printf(" %dX^%d", C.terms[C.count-1].coef, C.terms[C.count-1].exp);
        else
            printf(" %+dX^%d", C.terms[C.count-1].coef, C.terms[C.count-1].exp);
    }

    for(i=C.count-2;i>=0;i--)
    {
        printf(" %+dX^%d", C.terms[i].coef, C.terms[i].exp);
    }
    printf("\n");

    return 0;
}
