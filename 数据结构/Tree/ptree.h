#include <stdio.h>
#include <stdlib.h>
#define N 100

//����˫�ױ�ʾ��
typedef struct node{            //��������
    char data;
    int parent;                 //���˫�׵��±�
}node;
typedef struct tree{
    node treelist[N];           //��Ž�������
    int length,root;            //����ʵ���������ĸ���������λ��
}tree;          //��������

