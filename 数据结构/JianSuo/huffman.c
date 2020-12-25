#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *lchild,*rchild,*next;
}hufnode;
typedef hufnod* linkhuf;

linkhuf insert(linkhuf root,linkhuf s)
{
    linkhuf p1,p2;
    if(root==NULL)
        root = s;
    else{
        p1 = NULL;
        p2 = NULL;
        while(p2 && p2_>data < s->data){
            p1 = p2;
            p2 = p2->next;
        }
        s->next = p2;
        if(p1 = NULL)
            root = s;
        else
            p1->next = s;
    }
    return root;
}

void creathuffman(linkhuf* root)
{
    linkhuf s,rl,rr;
    while(*root && (*root)->next){
        rl = *root;
        rr = (*root)->next;
        *root = rr->next;
        s=(linkhuf)malloc(sizeof(hufnode));
        s->next = NULL;
        s->data = rl->data + rr->data;
        s->lchild = rl;
        s->rchild = rr;
        rl->next = rr->next = NULL;
        *root = insert(*root,s);
    }
}
