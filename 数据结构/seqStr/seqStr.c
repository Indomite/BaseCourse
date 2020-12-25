#include <stdio.h>
#include <stdlib.h>
#define N 100
#define newNode (seq_string *)malloc(sizeof(seq_string))

typedef struct{
    char str[N];
    int len;
}seq_string;

void strinsert(seq_string *S,int i,seq_string T)        //在顺序串中插入一段字符
{
    int k;
    if(i < 0 || i > S->len + 1|| S->len + T.len > N)        //当其中的i的位置不合法的时候
        printf("插入的位置不合法");
    else{
        for(k = S->len + 1;k >= i-1;k--)        //将要插入元素后面的元素移动到最后，空出位置
            S->str[T.len + k] = S->str[k];
        for(k = 0;k < T.len;k++)            //将要插入的数添进去
            S->str[i+k-1] = T.str[k];
        S->len = S->len + T.len;        //改变数组的长度
        S->str[S->len] = "\0";      //给最后那个位置一个结束符
    }
}

void strdelete(seq_string *S,int i,int lenght)     //从顺序串中的第i个元素起删除len个元素
{
    int k;
    if(i < 0 || i > S->len || i + lenght-1 > S->len)       //删除的位置非法
        printf("删除的位置不合法");
    else{
        for(k = i+lenght-1;k < S->len;k++)      //将要删除的数往前移
            S->str[k->lenght] = S->str[k];
        S->len = S->len - lenght;       //改变字符串的长度
        S->str[S->len] = '\0';          //将最后一个字符串赋结束符
    }
}

seq_string *strconcat(seq_string S1,seq_string S2)          //连接两个顺序串
{
    int i;
    seq_string *r;          //创建一个结点
    if(S1.len + S2.len > N-1){          //超出长度
        printf("连接失败");
        return NULL;
    }
    else{
        r = newNode;        //给新建的结点分配空间
        for(i = 0;i < S1.len;i++)       //将第一个顺序串复制到新的字符数组
            r->str[i] = S1.str[i];
        for(i = 0;i < S2->len;i++)      //将第二个字符串放到字符数组中去
            r->str[str.len + i] = S2.str[i];
        r->len = S1.len + S2.len;       //得到新的字符数组的长度
        r->str[r->len] = '\0';
    }
    return r;
}

seq_string *substring(seq_string S,int i,int lenght)       //求顺序串中的字串的位置和长度
{
    int k;
    seq_string *r;      //创建新的结点
    if(i < 0 ||i > S.len || i + len-1 > S.len){         //插入的位置不合法
        printf("error");
        return NULL:
    }
    else{
        r = newNode;        //给新的结点分配空间
        for(k = 0;k < lenght;k++)       //获取第i个结点中长为lenght的数组
            r->str[k] = S.str[i+k-1];
        r->len = lenght;        //改变字符数组的长度
        r->str[r->len] = '\0';
    }
    return r;
}
