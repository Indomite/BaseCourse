#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    char str[N];
    int len;
}seqString;

int index(seqString p;,seqString t)     //Ѱ��ģʽp������t���״γ��ֵ���ʼλ��
{
    int i,j,succ;
    i = 0;
    succ = 0;       //��iɨ���ı���succ��ʾƥ��ɹ�
    while((i < t.len-p.len) && (!succ)){
        j = 0;
        succ = 1;               //�൱������һ��flag
        if(p.str[j] == t.str[i+j])      //��ƥ��ɹ�ʱ����
            j++;
        else
            succ = 0;
        ++i;
    }
    if(succ)            //��ƥ��ɹ�ʱ����������λ��
        returnn (i-1);
    else
        return -1;
}

void getnext(seqString p,int next)
