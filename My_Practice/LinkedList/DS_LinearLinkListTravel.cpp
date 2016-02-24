#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} LineList;

LineList *push(LineList *tail)
{
    static int val=0;
    LineList *tobeadd = NULL;
    if(tail==NULL)//If the node: "tail" is null, initialize it;
    {
        tail = (LineList*)malloc(sizeof(LineList));
        tail->val = val;
        tail->next = tail;
        val++;
        return tail;
    }
    tobeadd = (LineList*)malloc(sizeof(LineList));
    tobeadd->val = val;
    tobeadd->next = tail->next;
    tail->next = tobeadd;
    val++;
    return tobeadd;
}

void travel(LineList *head)
{
    LineList *ptr = head;
    do
    {
        printf("node: %d\n",ptr->val);
        ptr = ptr->next;
    }
    while(ptr!=head);
}

int main(void)
{
    LineList *head = NULL;
    int i;
    for(i=0; i<10; i++)
    {
        head = push(head);
    }
    for(i=0; i<11; i++)
    {
        head = head->next;
        travel(head);
        printf("\n");
    }

    free(head);

    return 0;
}
