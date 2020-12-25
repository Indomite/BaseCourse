#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ProcessNum 5        //进程数

typedef struct pcb
{
    int name;      //进程名
    int CreateTime;     //创建时间
    int ProcessTime;        //运行时间
    int priority;       //优先级
    struct pcb *next;       //链指针
}PCB;
int Time = 0;       //系统开始时间
int state[5] = {0};          //进程初始状态
PCB * ready;        //就绪队列

//进程就绪队列
void ReadyQueue(PCB *head)
{
    PCB *h = head;
    PCB *now = NULL;
    while(h) {
        //就当前就绪的队列拿出来
        if(h->CreateTime <= Time && state[h->name] == 0) {          //已经创建好了，初始状态为0
            state[h->name] = 1;         //对进程序列中的进程状态进行标记，表示已经调用了
            now = (PCB*)malloc(sizeof(PCB));        //创建当前执行的节点
            now->next = NULL;
            now->name = h->name;
            now->CreateTime = h->CreateTime;
            now->ProcessTime = h->ProcessTime;
            now->priority = h->priority;
            if(!ready)      //第一个
                ready = now;
            else{
                now->next = ready;
                ready = now;
            }
        }
        h = h->next;
    }
    printf("当前就绪进程");
    h = ready;
    while(h) {
        printf("p%d ",h->name);
        h = h->next;
    }
}

//进程优先级排序
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
        //这就是一个节点插入的了，把各项属性都赋值
        while(now) {
            if(now->priority > h->priority) {       //进程信息的交换，把优先级高的进程信息放在前面
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
        printf("\n当前就绪进程优先级");
        h = ready;
        while(h) {
            printf("p%d ",h->name);
            h = h->next;
        }
}

//读取进程信息
PCB *ProcessInfo()
{
    int i;
    //尾插法读取进程信息
    PCB *now,*head,*tail;
    tail = head = NULL;
    printf("请输入各进程状态(进程名，创建时间，执行时间，优先级)\n");
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

//打印进程信息
void PrintInfo(PCB *head)
{
    PCB *h = head;          //拿到当前的头节点，读取链表信息
    printf("name\t CreateTime\t ProcessTime\t priority\n");
    while(h) {
        printf("p%d\t\t",h->name);
        printf("%d\t\t",h->CreateTime);
        printf("%d\t\t",h->ProcessTime);
        printf("%d\n",h->priority);
        h = h->next;
    }
}

//表示当前完成的进程
void ProcessDispatch(PCB *head)
{
    int finish = 0;         //完成状态
    PCB *del = NULL;
    while(true) {
        ReadyQueue(head);       //就绪队列
        PrioritySort();             //优先级排序
        Time += ready->ProcessTime;             //进程时间计算
        printf("\n时间Time = %d ,进程p%d 完成\n",Time,ready->name);           //打印出已经完成的进程
        finish += 1;            //已经完成的进程
        del = ready;           //释放完成的节点
        ready = ready->next;
        free(del);

        if(finish == 5)         //当进程全部完成之后结束
            break;
    }
}

int main()
{
    PCB *head = NULL;
    head = ProcessInfo();       //输入/读取进程信息
    PrintInfo(head);        //打印进程信息
    ProcessDispatch(head);          //进程调度
    printf("进程调度完毕");
    return 0;
}
