#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Linknode;

void plefttoright(Linknode *head)       //��ǰ����������������ݵݹ��㷨
{
    if(head->next){
        printf("%5d",head->next->data);         //�������ĵ�һ�����
        plefttoright(head->next);           //�ݹ����������
    }
}

void prighttoleft(Linknode *head)       //�Ӻ���ǰ������������ݵݹ��㷨
{
    if(head->next){
        prighttoleft(head->next);       //�ݹ����������
        printf("%5d",head->next->data);     //�������ĵ�һ�����
    }
}
