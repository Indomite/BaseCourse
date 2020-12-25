#include "Array.h"
#define N 10

int delData(int a[],int n,int pos)
{
    int i;
    if(pos >= 0 && pos < n){
        for(i = pos + 1; i < n; i++)
            a[i - 1] = a[i];
        return n-1;
    }
    else
        return n;
}

int main()
{
    int a[N],n,pos;
    init(a,N);
    print(a,N);
    printf("请输入要删除的位置：\n");
    scanf("%d",&pos);
    n = delData(a,N,pos);
    print(a,N);
    return 0;
}
