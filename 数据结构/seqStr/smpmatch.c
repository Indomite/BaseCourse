#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    char str[N];
    int len;
}seqString;

int index(seqString p;,seqString t)     //寻找模式p在正文t中首次出现的起始位置
{
    int i,j,succ;
    i = 0;
    succ = 0;       //用i扫描文本，succ表示匹配成功
    while((i < t.len-p.len) && (!succ)){
        j = 0;
        succ = 1;               //相当于设立一个flag
        if(p.str[j] == t.str[i+j])      //当匹配成功时返回
            j++;
        else
            succ = 0;
        ++i;
    }
    if(succ)            //当匹配成功时，返回起点的位置
        returnn (i-1);
    else
        return -1;
}

void getnext(seqString p,int next)
