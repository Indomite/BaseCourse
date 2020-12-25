#include "Array.h"
#define N 100

//顺序查找
int seqSearch(int a[],int n,int key)
{
    int i = 0;
    while(i < n && a[i] != key)     //从第一个数开始匹配，遇到key停止查找
        i++;
    if(i < n)
        return i;
    else
        return -1;
}

int main()
{
    int a[N],x,pos;
    init(a,N);
    print(a,N);
    printf("请输入要查找的数：");
    scanf("%d",&x);
    pos = seqSearch(a,N,x);
    if(pos != -1)
        printf("a[%d] = %d",pos,a[pos]);
    else
        printf("查询失败");
    return 0;
}
