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

queue *init()           //����һ���յ�������
{
    queue *qu;
    qu = newNode;
    qu->front = NULL;
    qu->rear = NULL;
    return qu;
}

int empty(queue qu)     //�ж���ʽ�����Ƿ�Ϊ��
{
    return (qu.front ? 0:1);
}

void display(queue *qu)     //�����ʽ�����и�������ֵ
{
    node *p;
    printf("\n");
    p = qu->front;
    if(!p)
        printf("��ʽ�����ǿյ�");
    while(p){
        printf("%5d",p->data);
        p=p->next;
    }
}

int read(node qu)       //�����ʽ���еĶ��׽��ֵ
{
    if(!qu.data){
        printf("��ʽ�����ǿյ�");
        exit(1);
    }
    return (qu.front->data);
}

queue *insert(queue *qu,int x)          //����ʽ���в���һ��ֵΪx�Ľ��
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

queue *delete(queue *qu)        //ɾ����ʽ���еĶ��׽��
{
    node *q;
    if(!qu->front){
        printf("����Ϊ�գ��޷�ɾ��");
        return qu;
    }
    q = qu->front;
    qu->front = q->next;
    free(q);
    if(qu->front == NULL)       //�����е�Ψһ�Ľ�㱻ɾ��֮�󣬶���Ϊ��
        qu->rear = NULL;
    return qu;
}
