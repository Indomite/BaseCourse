#include <stdio.h>
#include <stdlib.h>
#define newNode (linkStr *)malloc(sizeof(linkStr))

typedef struct k{
    char data;
    struct k *next;
}linkStr;

void strcreat(linkStr *S)       //��ʽ�ַ����Ĵ���
{
    char ch;
    linkStr *p,*r;
    *S = NULL;      //��rʼ��ָ��ǰ��ʽ�������һ���ַ�����Ӧ�Ľ��
    r = NULL;
    while((ch = getchar()) != '\n'){        //���Ӽ��̻�ȡ���ַ�����ӵ��½�����
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

void strinsert(linkStr *S,int i,linkStr T)      //����ʽ���еĵ�i��λ�ò���һ��ΪT���ַ���
{
    int k;
    linkStr *q,*p;
    p = *S,k = 1;
    while(p && k < i-1){        //��һ���µĽ�������ҵ�����i��λ��
        p = p->next;
        k++;
    }
    if(!p)      //���û���ҵ�i��λ��
        printf('error\n');
    else{
        q = T;              //��T��ֵ��һ���µĽ��
        while(q && q->next)     //��qȥ�ҵ�T�е����һ��Ԫ�ص�λ��
            q=q->next;
        q->next = p->next;      //�����һ��Ԫ�ص�λ�ø�Ҫ����Ԫ��ǰ��Ԫ��ԭ���ĺ�һ��Ԫ��
        p->next = T;
    }
}

void strdelete(linkStr *S,int i;int len)        //ɾ��S�дӵ�i���ַ��𳤶�Ϊlen���ִ�
{
    int k;
    linkStr *q,*p,*r;
    p = *S,q = NULL;k = 1;
    while(p && k < i){          //��p����S�еĵ�i��Ԫ�أ�qʼ�ո���p��ǰ��
        q = p;
        p = p->next;
        k++;
    }
    if(!p)
        printf("error\n");      //S�еĵ�i��Ԫ�ز�����
    else{
        k = 1;
        while(k < len && p){        //�ӵ�i��Ԫ�ؿ�ʼ�ҳ���Ϊlen���Ӵ�
            p = p->next;
            k++;
        }
        if(!p)
            printf("error");
        else{
            if(!p){             //����ɾ�����Ӵ�λ��S����ǰ��
                r = *S;
                *S= p->next;
            }else{
                r = q->next;
                q->next = p->next;
            }
            p->next = NULL;
            while(r != NULL){           //���տռ�
                p = r;
                r = r->next;
                free(p);
            }
        }
    }
}

void strconcat(linkStr *S1,linkStr *S2)             //���������ַ���
{
    linkStr *p;
    if(!(*S1)){             //���ǵ���һ���ַ���Ϊ�յ������
        *S1 = S2;
        return ;
    }
    else{
        if(S2){             //�������ַ�������Ϊ��ʱ
            p = *S1;
            while(p->next)          //����һ���ַ����������һ���ַ�ʱ
                p=p->next;
            p->next = S2;
        }
    }
}

linkStr *subString(linkStr *S,int i,int len)        //��S�еĵ�i��λ��ȡ������Ϊlen���Ӵ�
{
    int k;
    linkStr *q,*p,*r,*t;
    p = S,k = 1;
    while(p && k < i){          //��p����S�е�i���ַ�
        p = p->next;
        k++;
    }
    if(!p){             //��i���ַ������ڵ����
        printf("error");
        return NULL;
    }
    else{
        r = newNode;
        r->data = p->data;
        r->next = NULL;
        k = 1;q = r;
        while(p->next &&  k < len){             //ȡ����Ϊlen���ַ���
            p = p->next;
            k++;
            t = newNode;        //��t����pȡ������ֵ
            t->data = p->data;
            q->data = t;
            q = t;
        }
        if(k < len){            //�����䳤�Ȳ���lenʱ
            printf("error\n");
            return NULL;
        }
        else{                   //����β�����ַ���
            q->next = NULL;
            return r;
        }
    }
}
