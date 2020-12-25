#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *base;      //数组的首指针地址
    int index[3];       //存放三维数组各维的长度
    int c[3];           //存放三维数组各维的值
}array;

int initarray(array *A,int b1,int b2,int b3)        //三维数组的初始化
{
    int elements;
    if(b1 <= 0 || b2 <= 0 || b3 <=0)        //当情况非法时
        return 0;
    A->index[0] = b1;
    A->index[1] = b2;
    A->index[2] = b3;
    elements = b1*b2*b3;        //得到元素的个数
    A->base = (int *)malloc(elements*sizeof(int));          //为数组分配空间
    if(!(A->base))
        return 0;
    A->c[0] = b2*b3;
    A->c[1] = b3;
    A->c[2] = 1;
    return 1;
}

int value(array A,int i1,int i2,int i3,int *x)      //访问数组的元素值
{
    int off;
    if(i1 < 0 || i1 >= A.index[0] || i2 < 0 || i2 >= A.index[1] || i3 < 0 || i3 >= index[2])
        return 0;           //排除特殊情况
    off = i1*A.c[0] + i2*A.c[1] + i3*A.c[2];        //计算数组元素的位置
    *x = *(A.base + off);       //赋值
    return 1;
}

int assgin(array *A,int e,int i1,int i2,int i3)     //实现对数组元素的赋值运算
{
    int off;
    if(i1 < 0 || i1 >= A.index[0] || i2 < 0 || i2 >= A.index[1] || i3 < 0 || i3 >= index[2])
        return 0;           //排除特殊情况
    off = i1*A->c[0] + i2*A->c[1] + i3*A->c[2];         //计算元素的位移
    *(A->base + off) = e;       //赋值
    return 1;
}
