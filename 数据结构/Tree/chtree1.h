#include <stdio.h>
#include <stdlib.h>
#define  m 3            //树的度数

//树的孩子表示法
typedef struct node{        //结点的类型
    char data;
    struct node *child[m];              //指向子女的指针数组
}node,*tree;
tree root;                  //root表示指向根结点的指针
