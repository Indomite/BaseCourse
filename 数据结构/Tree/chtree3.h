#include <stdio.h>
#include <stdlib.h>
#define N 100

 typedef struct chnode{         //���ӽ�������
    int child;
    struct chnode *next;
 }chnode,* chpoint;

 typedef struct{                //����ÿ����������
    char data;
    chpoint firstchild;             //ָ���1����Ů����ָ��
 }node;

 typedef struct{            //��������
    node treelist [N];
    int lenght,root;            //����ʵ���������ĸ����͸�����λ��
 }tree;
