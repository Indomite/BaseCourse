//����һ��ջ�ṹ

typedef struct stack{
    Btree data[100];
    int tag[100];               //Ϊջ��ÿ��Ԫ�����õı�ǣ����ں������
    int top;                //ջ��ָ��
}seqstack;

void push(seqstack *s,Btree t)
{
    s->data[s->top] = t;
    s->top++;
}

void pop(seqstack *s)
{
    if(s->top != o){
        s->top--;
        return (s->data[s->top]);
    }else
    return NULL;
}
