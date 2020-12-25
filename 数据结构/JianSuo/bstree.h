#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype key;
    struct node *lchild,*rchild;
}bsnode;
typedef bsnode *bstree;

void bssearch1(bstree t,datatype key,bstree *f,bstree *s)
{
    *f = NULL;      //用于返回待查找结点x的父结点的地址
    *p = t;     //用于返回待查找结点在二叉树中的地址
    while(*p){
        if(x==(*p)->key)
            return;
        *f = *p;
        *p = (x<(*p)->key)? (*p)->lchild : (*p)->rchild;
    }
    return;
}

bstree bssearch2(bstree t,datatype x)
{
    if(t == NULL || x == t->key)
        return t;
    if(x < t->key)
        return bssearch2(t->lchild.x);
    else
        return bssearch2(t->rchild.x);
}

void InsertBstree(bstree *t,datatype x)
{
    bstree f = NULL,p;
    p = *t;
    while(p){
        if(x == p->key)
            return;
        f=p;
        p = (x<p->key)? p->lchild:p->rchild;
    }
    p = (bstree)malloc(sizeof(bsnode));
    p->key = x;
    p->lchild = p->rchild=NULL;
    if(*t==NULL)
        *t = p;
    else if(x < f->key)
        f->lchild = p;
    else
        f->rchild = p;
}

bstree CreatBstree(void)
{
    bstree t=NULL;
    datatype key;
    printf("请输入一组数，以-1结束：");
    scanf("%d",&key);
    while(key != -1){
        InsertBstree(&t,key);
        scanf("%d",&key);
    }
    return t;
}

bstree DelBstree(bstree t,datatype x)
{
    bstree p,q,child;
    bssearch1(t,x,&p,&q);
    if(q){
        if(q->lchild == NULL && q->rchild == NULL){
            if(p){
                if(p->lchild == q)
                    p->lchild = NULL;
                else
                    p->rchild = NULL;
            }else
                t = NULL;
                free(q);
        }
        else if(q->rchild == NULL){
            if(p){
                if(p->lchild == q)
                    p->lchild = q->lchild;
                else
                    p->rchild = q->lchild;
            }else
                t = q->lchild;
            free(p);
        }
        else if(q->lchild == NULL){
            if(p){
                if(p->lchild == q)
                    p->lchild = q->lchild;
                else
                    p->rchild = q->rchild;
            }else
                t = q->rchild;
            free(p);
        }
        else{
            child = q->rchild;
            while(child->lchild)
                child = child->lchild;
            child->lchild = q->lchild;
            if(p){
                if(p->lchild == q)
                    p->lchild = q->rchild;
                else
                    p->rchild = q->rchild;
            }else
                t=q->rchild;
            free(q);
        }
    }
    return t;
}
