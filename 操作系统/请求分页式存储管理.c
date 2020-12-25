#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#define N 16
#define num 5  /*进程分配物理块数目*/
int A[N]={1,2,3,4,5,6,7,8,5,2,3,2,7,8,1,4};  /*页表映像*/
typedef struct page
{  int address;           /*页面地址*/
  struct page *next;
  }page;
struct page *head,*run,*rear;
void jccreat()   /*进程分配物理块*/
{ int i=1;
 page *p,*q;
 head=(page *)malloc(sizeof(page)); p=head;
 for(i=1;i<=num;i++) { q=(page *)malloc(sizeof(page));
                p->next=q;  q->address=0; q->next=NULL; p=q; }
            rear=p;}
int search(int n){
  page *p;
  int i=0;
  p=head;
  while(p->next)
  {
   if(p->next->address==n)
   {
   printf("Get it at the page %d\n",i+1);
   run=p;
   return 1;}
   p=p->next;
   i++;
  }
   return 0;
}

void changeOPT(int n,int position)
{
  int i;
  int total=0;
  int flag=1;
  int distance[num];
  int MAX;
  int order=0;
  page *p,*q;
  p=head->next;
  q=head->next;

  for(i=0;i<num;i++)
  distance[i]=100;
  i=0;
  while(p)
  {
   if(p->address==0)
   {flag=0;
    break;}
   p=p->next;
   i++;
  }
   if(!flag)
   {p->address=n;
    printf("Change the page %d\n",i+1);
   }
   else
   {
    while(q)
    {
     for(i=position;i<N;i++)
     {if(q->address==A[i])
     distance[total]=i-position;}
     total++;
     q=q->next;
    }
    MAX=distance[0];
    for(i=0;i<num;i++)
    {
     if(distance[i]>MAX)
      {
        MAX=distance[i];
        order=i;
       }
    }
    printf("Change the page %d\n",order+1);
    i=0;
    while(p)
    {
     if(i==order)
     p->address=n;
     i++;
     p=p->next;
    }
   }

}

void changeLRU(int n)
{
  int i=0;
  int flag=1;
  page *p,*delect;
  p=head->next;

  while(p)
  {
   if(p->address==0)
   {flag=0;
    p->address=n;
    printf("Change the page %d\n",i+1);
    break;}
   p=p->next;
   i++;
  }
   if(flag)
   {
    delect=head->next;
    head->next=delect->next;
    printf("Delect from the head, and add new to the end.\n");
    delect->address=n;
    rear->next=delect;
    rear=delect;
    rear->next=NULL;
   }
}

float OPT()
{
 int i;
 int lose=0;
 float losef;
 float percent;
 for(i=0;i<N;i++)
 {
  if(search(A[i])==0)
  {
    lose++;
    changeOPT(A[i],i);
  }
 }
   losef=lose;
   percent=1-(losef/N);
   return percent;
}

float LRU()
{
 int i;
 int lose=0;
 float losef;
 float percent;
 page *p;
 for(i=0;i<N;i++)
 {
  if(search(A[i])==0)
  {
    lose++;
    changeLRU(A[i]);
  }
  else
   {
    p=run->next;
    run->next=p->next;
    rear->next=p;
    rear=p;
    rear->next=NULL;
    printf("Move it to end of queue.\n");
   }
 }
   losef=lose;
   percent=1-(losef/N);
   return percent;
}

main()  /*主函数部分*/
{float percent;
  int choice;
  printf("Select the arithmetic:\n(1)OPT\n(2)LRU\nyour choice is:");
  scanf("%d",&choice);/*选择页面置换算法*/
  jccreat();               /*创建进程*/
  if(choice==1)           /*采用OPT算法置换*/
  {percent=OPT();        /*计算OPT时的缺页率*/
  printf("The percent of OPT is %f",percent);}
  else if(choice==2)      /*采用LRU算法置换*/
  {percent=LRU();       /*计算LRU时的缺页率*/
  printf("The percent of OPT is %f",percent);}
  else printf("Your choice is invalid.");
  getch();
}
