#include "Array.h"
#define N 100

//查找最大的数
int findMax(int a[],int n)
{
    int i,max;
    max = a[0];
    for(i = 1;i < n; i++){
        if(a[i] > max)
            max = a[i];
        //maxIndex = i;   返回最大数的下标
    }
    return max;
}

int main()
{
    int a[N],n;
    init(a,N);
    print(a,N);
    printf("最大的数是：");
    n = findMax(a,N);
    printf("%d",n);
    return 0;
}
