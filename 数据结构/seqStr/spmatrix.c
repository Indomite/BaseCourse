#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data[100][100];         //存放稀疏矩阵的二维数组
    int m,n;        //分别存放稀疏矩阵的行和列
}matrix;            //matrix表示稀疏矩阵的类型
typedef int spmatrix[100][3];       //spmatrix表示稀疏矩阵对应的三元组表示的类型

void compressmatrix(matrix A,spmatrix B)        //将稀疏矩阵转换成其三元组表示
{
    int i,j,k = 1;
    for(i = 0;i < A.m;i++)
        for(j = 0;j < A.n;j++)
    if(A.data[i][j] != 0){          //其中的非0元素的三元组表示
        B[k][0] = i;
        B[k][1] = j;
        B[k][2] = A.data[i][j];
        k++;
    }
    B[0][0] = A.m;          //在三元组的第一行放稀疏矩阵的行数，列数，非0元素的个数
    B[0][1] = A.n;
    B[0][2] = k - 1;
}

void transpmatrix(spmatrix B,spmatrix C)        //实现稀疏矩阵的转置
{
    int i,j,t,m,n;
    int x[100];     //该数组用来存放B中每一列非0元素的个数
    int y[100];      //该数组用来存放C中每一行非0元素三元组的起始位置
    m = B[0][0];n = B[0][1];t = B[0][2];        //第一行用来存储稀疏矩阵转化成稀疏矩阵的行数，列数，非0元素的个数
    C[0][0] = n;C[0][1] = m;C[0][2] = t;
    if(t > 0){
        for(i = 0;i < n;i++)    //初始化数组
            x[i] = 0;
        for(i = 1;i <= t;i++)       //统计每一列中非0元素的个数
            x[B[i][1]] = x[B[i][1]] +1;
        y[0] = 1;
        for(i = 1;i < n;i++)
            y[i] = y[i-1] + x[i-1];
        for(i = 1;i <= t;i++){          //将元素的行号列号交换，得到转置的矩阵
            j = y[B[i][1]];
            C[j][0] =B[i][1];
            C[j][1] =B[i][0];
            C[j][2] =B[i][2];
            y[B[i][1]] = j+1;
        }
    }
}
