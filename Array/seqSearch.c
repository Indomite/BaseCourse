#include "Array.h"
#define N 100

//˳�����
int seqSearch(int a[],int n,int key)
{
    int i = 0;
    while(i < n && a[i] != key)     //�ӵ�һ������ʼƥ�䣬����keyֹͣ����
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
    printf("������Ҫ���ҵ�����");
    scanf("%d",&x);
    pos = seqSearch(a,N,x);
    if(pos != -1)
        printf("a[%d] = %d",pos,a[pos]);
    else
        printf("��ѯʧ��");
    return 0;
}
