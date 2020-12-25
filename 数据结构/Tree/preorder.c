#include <stdio.h>
#include <stdlib.h>

typedef struct node{        //��������
    char data;
    struct node *child[m];              //ָ����Ů��ָ������
}node,*tree;
tree root;                  //root��ʾָ�������ָ��

void preorder(tree p)           //����ǰ������ĵݹ��㷨
{
    int i;
    if(p != NULL){          //����Ϊ��
        printf("%c",p->data);           //���������ֵ
        for(i = 0;i < m;i++)
            preorder(p->child[i]);          //�ݹ�ʵ�ָ�������ǰ�����
    }
}

void postorder(tree p)          //���ĺ�������ĵݹ��㷨
{
    int i;
    if(p != NULL){
        for(i = 0;i < m;i++)
            postorder(p->child[i]);
        printf("%c",p->data);
    }
}

tree createtree()           //��ǰ���������һ��������
{
    int i;
    char ch;
    tree t;
    if((ch = getchar ()) == '#')
        t = NULL;
    else{
        t = (tree)malloc(sizeof(node))
        t->data = ch;
        for(i = 0;i < m,i++)
            t->child[i] = createtree();
    }
}

void levelorder(tree t)             //ʵ�����Ĳ�α�����tָ����Ǹ�����ָ��
{
    tree queue[100];            //��ŵȴ����ʵĽ�����
    int f,r,i;          //f��r�ֱ�Ϊ��ͷ��βָ��
    tree p;
    f = 0;r = 1;queue[0] = t;
    while(f < r){               //���в�Ϊ��
        p = queue[f];
        f++;
        printf("%c",p->data);           //���ʶ�ͷԪ��
        for(i = 0;i < m;i++)        //���ձ����ʵ�Ԫ�ص�������Ů������ν���
        if(p ->child[i]){
            queue[r] = p->child[i];
            r++;
        }
    }
}

