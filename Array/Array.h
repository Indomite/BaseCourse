#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//输入函数
void input(int a [],int n)
{
    int i;
    printf("请输入%d个整数(整数间用空格间隔):\n",n);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
}

//打印函数
void print(int a[],int n)
{
    int i;
    printf("\n数组的内容是：\n");
    for(i = 0;i < n; i++){
        if(i % 10 == 0)
            printf("\n");
        printf("%6d",a[i]);
    }
    printf("\n");
}

//随机赋值
void init(int a[],int n)
{
    int i;
    srand(time(0));
    for(i = 0;i < n; i++){
      a[i] = rand() % 1000 + 1;
    }
}
