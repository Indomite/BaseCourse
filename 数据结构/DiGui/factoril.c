#include <stdio.h>
#include <stdlib.h>

int Fact(int n)             //求n的阶乘
{
    int m;
    if(n == 0)          //结束递归
        return 1;
    else{
        m = n*Fact(n - 1);              //开始递归
        return m;
    }
}

int Fact1(int n)            //求n的阶乘，非递归的形式
{
    int i,fac;
    fac = 1;        //将变量初始化，类似于sum求和
    for(i = 1;i <= n;i++)       //根据递推关系进行递推
        fac = i*fac;
    return fac;
}

int Fibona(int n)           //斐波那契递归算法
{
    int m;
    if(n == 1)          //递归结束的条件
        return (1);
    else if(n == 2)
        return (1);
    else{
        m = Fibona(n - 1)+Fibona(n - 2);            //开始递归
        return (m);
    }
}

//打印三角形
int N;
void print1(int n)      //正向打印三角形
{
    if(n > 0){
            print1(n - 1);
        for(int i = 1;i <= n;i++){
            printf("%d",i);
            printf("  ");
        }
        printf("\n");
    }
}

void print2(int n)      //打印三角形
{
    if(n > 0){
            print2(n - 1);
        for(int i = 1;i <= N-n;i++)
            printf(" ");
        for(int i = 1;i <= n;i++)
            printf("%d",i);
        printf("\n");
    }
}

void print3(int n)      //用递归打印金字塔
{
    if(n > 0){
            print3(n - 1);
        for(int i = 0;i < N-n;i++)
            printf(" ");
        for(int k = 1;k < n;k++)
            printf("%d",k);
        for(int j = n;j > 0;j--)
            printf("%d",j);
        printf("\n");
    }
}

void convert(int n)         //将正整数转换字符串的算法
{
    int i;
    char ch;
    if((i = n/10) != 0)         //分别取出n的每一位的数字
        convert(i);
    ch = (n % 10) + '0';
    putchar(ch);
}

int gcd(int m,int n)            //求两个正整数的最大公约数，辗转相除法
{
    int k;
    if(n == 0)
        return m;
    else if(n > m)
        return gcd(n,m);
    else{
        k = m % n;
        return (gcd(n,k));
    }
}

int main()
{
    int n,t;
    //scanf("%d",&n);
    //t = Fact(n);
    //t = Fibona(n);
    //printf("%d",t);
    scanf("%d",&N);
    print3(N);
    return 0;
}
