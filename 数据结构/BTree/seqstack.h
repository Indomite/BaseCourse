//定义一个栈结构

typedef struct stack{
    Btree data[100];
    int tag[100];               //为栈中每个元素设置的标记，用于后序遍历
    int top;                //栈顶指针
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
