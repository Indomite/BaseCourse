#include <stdio.h>
#define N 50

typedef struct subarea
{
    int start;
    int length;
    int work;
}subarea;

subarea s[N];

void distribute1(int n,int w1,int size)     //����ռ�
{
    int i=0,j;
    while(i < n){
        if(s[i].length >size && s[i].work == 0){
            s[i].work = w1;
            printf("������\t��ʼ��ַ\t����\tռ�ñ�־\n");
            for(j=0;j < n;j++)
                printf("%d\t%d\t%d\t%d\t\n",j+1,s[j].start,s[j].length,s[j].work);
                break;
        }
        i++;
    }
    if(i == n)
        printf("����ʧ��");
}

void distribute2(int n,int w2)      //�ͷſռ�
{
    int i,j;
    for(i=0;i<n;i++)
        if(s[i].work = w2)
            s[i].work = 0;
    printf("������\t��ʼ��ַ\t����\tռ�ñ�־\n");
    for(j=0;j < n;j++)
        printf("%5d%5d%5d%5d\n",j+1,s[j].start,s[j].length,s[j].work);
}

void main()
{
    int i,n,w1,w2,size,k;
    printf("����������ĸ�����");
    scanf("%d",&n);
    printf("���������,����������ʼ��ַ�����ȡ�ռ�ñ�־\n");
    for(i=0;i<n;i++){
        scanf("%d %d %d",&s[i].start,&s[i].length,&s[i].work);
    }

    printf("����kֵ(1=>���룬0=>�ͷ�)��");
    scanf("%d",&k);
    if(k==1){
        printf("������Ҫ�������ҵ��");
        scanf("%d",&w1);
        printf("������Ҫ����Ŀռ��С��");
        scanf("%d",&size);
        distribute1(n,w1,size);
    }
    if(k == 0){
        printf("������Ҫ��ɵ���ҵ��");
        scanf("%d",&w2);
        distribute2(n,w2);
    }
}
