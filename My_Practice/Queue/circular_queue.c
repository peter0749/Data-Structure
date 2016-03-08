#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void)
{
    int rare=0, front=0;
    int que[MAX];
    int op, key;
    int term;
    int newrare;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            newrare = (rare+1)%MAX;
            if(newrare==front)
            {
                puts("Full!");
                break;
            }
            scanf("%d",&key);
            que[newrare] = key;
            rare = newrare;
            break;
        case 2:
            if(rare==front)
            {
                puts("Empty!");
                break;
            }
            newrare = (front+1)%MAX;
            printf("%d\n",que[newrare]);
            front = newrare;
            break;
        }
    }
    return 0;
}
