#include <stdio.h>
#include <stdlib.h>
#define newNode (node *)malloc(sizeof(node))

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}node;

node *headcreat()         //����һ����ͷ���ĵ�����
{       //ͷ�巨 1.����ͷ��㣬ʹ��ָ�� 2.�����������ӵĽ�� 3.�ı�ָ���λ�� 4.����ͷ���
    node *head;
    node *q;
    int x;
    head = newNode;
    head->next = NULL;
    printf("����һ�����ݣ���-1������");
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

node *tailcreat()       //����һ����ͷ���ĵ�����
{       //β�巨 1.����ͷ��㣬ʹ��ָ�� 2�������½������������ݣ���ÿ���������ʱ��ע���޸�βָ�� 3.���ر�ͷ
    node *head;
    node *q,*tail;
    int x;
    head = newNode;
    head->next = NULL;
    tail = head;
    printf("����:");
    scanf("%d",&x);
    while(x != -1){
        q = newNode;
        q->data = x;
        q->next = NULL;     //�����٣���������Ұָ��
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

node *insertY(node *head,int x,int y)       //�ڵ������в���Ԫ��x���ҵ�������x֮ǰ������Ԫ��y
{       //����������㣬�ֱ����ڱ�������������������ֵ������ǰһ��ֵ
    node *q,*p,*pre;
    q = newNode;
    q->data = y;
    q->next = NULL;     //Ϊ������ݵĽ���ʼ��
    pre = head;
    p = head->next;     //������ʾ����pre->next = p
    while(p != NULL && p->data != x){
        p = p->next;
        pre = pre->next;
    }
    q->next = p;
    pre->next = q;
    return head;
}

node *seqInsert(node *head,int x)       //���赥����������ģ���õ��������Ԫ��x��ʹ�ò������������
{       //��������ķ��������Ǹ�һ������
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

node *deleteX(node *head,int x)     //ɾ����������ֵΪx������Ԫ��
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

void findX(node *head,int x)//�������в���X
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
