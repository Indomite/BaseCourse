#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100
//˳���
typedef struct{     //˳���=����+��
    int a[N];
    int len;
}seqList;

void init(seqList *L)
{
    L->len = 0;
}

void creatList(seqList *L)      //����˳���
{
    int x,i = 0;
    printf("���������ݣ���-1������");
    scanf("%d",&x);
    while(x != -1){
        L->a[i] = x;
        i++;
        scanf("%d",&x);
    }
    L->len = i;
}

void printList(seqList *L)      //��ӡ˳���
{
    int i;
    for(i = 0;i < L->len;i++){
        printf("%d ",L->a[i]);
    }
}

void insertList(seqList *L,int pos,int x)       //��˳�����ض�λ�ò�������
{   //1.�Ƴ���λ 2. ����Ԫ�� 3. �޸ı�
    int i = L->len;
    if(pos > L->len || pos < 0){
        printf("����Խ�磡");
        exit(1);
    }
    while(i > pos){
        L->a[i] = L->a[i-1];
        i--;
    }
    /*for(i = L->len;i > pos;i--)
        L->a[i] = L->a[i-1];*/
    L->a[pos] = x;
    L->len++;
}

void jioinsterList(seqList *L,seqList *L1,seqList *L2)      //��˳����е���ż�������������в��ֱ��ӡ
{
    int i,j,k;
    for(i = 0,j = 0,k = 0;i < L->len;i++)
    if(L->a[i] % 2 == 1){
        L1->a[j] = L->a[i];
        j++;
    }else{
        L2->a[k] = L->a[i];
        k++;
    }
    L1->len = j;
    L2->len = k;
}

void jioinsterList1(seqList *L)     //�����е�����������ߣ�ż�������ұ�
{
    int i = 0,j = L->len - 1,k;
    while(i < j){
        while(i < j && L->a[i] % 2 == 1)
            i++;
        while(i < j && L->a[j] % 2 == 0)
            j--;
        if(i < j){
            k = L->a[i];
            L->a[i] = L->a[j];
            L->a[j] = k;
        }
    }
}

void deleteList(seqList *L,int pos)       //ɾ���ض�λ�õ�����
{       //1. ɾ��Ԫ�� 2.�޸ı�
    int i;
    if(pos < 0 && pos > L->len){
        printf("��λ����Ч");
        exit(1);
    }
    for(i = pos;i < L->len;i++){
        L->a[i] = L->a[i+1];
    }
    L->len--;
}

void deleteList2(seqList *L,int x)      //ɾ��ָ������
{
    int j = 0,i;      //�����
    for(i = 0;i < L->len;i++){
        if(L->a[i] != x){
            L->a[j] = L->a[i];
            j++;
        }
    }
    L->len = j;
}

void deleteList3(seqList *L,int x)      //ɾ������x����
{
    int j = 0,i;      //�����
    for(i = 0;i < L->len;i++){
        if(L->a[i] <= x){
            L->a[j] = L->a[i];
            j++;
        }
    }
    L->len = j;
}

void delete4(seqList *L)        //ɾ��L����������
{
    int j = 0,i;
    for(i = 0;i < L->len;){
        if(L->a[i] % 2 == 1)
            i++;
        else{
            L->a[j] = L->a[i];
            i++;
            j++;
        }
    }
}

void selectList(seqList *L,int pos)     //��ѯָ��λ�õ�����
{
    if(pos > L->len || pos < 0)
        printf("������Ч");
    printf("%d\n",L->a[pos]);
}

void selectList1(seqList *L,int x)      //��ѯָ��������
{
    int i;
    for(i = 0;i < L->len;i++)
        if(L->a[i] == x)
        printf("%d ",i);
}

void updataList(seqList *L,int pos,int x)     //����ָ��λ�õ�����
{
    if(pos > L->len || pos < 0)
        printf("������Ч");
    L->a[pos] = x;
}

void updataList1(seqList *L,int x,int y)     //����ָ������
{
    int i;
    for(i = 0;i < L->len;i++){
        if(L->a[i] == x)
            L->a[i] = y;
    }
}

void mergeList1(seqList *L1,seqList *L2,seqList *L)      //�ϲ�����������һ���µ�˳���ʹ������һ�������
{
    int i = 0,j = 0 ,k = 0;
    while(i < L1->len && j < L2->len){
        if(L1->a[i] <= L2->a[j]){
            L->a[k] = L1->a[i];
            i++;
            k++;
        }else{
            L->a[k] = L2->a[j];
            j++;
            k++;
        }
    }
    while(i < L1->len){
        L->a[k] = L1->a[i];
        i++;
        k++;
    }
    while(j < L2->len){
        L->a[k] = L2->a[j];
        j++;
        k++;
    }
    L->len = k;
}

void mergeList2(seqList *L1,seqList *L2,seqList *L)      //�ϲ�����˳����һ���µ�˳���ʹ���ε���
{
    int i = 0,j = 0 ,k = L1->len + L2->len - 1;
    while(i < L1->len && j < L2->len){
        if(L1->a[i] <= L2->a[j]){
            L->a[k] = L1->a[i];
            i++;
            k--;
        }else{
            L->a[k] = L2->a[j];
            j++;
            k--;
        }
    }
    while(i < L1->len){
        L->a[k] = L1->a[i];
        i++;
        k--;
    }
    while(j < L2->len){
        L->a[k] = L2->a[j];
        j++;
        k--;
    }
    L->len = L1->len +L2->len;
}

int main()
{
    seqList L,L1,L2;
    init(&L);
    creatList(&L);
    //creatList(&L1);
    //creatList(&L2);
    //printList(&L);
    //insertList(&L,5,100);
    //jioinsterList(&L,&L1,&L2);
    //jioinsterList1(&L);
    //deleteList(&L,2);
    //deleteList2(&L,2);
    //deleteList3(&L,2);
    //selectList1(&L,2);
    //updataList(&L,2,40);
    //updataList1(&L,2,40);
    //mergeList2(&L1,&L2,&L);
    printList(&L);
    //printf("����:");printList(&L1);
    //printf("ż��:");printList(&L2);
    return 0;
}
