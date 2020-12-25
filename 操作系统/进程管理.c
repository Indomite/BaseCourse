    #include <stdio.h>
    #include <stdlib.h>
    #define getpch(type) (type*)malloc(sizeof(type))

    struct pcb
    {
        char name[20];
        int state;
        int priority;
        int needtime;
        int runtime;
        struct pcb* next;
    }
    *ready=NULL,*p,*bhead=NULL;
    typedef struct pcb PCB;

    void sort()
    {
        PCB *first,*second;
        int insert=0;
        if ((ready==NULL)||((p->priority)>(ready->priority)))   //优先级高的先插入
        {
            p->next=ready;
            ready=p;
        }
        else
        {
            first=ready;
            second=first->next;
            while(second!=NULL)
            {
                if((p->priority)>(second->priority))
                {
                    p->next=second;
                    first->next=p;
                    second=NULL;
                }
                else
                {
                    first=first->next;second=second->next;
                }
            }
            if(insert==0) {
                first->next=p;
            }
        }
    }

    void block(){
        PCB *pb,*index=ready;
        int count=0;
        if(ready==NULL)return;
        while((index->next!=NULL))
        {
            if((index->next->priority)>=ready->priority){
                index->next->state='B';
                index=index->next;
                count++;
            }else{
                break;
            }
        }
        if(count>0){
            pb=index->next;
            index->next=bhead;
            bhead=ready->next;
            ready->next=pb;
        }
    }

    void weakup(){
        PCB *index,*prior,*t;
        int exchange=0;
        if(bhead==NULL)return;
        if(bhead->next!=NULL)
        {
            index=bhead->next;
            prior=bhead;
            while(index!=NULL)
            {
                if((index->priority)>(bhead->priority))
                {
                    exchange=1;
                }
                else if((index->priority)==(bhead->priority))
                {
                    if((index->needtime-index->runtime)<(bhead->needtime-bhead->runtime))
                    {
                        exchange=1;
                    }
                }
                if(exchange==1){
                    prior->next=bhead;
                    t=bhead->next;
                    bhead->next=index->next;
                    index->next=t;
                    bhead=index;
                    exchange=0;
                }
                prior=index;
                index=index->next;
            }
        }
        t=bhead->next;
        bhead->next=ready;
        ready=bhead;
        bhead=t;
    }

    void input()
    {
        int i,num;
        printf("请输入进程数量:");
        scanf("%d",&num);
        for (i=0;i<num;i++)
        {
            printf("[请设置 %d号 进程的基本属性]\n",i+1);
            p=getpch(PCB);
            printf("请输入名称、优先级、时间：");
            scanf("%s%d%d",p->name,&p->priority,&p->needtime);
            printf("\n");
            p->runtime=0;
            p->state='W';
            p->next=NULL;
            sort();
        }
    }

    int space()
    {
        int l=0;PCB*pr=ready;
        while(pr!=NULL)
        {
            l++;
            pr=pr->next;
        }
        return(l);
    }

    void disp(PCB*pr)
    {
        printf("%s\t%c\t%d\t%d\t%d\t",pr->name,pr->state,pr->priority,pr->needtime,pr->runtime);
        printf("\n");
    }

    void check()
    {
        PCB *pr,*pb;
        printf("\n====[当前运行中的进程]====\n");
        printf("进程名称:%s\n",p->name);
        printf("\n名称\t状态\t优先数\t总时长\t已用时\n");
        disp(p);
        pr=ready;
        if(pr==NULL){
            printf("\n====[当前就绪队列为空]====\n");
        }
        else
        {
            printf("\n====[当前就绪队列状态]====");
            printf("\n名称\t状态\t优先数\t总时长\t已用时\n");
            while(pr!=NULL)
            {
                disp(pr);
                pr=pr->next;
            }
        }
        pb=bhead;
        if(pb==NULL){
            printf("\n====[当前阻塞队列为空]====\n");
        }
        else
        {
            printf("\n====[当前阻塞队列状态]====");
            printf("\n名称\t状态\t优先数\t总时长\t已用时\n");
            while(pb!=NULL)
            {
                disp(pb);
                pb=pb->next;
            }
        }
    }

    void destroy()
    {
        printf("\n进程[%s]已完成.\n",p->name);
        free(p);
    }

    void running()
    {
        (p->runtime)++;
        if(p->runtime==p->needtime)
        {
            destroy();
        }
        else
        {
            (p->priority)--;
            p->state='W';
            sort();
            if(bhead!=NULL){
                weakup();
            }
            block();
        }
    }

    int main()
    {
        int len,h=0;
        char ch;
        input();
        len=space();
        while((len!=0)&&(ready!=NULL))
        {
            ch=getchar();
            h++;
            printf("\n\n[第%d次运行]\n",h);
            p=ready;
            ready=p->next;
            p->next=NULL;
            p->state='R';
            check();	//显示当前运行状态信息
            running();	//运行
            printf("\n按任一键继续.....");
            ch=getchar();
        }
        printf("\n\n进程已经完成.\n");
        ch=getchar();
        return 0;
    }
