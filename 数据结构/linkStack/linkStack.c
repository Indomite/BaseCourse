#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))

typedef struct k{
    int data;
    struct k* next;
}node;

node * init()       //����һ����ջ
{
    return NULL;
}

int empty(node *top)        //�ж���ʽջ�Ƿ�Ϊ��
{
    return (top? 0:1);
}

int read(node * top)            //��ȡջ��Ԫ�ص�ֵ
{
    if(!top){
        printf("��ʽջ�ǿյ�");
        exit(1);
    }
    return (top->data);
}

void display(node *top)             //�����ʽջ�еĸ�������ֵ
{
    node *p;
    p = top;
    printf("\n");
    if(!p)
        printf("��ʽջ�ǿյ�");
    while(p){
        printf("%5d",p->data);
        top = top->next;
    }
}

node *push(node *top)           //����ʽջ�в���һ��ֵΪx�Ľ��
{
    node *p;
    p = newNode;
    p->data = x;
    p->next = top;
    top = p;
    return top;
}

node *pop(node *head)           //ɾ����ʽջ��ջ�����
{
    node *p;
    if(!p){
        printf("��ʽջΪ�գ�ɾ��ʧ��");
        return NULL;
    }
    q = top;
    top = top->next;
    free(p);
    return top;
}
