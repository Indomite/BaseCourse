#include <stdio.h>
#include <stdlib.h>
#define N 100

 typedef struct chnode{         //孩子结点的类型
    int child;
    struct chnode *next;
 }chnode,* chpoint;

 typedef struct{                //树中每个结点的类型
    char data;
    chpoint firstchild;             //指向第1个子女结点的指针
 }node;

 typedef struct{            //树的类型
    node treelist [N];
    int lenght,root;            //树中实际所含结点的个数和根结点的位置
 }tree;
