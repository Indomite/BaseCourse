#include <stdio.h>
#include <stdlib.h>
#define newNode (linkStr *)malloc(sizeof(linkStr))

typedef struct k{
    char data;
    struct k *next;
}linkStr;

void strcreat(linkStr *S)       //链式字符串的创建
{
    char ch;
    linkStr *p,*r;
    *S = NULL;      //用r始终指向当前链式串的最后一个字符所对应的结点
    r = NULL;
    while((ch = getchar()) != '\n'){        //将从键盘获取的字符串添加到新结点后面
        p = newNode;
        p->data = ch;
        if(*S == NULL)
            *S = p;
        else
            r->next = p;
        r = p;
    }
    if(r != NULL)
        r->next = NULL;
}

void strinsert(linkStr *S,int i,linkStr T)      //在链式串中的第i个位置插入一个为T的字符串
{
    int k;
    linkStr *q,*p;
    p = *S,k = 1;
    while(p && k < i-1){        //给一个新的结点用于找到其中i的位置
        p = p->next;
        k++;
    }
    if(!p)      //如果没有找到i的位置
        printf('error\n');
    else{
        q = T;              //将T赋值给一个新的结点
        while(q && q->next)     //用q去找到T中的最后一个元素的位置
            q=q->next;
        q->next = p->next;      //将最后一个元素的位置给要插入元素前的元素原本的后一个元素
        p->next = T;
    }
}

void strdelete(linkStr *S,int i;int len)        //删除S中从第i个字符起长度为len的字串
{
    int k;
    linkStr *q,*p,*r;
    p = *S,q = NULL;k = 1;
    while(p && k < i){          //用p查找S中的第i个元素，q始终跟踪p的前驱
        q = p;
        p = p->next;
        k++;
    }
    if(!p)
        printf("error\n");      //S中的第i个元素不存在
    else{
        k = 1;
        while(k < len && p){        //从第i个元素开始找长度为len的子串
            p = p->next;
            k++;
        }
        if(!p)
            printf("error");
        else{
            if(!p){             //当被删除的子串位于S的最前面
                r = *S;
                *S= p->next;
            }else{
                r = q->next;
                q->next = p->next;
            }
            p->next = NULL;
            while(r != NULL){           //回收空间
                p = r;
                r = r->next;
                free(p);
            }
        }
    }
}

void strconcat(linkStr *S1,linkStr *S2)             //连接两个字符串
{
    linkStr *p;
    if(!(*S1)){             //考虑到第一个字符串为空的情况下
        *S1 = S2;
        return ;
    }
    else{
        if(S2){             //当两个字符串都不为空时
            p = *S1;
            while(p->next)          //当第一个字符串到了最后一个字符时
                p=p->next;
            p->next = S2;
        }
    }
}

linkStr *subString(linkStr *S,int i,int len)        //从S中的第i个位置取出长度为len的子串
{
    int k;
    linkStr *q,*p,*r,*t;
    p = S,k = 1;
    while(p && k < i){          //用p查找S中第i个字符
        p = p->next;
        k++;
    }
    if(!p){             //第i个字符不存在的情况
        printf("error");
        return NULL;
    }
    else{
        r = newNode;
        r->data = p->data;
        r->next = NULL;
        k = 1;q = r;
        while(p->next &&  k < len){             //取长度为len的字符串
            p = p->next;
            k++;
            t = newNode;        //用t保存p取出来的值
            t->data = p->data;
            q->data = t;
            q = t;
        }
        if(k < len){            //当起其长度不足len时
            printf("error\n");
            return NULL;
        }
        else{                   //处理尾部的字符串
            q->next = NULL;
            return r;
        }
    }
}
