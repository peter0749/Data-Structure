#include <iostream>
#include <iomanip>
#include <string>
#define MAX 3000

using namespace std;

typedef struct node
{
    int key;
    struct node *lc;
    struct node *rc;
} btree;

int first;

void push(btree *ptr, const int key)
{
    if(key > ptr->key)/*key > rootkey, move to right subtree.*/
    {
        if(ptr->rc!=NULL)
            push(ptr->rc, key);
        else
        {
            ptr->rc = new btree;
            ptr->rc->lc = ptr->rc->rc = NULL;
            ptr->rc->key = key;
        }
    }
    else
    {
        if(ptr->lc!=NULL)
            push(ptr->lc, key);
        else
        {
            ptr->lc = new btree;
            ptr->lc->lc = ptr->lc->rc = NULL;
            ptr->lc->key = key;
        }
    }
}

void travel(btree *ptr)
{
    if(ptr==NULL)   return;
    travel(ptr->lc);
    if(first)
    {
        cout<<ptr->key;
        first = 0;
    }
    else
        cout<<' '<<ptr->key;
    travel(ptr->rc);
    //cout<<ptr->key<<'\n';
    delete ptr;
}

int main(void)
{
    int keyin;
    int term;
    btree *rootp = NULL;
    while(cin>>term)
    {
        if(term<=0) continue;
        while(term--)
        {
            cin>>keyin;
            if(rootp==NULL)
            {
                rootp = new btree;
                rootp->lc = rootp->rc = NULL;
                rootp->key = keyin;
            }
            else
                push(rootp,keyin);
            //travel(rootp);
        }
        first = 1;
        travel(rootp);
        rootp = NULL;
        cout<<'\n';
    }
    //travel(rootp);
    return 0;
}
