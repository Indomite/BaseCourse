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
        if ((ready==NULL)||((p->priority)>(ready->priority)))   //���ȼ��ߵ��Ȳ���
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
        printf("�������������:");
        scanf("%d",&num);
        for (i=0;i<num;i++)
        {
            printf("[������ %d�� ���̵Ļ�������]\n",i+1);
            p=getpch(PCB);
            printf("���������ơ����ȼ���ʱ�䣺");
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
        printf("\n====[��ǰ�����еĽ���]====\n");
        printf("��������:%s\n",p->name);
        printf("\n����\t״̬\t������\t��ʱ��\t����ʱ\n");
        disp(p);
        pr=ready;
        if(pr==NULL){
            printf("\n====[��ǰ��������Ϊ��]====\n");
        }
        else
        {
            printf("\n====[��ǰ��������״̬]====");
            printf("\n����\t״̬\t������\t��ʱ��\t����ʱ\n");
            while(pr!=NULL)
            {
                disp(pr);
                pr=pr->next;
            }
        }
        pb=bhead;
        if(pb==NULL){
            printf("\n====[��ǰ��������Ϊ��]====\n");
        }
        else
        {
            printf("\n====[��ǰ��������״̬]====");
            printf("\n����\t״̬\t������\t��ʱ��\t����ʱ\n");
            while(pb!=NULL)
            {
                disp(pb);
                pb=pb->next;
            }
        }
    }

    void destroy()
    {
        printf("\n����[%s]�����.\n",p->name);
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
            printf("\n\n[��%d������]\n",h);
            p=ready;
            ready=p->next;
            p->next=NULL;
            p->state='R';
            check();	//��ʾ��ǰ����״̬��Ϣ
            running();	//����
            printf("\n����һ������.....");
            ch=getchar();
        }
        printf("\n\n�����Ѿ����.\n");
        ch=getchar();
        return 0;
    }
