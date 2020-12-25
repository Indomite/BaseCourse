#include "Array.h"
#define N 20

//插入数据
int insertData(int a[],int n,int pos,int x)
{
    int i;
    if(pos >= 0 && pos <= n){
        for(i = n-1;i >= pos; i--)
            a[i+1] = a[i];
        a[pos] = x;
        n++;
    }
    return n;
}

int main()
{
    int a[N],n,pos,x;
    init(a,N);
    print(a,N);
    printf("请输入要插入的位置和数据：\n");
    scanf("%d%d",&pos,&x);
    n = insertData(a,N,pos,x);
    print(a,N);
    return 0;
}
