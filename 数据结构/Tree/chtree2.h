#include <stdio.h>
#include <stdlib.h>
#define m 3                //树的度数
#define N 100

typedef struct node{            //树中结点的类型
    char data;
    int child[m];
}treenod;
treenode tree[N];           //存储树结点的数组
int root;                   //根结点的下标
int length;             //树中实际所含结点的个数
