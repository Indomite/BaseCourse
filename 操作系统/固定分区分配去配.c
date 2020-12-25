#include <stdio.h>
#define N 50

typedef struct subarea
{
    int start;
    int length;
    int work;
}subarea;

subarea s[N];

void distribute1(int n,int w1,int size)     //申请空间
{
    int i=0,j;
    while(i < n){
        if(s[i].length >size && s[i].work == 0){
            s[i].work = w1;
            printf("分区号\t起始地址\t长度\t占用标志\n");
            for(j=0;j < n;j++)
                printf("%d\t%d\t%d\t%d\t\n",j+1,s[j].start,s[j].length,s[j].work);
                break;
        }
        i++;
    }
    if(i == n)
        printf("分配失败");
}

void distribute2(int n,int w2)      //释放空间
{
    int i,j;
    for(i=0;i<n;i++)
        if(s[i].work = w2)
            s[i].work = 0;
    printf("分区号\t起始地址\t长度\t占用标志\n");
    for(j=0;j < n;j++)
        printf("%5d%5d%5d%5d\n",j+1,s[j].start,s[j].length,s[j].work);
}

void main()
{
    int i,n,w1,w2,size,k;
    printf("请输入分区的个数：");
    scanf("%d",&n);
    printf("请输入分区,依次输入起始地址、长度、占用标志\n");
    for(i=0;i<n;i++){
        scanf("%d %d %d",&s[i].start,&s[i].length,&s[i].work);
    }

    printf("输入k值(1=>申请，0=>释放)：");
    scanf("%d",&k);
    if(k==1){
        printf("请输入要申请的作业：");
        scanf("%d",&w1);
        printf("请输入要申请的空间大小：");
        scanf("%d",&size);
        distribute1(n,w1,size);
    }
    if(k == 0){
        printf("请输入要完成的作业：");
        scanf("%d",&w2);
        distribute2(n,w2);
    }
}
