#include <stdio.h>
#include <stdlib.h>
#define  m 3            //���Ķ���

//���ĺ��ӱ�ʾ��
typedef struct node{        //��������
    char data;
    struct node *child[m];              //ָ����Ů��ָ������
}node,*tree;
tree root;                  //root��ʾָ�������ָ��
