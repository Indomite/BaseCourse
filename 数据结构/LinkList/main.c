#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))

typedef struct k
{
    int data;
    struct k *next;     //由于此时并没有创建node结构体，所以只能用struct k*表示
}node;

node *tailcreat()       //实现尾插法
{
    node *h;
    int x;
    node *p,*tail;
    h = newNode;
    h->next = NULL;
    tail = h;
    printf("\n输入：");
    scanf("%d",&x);
    while(x != -1){
        p = newNode;
        p->data = x;
        p->next = NULL;
        tail->next = p;
        tail = tail->next;
        scanf("%d",&x);
    }
    return h;
}

node *headcreat()//实现头插法
{
    node *h;
    int x;
    node *p;
    h = newNode;
    h->next = NULL;
    printf("输入：");
    scanf("%d",x);
    while(x != -1){
        p = newNode;
        p->data = x;
        p->next = NULL;
        p->next = h->next;
        h->next = p;
        scanf("%d",&x);
    }
    return h;
}

void insert(node *h,int x)//向有序表中插入一个数，使其任有序
{
    node *p,*pre,*q;
    q = newNode;
    q->data = x;
    q->next = NULL;
    pre = h;
    p = h->next;
    while(p != NULL && p->data < x)
    {
        p = p->next;
        pre = pre->next;
    }
    q->next = p;
    pre->next = q;
}

void merge(node *ha,node *hb,node *hc)//合并两个有序表，使其任有序
{
    node *a,*b,*c,*tail;
    a = ha->next;
    b = hb->next;
    tail = hc;
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data){
            c = a;
            a = a->next;
            tail->next = c;
            tail = c;
        }else{
            c = b;
            b = b->next;
            tail->next = c;
            tail = c;
        }
    }
    while(a != NULL)
    {
        c = a;
        a = a->next;
        tail->next = c;
        tail = c;
    }
    while(b != NULL)
    {
        c = b;
        b = b->next;
        tail->next = c;
        tail = c;
    }
}

void print(node *h)//打印单链表
{
    node *p;
    for(p=h->next;p!=NULL;p=p->next)
        printf("%d  ",p->data);
}

int main()
{
    node *h,*ha,*hb;
    //h = headcreat();
    ha = headcreat();
    hb = headcreat();
    h = newNode;h->next = NULL;
    merge(ha,hb,h);
    printf("\n输出：");
    print(h);
    return 0;
}
