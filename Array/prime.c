#include <stdio.h>
#define N 100

//ɸѡ��������
int main()
{
    int prime[N] = {0}; //��ʼ������
    int i, j, counter = 0;
    for(i = 2;i <= N; i++)
        prime[i] = 1;       //�Ƚ�2~N����Ϊ����
    for(i = 2;i <= N;i++)
    if(prime[i] == 1){      //i������
        printf("%5d",i);
        counter++;
        if(counter % 10 == 0)       //ÿʮ����һ��
            printf("\n");
        for(j = i;j <= N; j+=i)     //��i�ı���ȫ����Ϊ������
            prime[j] = 0;
    }
    return 0;
}
