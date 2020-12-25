#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Linknode;

void plefttoright(Linknode *head)       //从前往后输出单链表内容递归算法
{
    if(head->next){
        printf("%5d",head->next->data);         //输出链表的第一个结点
        plefttoright(head->next);           //递归输出后序结点
    }
}

void prighttoleft(Linknode *head)       //从后往前输出单链表内容递归算法
{
    if(head->next){
        prighttoleft(head->next);       //递归输出后序结点
        printf("%5d",head->next->data);     //输出链表的第一个结点
    }
}
