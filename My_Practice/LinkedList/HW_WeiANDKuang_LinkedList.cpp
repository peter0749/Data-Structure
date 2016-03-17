#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000
struct node
{
    char stdid[max];
    char name[max];
    char addr[max];
    char city[max];
    char phone[max];
    int age;
    struct node *next;
};
typedef struct node NODE;

NODE *push(NODE *tail, char buffer[])
{
    NODE *tobeadd = NULL;
    const char token[] = " \t";
    char *test;
    //printf("counter %d\n",debug++);
    if(tail==NULL)
    {
        tail = (NODE*)malloc(sizeof(NODE));
        tail->next = NULL;
        test = strtok(buffer, token);
        strcpy(tail->stdid,test);
        //puts(tail->stdid);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tail->name,test);
        //puts(tail->name);
        //--------------------------------
        test = strtok(NULL, token);
        tail->age = atoi(test);
        //printf("%d\n", tail->age);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tail->addr,test);
        //puts(tail->addr);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tail->city,test);
        //puts(tail->city);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tail->phone,test);
        //puts(tail->phone);
        //--------------------------------
        return tail;
    }
    else
    {
        tobeadd = (NODE*)malloc(sizeof(NODE));
        tobeadd->next = NULL;
        test = strtok(buffer, token);
        strcpy(tobeadd->stdid,test);
        //puts(tobeadd->stdid);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tobeadd->name,test);
        //puts(tobeadd->name);
        //--------------------------------
        test = strtok(NULL, token);
        tobeadd->age = atoi(test);
        //printf("%d\n", tobeadd->age);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tobeadd->addr,test);
        //puts(tobeadd->addr);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tobeadd->city,test);
        //puts(tobeadd->city);
        //--------------------------------
        test = strtok(NULL, token);
        strcpy(tobeadd->phone,test);
        //puts(tobeadd->phone);
        //--------------------------------
        tail->next = tobeadd;

        return tobeadd;

    }
}

int travel(NODE *entry, const char query[])
{
    if(entry==NULL) return 1;
    if(strcmp(query,entry->stdid)==0)       return 0;
    travel(entry->next, query);
}

int MYcmp(const NODE *ptr1 , const NODE *ptr2, const char *str)
{
    if(strstr(str,"name")!=NULL)
        return strcmp(ptr1->name,ptr2->name);
    if(strstr(str,"studentID")!=NULL)
        return strcmp(ptr1->stdid,ptr2->stdid);
    if(strstr(str,"address")!=NULL)
        return strcmp(ptr1->addr,ptr2->addr);
    if(strstr(str,"city")!=NULL)
        return strcmp(ptr1->city,ptr2->city);
    if(strstr(str,"phone")!=NULL)
        return strcmp(ptr1->phone,ptr2->phone);
    if(strstr(str,"age")!=NULL)
        return ptr1->age - ptr2->age;
}

void destry(NODE *ptr)
{
    if(ptr==NULL)   return;
    destry(ptr->next);
    free(ptr);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *charptr;
    char buffer[max];
    char newadd[max];
    char input;
    int i, j;
    int founded = 0;
    NODE *ptr=NULL;
    NODE *preserve=NULL;
    NODE **SORTPTR;
    NODE *temp;
    int count = 0;
    fp = fopen("context.txt","r");
    NODE *head=NULL, *tail=NULL;
    while(fgets(buffer,max,fp)!=NULL)
    {
        count++;
        if(head==NULL)
        {
            head = push(head, buffer);
            tail = head;
        }
        else
            tail = push(tail, buffer);
    }
    printf("total:%d\n",count);
    while(1)
    {
        printf("Please input command(p i d u f s q):");
        fgets(newadd,max,stdin);
        input = newadd[0];
        newadd[0] = '\0';

        switch(input)
        {
        //printf---------------------------------
        case'p':
            ptr=head;
            while(ptr!=NULL)
            {
                printf("%s\t",ptr->stdid);
                printf("%s\t",ptr->name);
                printf("%d\t",ptr->age);
                printf("%s\t",ptr->addr);
                printf("%s\t",ptr->city);
                printf("%s",ptr->phone);
                ptr=ptr->next;
            }
            break;
        //insert--------------------------------
        case'i':
            fgets(newadd,max,stdin);
            strcpy(buffer,newadd);
            charptr = strtok(buffer,"\t ");
            //puts(charptr);
            if(travel(head,charptr))
            {
                if(head==NULL)
                {
                    head = push(head,newadd);
                    tail = head;
                }
                else
                    tail = push(tail, newadd);
                count++;
            }
            else
            {
                printf("Insert fail! StudentID %s already exists!\n", buffer);
            }
            printf("total:%d\n",count);
            break;
        //delete--------------------------------
        case'd':
            if(count<=0)break;
            founded = 0;
            fgets(newadd,max,stdin);
            strcpy(buffer,newadd);
            charptr = strtok(buffer,"\t\n ");
            //puts(charptr);
            //printf("%d\n",travel(head,charptr));

            ptr = head;
            while(ptr!=NULL)
            {
                if(strcmp(ptr->stdid, charptr)==0)
                {
                    if(ptr==head)
                    {
                        head = head->next;
                    }
                    else if(ptr==tail)
                    {
                        tail = preserve;
                        tail->next = NULL;
                    }
                    else
                    {
                        preserve->next = ptr->next;
                    }
                    ptr->next = NULL;
                    free(ptr);
                    founded = 1;
                    break;
                }
                preserve = ptr;
                ptr = ptr->next;
            }
            ptr=NULL;

            if(founded)
            {
                count--;
            }
            else
            {
                printf("Nothing to delete!\n");
            }
            break;
        //find-----------------------------------
        case'f':
            fgets(newadd, max, stdin);
            strcpy(buffer, newadd);
            charptr = strtok(buffer,"\t\n ");
            ptr = head;
            while(ptr!=NULL)
            {
                if(strstr(ptr->name,charptr)!=NULL)
                {
                    printf("%s\t", ptr->stdid);
                    printf("%s\t", ptr->name);
                    printf("%d\t", ptr->age);
                    printf("%s\t", ptr->addr);
                    printf("%s\t", ptr->city);
                    printf("%s", ptr->phone);
                }
                ptr = ptr->next;
            }
            break;
        //sort----------------------------------
        case's':
            fgets(newadd,max,stdin);
            SORTPTR = (NODE**)malloc(sizeof(NODE*)*count);
            ptr = head;
            i = 0;
            while(ptr!=NULL)
            {
                SORTPTR[i++] = ptr;
                ptr = ptr->next;
            }

            for(i=count-1; i>=1; i--)
            {
                for(j=0; j<i; j++)
                {
                    if(MYcmp(SORTPTR[j],SORTPTR[j+1],newadd)>0)
                    {
                        temp = SORTPTR[j];
                        SORTPTR[j] = SORTPTR[j+1];
                        SORTPTR[j+1] = temp;
                    }
                }
            }
            for(i=0; i<count-1; i++)
            {
                SORTPTR[i]->next = SORTPTR[i+1];
            }
            for(i=0; i<count; i++)
            {
                printf("%s\t",SORTPTR[i]->stdid);
                printf("%s\t",SORTPTR[i]->name);
                printf("%d\t",SORTPTR[i]->age);
                printf("%s\t",SORTPTR[i]->addr);
                printf("%s\t",SORTPTR[i]->city);
                printf("%s",SORTPTR[i]->phone);
            }
            head = SORTPTR[0];
            tail = SORTPTR[count-1];
            tail->next = NULL;
            free(SORTPTR);
            SORTPTR = NULL;
            break;
        //quit---------------------------------
        case'q':
            puts("exit");
            return 0;


        }
    }
    destry(head);
    tail = head = NULL;

    return 0;
}
