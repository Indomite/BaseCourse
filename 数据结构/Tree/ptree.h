#include <stdio.h>
#include <stdlib.h>
#define N 100

//树的双亲表示法
typedef struct node{            //结点的类型
    char data;
    int parent;                 //结点双亲的下标
}node;
typedef struct tree{
    node treelist[N];           //存放结点的数组
    int length,root;            //树中实际所含结点的个数及结点的位置
}tree;          //树的类型

