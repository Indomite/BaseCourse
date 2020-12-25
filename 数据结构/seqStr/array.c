#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *base;      //�������ָ���ַ
    int index[3];       //�����ά�����ά�ĳ���
    int c[3];           //�����ά�����ά��ֵ
}array;

int initarray(array *A,int b1,int b2,int b3)        //��ά����ĳ�ʼ��
{
    int elements;
    if(b1 <= 0 || b2 <= 0 || b3 <=0)        //������Ƿ�ʱ
        return 0;
    A->index[0] = b1;
    A->index[1] = b2;
    A->index[2] = b3;
    elements = b1*b2*b3;        //�õ�Ԫ�صĸ���
    A->base = (int *)malloc(elements*sizeof(int));          //Ϊ�������ռ�
    if(!(A->base))
        return 0;
    A->c[0] = b2*b3;
    A->c[1] = b3;
    A->c[2] = 1;
    return 1;
}

int value(array A,int i1,int i2,int i3,int *x)      //���������Ԫ��ֵ
{
    int off;
    if(i1 < 0 || i1 >= A.index[0] || i2 < 0 || i2 >= A.index[1] || i3 < 0 || i3 >= index[2])
        return 0;           //�ų��������
    off = i1*A.c[0] + i2*A.c[1] + i3*A.c[2];        //��������Ԫ�ص�λ��
    *x = *(A.base + off);       //��ֵ
    return 1;
}

int assgin(array *A,int e,int i1,int i2,int i3)     //ʵ�ֶ�����Ԫ�صĸ�ֵ����
{
    int off;
    if(i1 < 0 || i1 >= A.index[0] || i2 < 0 || i2 >= A.index[1] || i3 < 0 || i3 >= index[2])
        return 0;           //�ų��������
    off = i1*A->c[0] + i2*A->c[1] + i3*A->c[2];         //����Ԫ�ص�λ��
    *(A->base + off) = e;       //��ֵ
    return 1;
}
