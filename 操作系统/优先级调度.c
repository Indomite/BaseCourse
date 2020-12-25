#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ProcessNum 5        //������

typedef struct pcb
{
    int name;      //������
    int CreateTime;     //����ʱ��
    int ProcessTime;        //����ʱ��
    int priority;       //���ȼ�
    struct pcb *next;       //��ָ��
}PCB;
int Time = 0;       //ϵͳ��ʼʱ��
int state[5] = {0};          //���̳�ʼ״̬
PCB * ready;        //��������

//���̾�������
void ReadyQueue(PCB *head)
{
    PCB *h = head;
    PCB *now = NULL;
    while(h) {
        //�͵�ǰ�����Ķ����ó���
        if(h->CreateTime <= Time && state[h->name] == 0) {          //�Ѿ��������ˣ���ʼ״̬Ϊ0
            state[h->name] = 1;         //�Խ��������еĽ���״̬���б�ǣ���ʾ�Ѿ�������
            now = (PCB*)malloc(sizeof(PCB));        //������ǰִ�еĽڵ�
            now->next = NULL;
            now->name = h->name;
            now->CreateTime = h->CreateTime;
            now->ProcessTime = h->ProcessTime;
            now->priority = h->priority;
            if(!ready)      //��һ��
                ready = now;
            else{
                now->next = ready;
                ready = now;
            }
        }
        h = h->next;
    }
    printf("��ǰ��������");
    h = ready;
    while(h) {
        printf("p%d ",h->name);
        h = h->next;
    }
}

//�������ȼ�����
void PrioritySort()
{
    int name;
    int CreateTime;
    int ProcessTime;
    int priority;
    PCB *h = ready;
    PCB *now = NULL;
    while(h) {
        now = h->next;
        //�����һ���ڵ������ˣ��Ѹ������Զ���ֵ
        while(now) {
            if(now->priority > h->priority) {       //������Ϣ�Ľ����������ȼ��ߵĽ�����Ϣ����ǰ��
                name = now->name;
                now->name = h->name;
                h->name = name;

                CreateTime = now->CreateTime;
                now->CreateTime = h->CreateTime;
                h->CreateTime = CreateTime;

                ProcessTime = now->ProcessTime;
                now->ProcessTime = h->ProcessTime;
                h->ProcessTime = ProcessTime;

                priority = now->priority;
                now->priority = h->priority;
                h->priority = priority;
            }
            now = now->next;
        }
            h = h->next;
        }
        printf("\n��ǰ�����������ȼ�");
        h = ready;
        while(h) {
            printf("p%d ",h->name);
            h = h->next;
        }
}

//��ȡ������Ϣ
PCB *ProcessInfo()
{
    int i;
    //β�巨��ȡ������Ϣ
    PCB *now,*head,*tail;
    tail = head = NULL;
    printf("�����������״̬(������������ʱ�䣬ִ��ʱ�䣬���ȼ�)\n");
    for(i=0;i<ProcessNum;i++) {
        now = (PCB*)malloc(sizeof(PCB));
        scanf("%d",&now->name);
        scanf("%d",&now->CreateTime);
        scanf("%d",&now->ProcessTime);
        scanf("%d",&now->priority);
        if(!head)
            tail = head = now;
        else{
            tail->next = now;
            tail = now;
        }
    }
    tail->next = NULL;
    return head;
}

//��ӡ������Ϣ
void PrintInfo(PCB *head)
{
    PCB *h = head;          //�õ���ǰ��ͷ�ڵ㣬��ȡ������Ϣ
    printf("name\t CreateTime\t ProcessTime\t priority\n");
    while(h) {
        printf("p%d\t\t",h->name);
        printf("%d\t\t",h->CreateTime);
        printf("%d\t\t",h->ProcessTime);
        printf("%d\n",h->priority);
        h = h->next;
    }
}

//��ʾ��ǰ��ɵĽ���
void ProcessDispatch(PCB *head)
{
    int finish = 0;         //���״̬
    PCB *del = NULL;
    while(true) {
        ReadyQueue(head);       //��������
        PrioritySort();             //���ȼ�����
        Time += ready->ProcessTime;             //����ʱ�����
        printf("\nʱ��Time = %d ,����p%d ���\n",Time,ready->name);           //��ӡ���Ѿ���ɵĽ���
        finish += 1;            //�Ѿ���ɵĽ���
        del = ready;           //�ͷ���ɵĽڵ�
        ready = ready->next;
        free(del);

        if(finish == 5)         //������ȫ�����֮�����
            break;
    }
}

int main()
{
    PCB *head = NULL;
    head = ProcessInfo();       //����/��ȡ������Ϣ
    PrintInfo(head);        //��ӡ������Ϣ
    ProcessDispatch(head);          //���̵���
    printf("���̵������");
    return 0;
}
