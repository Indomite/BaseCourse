#include <stdio.h>
#include <stdlib.h>

//���ĺ����ֵܱ�ʾ��
typedef struct node{            //����ÿ����������
    char data;
    struct node *firstchild,*rightsibling;
}node,* pnode;
pnode root;             //ָ����������ָ��
