#include <stdio.h>
#include <stdlib.h>

int Fact(int n)             //��n�Ľ׳�
{
    int m;
    if(n == 0)          //�����ݹ�
        return 1;
    else{
        m = n*Fact(n - 1);              //��ʼ�ݹ�
        return m;
    }
}

int Fact1(int n)            //��n�Ľ׳ˣ��ǵݹ����ʽ
{
    int i,fac;
    fac = 1;        //��������ʼ����������sum���
    for(i = 1;i <= n;i++)       //���ݵ��ƹ�ϵ���е���
        fac = i*fac;
    return fac;
}

int Fibona(int n)           //쳲������ݹ��㷨
{
    int m;
    if(n == 1)          //�ݹ����������
        return (1);
    else if(n == 2)
        return (1);
    else{
        m = Fibona(n - 1)+Fibona(n - 2);            //��ʼ�ݹ�
        return (m);
    }
}

//��ӡ������
int N;
void print1(int n)      //�����ӡ������
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

void print2(int n)      //��ӡ������
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

void print3(int n)      //�õݹ��ӡ������
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

void convert(int n)         //��������ת���ַ������㷨
{
    int i;
    char ch;
    if((i = n/10) != 0)         //�ֱ�ȡ��n��ÿһλ������
        convert(i);
    ch = (n % 10) + '0';
    putchar(ch);
}

int gcd(int m,int n)            //�����������������Լ����շת�����
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
