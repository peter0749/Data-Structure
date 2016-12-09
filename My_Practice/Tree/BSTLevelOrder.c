#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#define MAXN 1000000
#define P 1000000009

typedef struct node{
    int val;
    struct node *lc, *rc;
}TREE;

TREE *_initTree(TREE *root){
    root = (TREE*)malloc(sizeof(TREE));
    root->val = INT_MIN;
    root->lc = root->rc = NULL;
    return root;
}

void _push(TREE *root, int val){
    if(root==NULL||val==INT_MIN) return;
    if(root->val==INT_MIN){
        root->val = val;
        return;
    }
    if(val>root->val){
        if(!root->rc) root->rc = _initTree(root->rc);
        _push(root->rc,val);
    }else{
        if(!root->lc) root->lc = _initTree(root->lc);
        _push(root->lc,val);
    }
}

void nonRInorder(TREE *root, int *array, int maxDEPTH){
    int top=-1;
    TREE **NodeSTK = (TREE**)malloc(sizeof(TREE*)*maxDEPTH);
    TREE *ptr=root, *old;
    while(1){
        for(;ptr;ptr=ptr->lc) NodeSTK[++top] = ptr;
        if(top==-1)return;
        ptr = NodeSTK[top--];
        //printf("%d\n",ptr->val);
        *(array++) = ptr->val;
        old = ptr;
        ptr = ptr->rc;
        free(old);
    }
    free(NodeSTK);
}

void LevelOrder(TREE *root, int *array, int maxLENGTH){
	int front=-1, rear=-1;
	TREE **NodeQue = (TREE**)malloc(sizeof(TREE*)*maxLENGTH);
	TREE *ptr=root, *old;
	if(!ptr) return;
	NodeQue[++rear] = ptr;
	while(front!=rear){
		ptr = NodeQue[++front];
		if(ptr){
			*(array++) = ptr->val;
			//if(ptr->rc) NodeQue[++rear] = ptr->rc;
			if(ptr->lc){
                NodeQue[++rear] = ptr->lc;
                printf("l%d ", ptr->lc->val);
			}
			printf("m%d", ptr->val);
			if(ptr->rc){
                NodeQue[++rear] = ptr->rc;
                printf(" r%d", ptr->rc->val);
			}
			puts("");
		}
	}
}

unsigned int hashing(char const *ptr){
    unsigned int prime=5371u;
    while(*ptr){
        prime = ((((prime<<5)%P)^prime)+*ptr)%P;
        ptr++;
    }
    return prime;
}

TREE T={INT_MIN, NULL, NULL};
int result[MAXN];

int main(void){
    int num, i, count=0;
    unsigned int h;
    //srand(h=hashing("CCU_ChiYuMi"));
    //for(i=0; i<6; ++i) _push(&T, rand());
    while(scanf("%d",&num)!=EOF){
		_push(&T, num);
		++count;
	}
	LevelOrder(&T, result,MAXN);
	for(i=0; i<count; ++i) printf("%d\n",result[i]);
    nonRInorder(&T,result,MAXN);
    for(i=1; i<count; ++i) assert(result[i-1]<=result[i]);
    //printf("hash: %u\n", h);
    return 0;
}
