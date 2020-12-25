#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node)

typedef struct k{
    int data;
    struct k *next;
}node;
typedef struct{
    node *front,*rear;
}queue;

queue *init()           //建立一个空的链队列
{
    queue *qu;
    qu = newNode;
    qu->front = NULL;
    qu->rear = NULL;
    return qu;
}

int empty(queue qu)     //判断链式队列是否为空
{
    return (qu.front ? 0:1);
}

void display(queue *qu)     //输出链式队列中各个结点的值
{
    node *p;
    printf("\n");
    p = qu->front;
    if(!p)
        printf("链式队列是空的");
    while(p){
        printf("%5d",p->data);
        p=p->next;
    }
}

int read(node qu)       //输出链式队列的队首结点值
{
    if(!qu.data){
        printf("链式队列是空的");
        exit(1);
    }
    return (qu.front->data);
}

queue *insert(queue *qu,int x)          //在链式队列插入一个值为x的结点
{
    node *p;
    p = newNode;
    p->data = x;
    p->next = NULL;
    if(qu->data == NULL)
        qu->front = qu->rear = p;
    else{
        qu->rear->next = p
        qu->rear = p;
    }
    return qu;
}

queue *delete(queue *qu)        //删除链式队列的队首结点
{
    node *q;
    if(!qu->front){
        printf("队列为空，无法删除");
        return qu;
    }
    q = qu->front;
    qu->front = q->next;
    free(q);
    if(qu->front == NULL)       //队列中的唯一的结点被删除之后，队列为空
        qu->rear = NULL;
    return qu;
}
