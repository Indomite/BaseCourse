#include <stdio.h>
#include <stdlib.h>

typedef struct node{        //结点的类型
    char data;
    struct node *child[m];              //指向子女的指针数组
}node,*tree;
tree root;                  //root表示指向根结点的指针

void preorder(tree p)           //树的前序遍历的递归算法
{
    int i;
    if(p != NULL){          //树不为空
        printf("%c",p->data);           //输出根结点的值
        for(i = 0;i < m;i++)
            preorder(p->child[i]);          //递归实现各子树的前序遍历
    }
}

void postorder(tree p)          //树的后序遍历的递归算法
{
    int i;
    if(p != NULL){
        for(i = 0;i < m;i++)
            postorder(p->child[i]);
        printf("%c",p->data);
    }
}

tree createtree()           //按前序遍历创建一棵三度树
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

void levelorder(tree t)             //实现树的层次遍历，t指向的是根结点的指针
{
    tree queue[100];            //存放等待访问的结点队列
    int f,r,i;          //f、r分别为队头队尾指针
    tree p;
    f = 0;r = 1;queue[0] = t;
    while(f < r){               //队列不为空
        p = queue[f];
        f++;
        printf("%c",p->data);           //访问队头元素
        for(i = 0;i < m;i++)        //将刚被访问的元素的所有子女结点依次进队
        if(p ->child[i]){
            queue[r] = p->child[i];
            r++;
        }
    }
}

