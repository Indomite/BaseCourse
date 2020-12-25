#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))

typedef struct k
{
    int data;
    struct k *next;     //���ڴ�ʱ��û�д���node�ṹ�壬����ֻ����struct k*��ʾ
}node;

node *tailcreat()       //ʵ��β�巨
{
    node *h;
    int x;
    node *p,*tail;
    h = newNode;
    h->next = NULL;
    tail = h;
    printf("\n���룺");
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

node *headcreat()//ʵ��ͷ�巨
{
    node *h;
    int x;
    node *p;
    h = newNode;
    h->next = NULL;
    printf("���룺");
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

void insert(node *h,int x)//��������в���һ������ʹ��������
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

void merge(node *ha,node *hb,node *hc)//�ϲ����������ʹ��������
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

void print(node *h)//��ӡ������
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
    printf("\n�����");
    print(h);
    return 0;
}
