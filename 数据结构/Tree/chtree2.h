#include <stdio.h>
#include <stdlib.h>
#define m 3                //���Ķ���
#define N 100

typedef struct node{            //���н�������
    char data;
    int child[m];
}treenod;
treenode tree[N];           //�洢����������
int root;                   //�������±�
int length;             //����ʵ���������ĸ���
