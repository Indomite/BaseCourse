#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
}bintnode;
typedef bintnode *bintree;

bintree creatFulltree(int node[],int low int,int high)
{
    int mid;
    bintree s;
    if(low <= high){
        mid = (low+high)/2;
        s = (bintree)malloc(sizeof(bintree));
        s->data = node[mid];
        s->lchild = creatFulltree(node,low,mid-1);
        s->rchild = creatFulltree(node,mid-1,high);
        return s;
    }
    else
        return NULL;
}
