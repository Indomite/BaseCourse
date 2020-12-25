#include <stdio.h>
#define N 100

//筛选法求素数
int main()
{
    int prime[N] = {0}; //初始化数组
    int i, j, counter = 0;
    for(i = 2;i <= N; i++)
        prime[i] = 1;       //先将2~N都设为素数
    for(i = 2;i <= N;i++)
    if(prime[i] == 1){      //i是素数
        printf("%5d",i);
        counter++;
        if(counter % 10 == 0)       //每十个换一行
            printf("\n");
        for(j = i;j <= N; j+=i)     //将i的倍数全部设为非素数
            prime[j] = 0;
    }
    return 0;
}
