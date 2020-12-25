#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))

typedef struct k{
    int data;
    struct k* next;
}node;

node * init()       //建立一个空栈
{
    return NULL;
}

int empty(node *top)        //判断链式栈是否为空
{
    return (top? 0:1);
}

int read(node * top)            //读取栈顶元素的值
{
    if(!top){
        printf("链式栈是空的");
        exit(1);
    }
    return (top->data);
}

void display(node *top)             //输出链式栈中的各个结点的值
{
    node *p;
    p = top;
    printf("\n");
    if(!p)
        printf("链式栈是空的");
    while(p){
        printf("%5d",p->data);
        top = top->next;
    }
}

node *push(node *top)           //向链式栈中插入一个值为x的结点
{
    node *p;
    p = newNode;
    p->data = x;
    p->next = top;
    top = p;
    return top;
}

node *pop(node *head)           //删除链式栈的栈顶结点
{
    node *p;
    if(!p){
        printf("链式栈为空，删除失败");
        return NULL;
    }
    q = top;
    top = top->next;
    free(p);
    return top;
}
