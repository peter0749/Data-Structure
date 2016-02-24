#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}linked_list;

linked_list *push(int val, linked_list *tail)
{
    linked_list *tobeadd;
    tobeadd = (linked_list*)malloc(sizeof(linked_list));
    tobeadd->val = val;
    tobeadd->next = NULL;
    tail->next = tobeadd;
    return  tobeadd;
}

linked_list *LLreverse(linked_list *head)
{
    linked_list *ptr = head;
    if(ptr->next==NULL)    return ptr;
    LLreverse(ptr->next)->next = ptr;
    return ptr;
}

void del_node(linked_list *ptr)
{
    if(ptr->next!=NULL) del_node(ptr->next);
    free(ptr);
}

int main(void)
{
    int val;
    linked_list *head, *tail, *ptr;
    head = (linked_list*)malloc(sizeof(linked_list));
    head->next = NULL;
    head->val = 0;
    tail = head;
    while(scanf("%d",&val)!=EOF)
    {
        tail = push(val,tail);
    }
    ptr = head->next;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->val);
        ptr = ptr->next;
    }
    //system("pause");
    ptr = tail;
    tail = LLreverse(head->next);
    head->next = ptr;
    tail->next = NULL;

    while(ptr!=NULL)
    {
        printf("%d\n",ptr->val);
        ptr = ptr->next;
        //system("pause");
    }

    del_node(head);
    head = NULL;

    printf("%d\n",head);

    return 0;
}
