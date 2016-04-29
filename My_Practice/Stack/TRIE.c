#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 256
typedef struct node
{
    struct node *l[MAX];
    int times;
}TRIE;

char buffer[500000];
int buffer_top = 0;

void push(TRIE *head, char *input)
{
    int i;
    TRIE *ptr=head;
    while( input!=NULL && *input!='\0' )
    {
        if( !ptr->l[*input] )
        {
            ptr->l[*input] = (TRIE*)malloc(sizeof(TRIE));
            ptr->l[*input]->times = 0;
            for(i=0;i<MAX;i++)
                ptr->l[*input]->l[i]=NULL;
        }
        ptr = ptr->l[*input];
        input++;
    }
    ptr->times++;
}

void dfs( TRIE *ptr , int lev)
{
    int i;
    for(i=0; i<MAX; i++)
    {
        if( ptr->l[i] )
        {
            buffer[lev] = i;
            //putchar(i);
            if(ptr->l[i]->times)
            {
                //puts("here");
                buffer[lev+1] = '\0';
                printf("%d ",ptr->l[i]->times);
                puts(buffer);
            }
            dfs( ptr->l[i] , lev+1 );
        }
    }
}

void del( TRIE *ptr)
{
    int i;
    for(i=0; i<MAX; i++)
    {
        if( ptr->l[i] )
        {
            del(ptr->l[i]);
            ptr->l[i]=NULL;
        }
    }
    free(ptr);
}

int main(void)
{
    int i;
    char temp[50000];
    TRIE head;
    head.times = 0;
    buffer_top = 0;
    for(i=0; i<MAX; i++)head.l[i]=NULL;
    while((fgets(temp,MAX,stdin))!=NULL)
    {
        sscanf(temp,"%s",temp);
        push(&head,temp);
        dfs(&head, 0);
    }
    puts("Final: ");
    dfs( &head, 0 );
    for(i=0; i<MAX; i++){if(head.l[i])del(head.l[i]);head.l[i]=NULL;}
    getchar();
    return 0;
}
