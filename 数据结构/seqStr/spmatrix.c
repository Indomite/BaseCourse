#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data[100][100];         //���ϡ�����Ķ�ά����
    int m,n;        //�ֱ���ϡ�������к���
}matrix;            //matrix��ʾϡ����������
typedef int spmatrix[100][3];       //spmatrix��ʾϡ������Ӧ����Ԫ���ʾ������

void compressmatrix(matrix A,spmatrix B)        //��ϡ�����ת��������Ԫ���ʾ
{
    int i,j,k = 1;
    for(i = 0;i < A.m;i++)
        for(j = 0;j < A.n;j++)
    if(A.data[i][j] != 0){          //���еķ�0Ԫ�ص���Ԫ���ʾ
        B[k][0] = i;
        B[k][1] = j;
        B[k][2] = A.data[i][j];
        k++;
    }
    B[0][0] = A.m;          //����Ԫ��ĵ�һ�з�ϡ��������������������0Ԫ�صĸ���
    B[0][1] = A.n;
    B[0][2] = k - 1;
}

void transpmatrix(spmatrix B,spmatrix C)        //ʵ��ϡ������ת��
{
    int i,j,t,m,n;
    int x[100];     //�������������B��ÿһ�з�0Ԫ�صĸ���
    int y[100];      //�������������C��ÿһ�з�0Ԫ����Ԫ�����ʼλ��
    m = B[0][0];n = B[0][1];t = B[0][2];        //��һ�������洢ϡ�����ת����ϡ��������������������0Ԫ�صĸ���
    C[0][0] = n;C[0][1] = m;C[0][2] = t;
    if(t > 0){
        for(i = 0;i < n;i++)    //��ʼ������
            x[i] = 0;
        for(i = 1;i <= t;i++)       //ͳ��ÿһ���з�0Ԫ�صĸ���
            x[B[i][1]] = x[B[i][1]] +1;
        y[0] = 1;
        for(i = 1;i < n;i++)
            y[i] = y[i-1] + x[i-1];
        for(i = 1;i <= t;i++){          //��Ԫ�ص��к��кŽ������õ�ת�õľ���
            j = y[B[i][1]];
            C[j][0] =B[i][1];
            C[j][1] =B[i][0];
            C[j][2] =B[i][2];
            y[B[i][1]] = j+1;
        }
    }
}
