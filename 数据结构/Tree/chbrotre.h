#include <stdio.h>
#include <stdlib.h>

//树的孩子兄弟表示法
typedef struct node{            //树中每个结点的类型
    char data;
    struct node *firstchild,*rightsibling;
}node,* pnode;
pnode root;             //指向树根结点的指针
