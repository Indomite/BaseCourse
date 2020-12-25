#include <stdio.h>
#include <stdlib.h>
#define N 100
#define newNode (seq_string *)malloc(sizeof(seq_string))

typedef struct{
    char str[N];
    int len;
}seq_string;

void strinsert(seq_string *S,int i,seq_string T)        //��˳���в���һ���ַ�
{
    int k;
    if(i < 0 || i > S->len + 1|| S->len + T.len > N)        //�����е�i��λ�ò��Ϸ���ʱ��
        printf("�����λ�ò��Ϸ�");
    else{
        for(k = S->len + 1;k >= i-1;k--)        //��Ҫ����Ԫ�غ����Ԫ���ƶ�����󣬿ճ�λ��
            S->str[T.len + k] = S->str[k];
        for(k = 0;k < T.len;k++)            //��Ҫ����������ȥ
            S->str[i+k-1] = T.str[k];
        S->len = S->len + T.len;        //�ı�����ĳ���
        S->str[S->len] = "\0";      //������Ǹ�λ��һ��������
    }
}

void strdelete(seq_string *S,int i,int lenght)     //��˳���еĵ�i��Ԫ����ɾ��len��Ԫ��
{
    int k;
    if(i < 0 || i > S->len || i + lenght-1 > S->len)       //ɾ����λ�÷Ƿ�
        printf("ɾ����λ�ò��Ϸ�");
    else{
        for(k = i+lenght-1;k < S->len;k++)      //��Ҫɾ��������ǰ��
            S->str[k->lenght] = S->str[k];
        S->len = S->len - lenght;       //�ı��ַ����ĳ���
        S->str[S->len] = '\0';          //�����һ���ַ�����������
    }
}

seq_string *strconcat(seq_string S1,seq_string S2)          //��������˳��
{
    int i;
    seq_string *r;          //����һ�����
    if(S1.len + S2.len > N-1){          //��������
        printf("����ʧ��");
        return NULL;
    }
    else{
        r = newNode;        //���½��Ľ�����ռ�
        for(i = 0;i < S1.len;i++)       //����һ��˳�򴮸��Ƶ��µ��ַ�����
            r->str[i] = S1.str[i];
        for(i = 0;i < S2->len;i++)      //���ڶ����ַ����ŵ��ַ�������ȥ
            r->str[str.len + i] = S2.str[i];
        r->len = S1.len + S2.len;       //�õ��µ��ַ�����ĳ���
        r->str[r->len] = '\0';
    }
    return r;
}

seq_string *substring(seq_string S,int i,int lenght)       //��˳���е��ִ���λ�úͳ���
{
    int k;
    seq_string *r;      //�����µĽ��
    if(i < 0 ||i > S.len || i + len-1 > S.len){         //�����λ�ò��Ϸ�
        printf("error");
        return NULL:
    }
    else{
        r = newNode;        //���µĽ�����ռ�
        for(k = 0;k < lenght;k++)       //��ȡ��i������г�Ϊlenght������
            r->str[k] = S.str[i+k-1];
        r->len = lenght;        //�ı��ַ�����ĳ���
        r->str[r->len] = '\0';
    }
    return r;
}
