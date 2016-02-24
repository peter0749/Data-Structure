#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEAD -(0xeeee)

typedef struct node
{
    int val;
    struct node *next;
}LinkedList;

int push(int val, LinkedList *top)
{
    LinkedList *newnode=NULL;
    newnode = (LinkedList*)malloc(sizeof(LinkedList));
    if(newnode==NULL)   return -1;
    newnode->val = val;
    if(top->next==NULL)
    {
        newnode->next = NULL;
        top->next = newnode;
        return 0;
    }
    newnode->next = top->next;
    top->next = newnode;
    return 0;
}

int pop(LinkedList *top)
{
    int result;
    LinkedList *ptr;
    if(top->next==NULL)
    {
        printf("The stack is empty!\n");
        return DEAD;
    }
    result = top->next->val;
    ptr = top->next->next;
    free(top->next);
    top->next = ptr;
    return result;
}

int main(void)
{
    int n;
    LinkedList *head = NULL;
    char op[30];
    char temp[1000];
    int result;
    head = (LinkedList*)malloc(sizeof(LinkedList));
    if(head==NULL)  return -1;
    head->val = DEAD;
    head->next = NULL;
    while((gets(temp))!=NULL)
    {
        sscanf(temp,"%s %d",op,&n);
        if(strcmp(op,"push")==0)
        {
            push(n,head);
        }
        else if(strcmp(op,"pop")==0)
        {
            result = pop(head);
            if(result==DEAD)
            {
                printf("ERROR CODE: Y%X\n",-result);
            }
            else
                printf("Top: %d\n",result);
        }
    }
    return 0;
}
