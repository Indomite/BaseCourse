#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}node;

node *headcreat()         //创建一个带头结点的单链表
{       //头插法 1.创建头结点，使其指空 2.创建用于增加的结点 3.改变指针的位置 4.返回头结点
    node *head;
    node *q;
    int x;
    head = newNode;
    head->next = NULL;
    printf("输入一组数据，以-1结束：");
    scanf("%d",&x);
    while(x != -1){
        q = newNode;
        q->data = x;
        q->next = head->next;
        head->next = q;
        scanf("%d",&x);
    }
    return head;
}

node *tailcreat()       //创建一个带头结点的单链表
{       //尾插法 1.创建头结点，使其指空 2。创建新结点用于添加数据，在每次添加数据时，注意修改尾指针 3.返回表头
    node *head;
    node *q,*tail;
    int x;
    head = newNode;
    head->next = NULL;
    tail = head;
    printf("输入:");
    scanf("%d",&x);
    while(x != -1){
        q = newNode;
        q->data = x;
        q->next = NULL;     //不可少，否则会出现野指针
        tail->next = q;
        tail = tail->next;
        scanf("%d",&x);
    }
    return head;
}

void print(node *head)
{
    node *q;
    for(q=head->next;q != NULL;q = q->next)
        printf("%d ",q->data);
}

node *insertY(node *head,int x,int y)       //在单链表中查找元素x，找到后则【在x之前】插入元素y
{       //创建三个结点，分别用于遍历链表，保存新增结点的值，结点的前一个值
    node *q,*p,*pre;
    q = newNode;
    q->data = y;
    q->next = NULL;     //为添加数据的结点初始化
    pre = head;
    p = head->next;     //这样表示就是pre->next = p
    while(p != NULL && p->data != x){
        p = p->next;
        pre = pre->next;
    }
    q->next = p;
    pre->next = q;
    return head;
}

node *seqInsert(node *head,int x)       //假设单链表是有序的，向该单链表插入元素x，使得插入后依旧有序
{       //类似上面的方法，就是改一下条件
    node *q,*pre,*p;
    q = newNode;
    q->data = x;
    q->next = NULL;
    pre = head;
    p = head->next;
    while(p != NULL && p->data < x){
        p = p->next;
        pre = pre->next;
    }
    q->next = p;
    pre->next = q;
    return head;
}

node *deleteX(node *head,int x)     //删除单链表中值为x的所有元素
{
    node *q,*pre,*p;
    pre = head;
    q = head->next;
    while(q != NULL){
        if(q->data == x){
            p = q;
            q = q->next;
            pre->next = q;
            free(p);
        }else{
            q = q->next;
            pre = pre->next;
        }
    }
    return head;
}

void findX(node *head,int x)//在链表中查找X
{
    node *q,*pre,*p;
    pre = head;
    q = head->next;
    while(q != NULL){
        if(q->data == x){
            printf("%d",q->data);
        }else{
            q = q->next;
            pre = pre->next;
        }
    }
}

int main()
{
    node *head,*ha,*hb,*y;
    head = tailcreat();
    deleteX(head,5);
    print(head);
    return 0;
}
