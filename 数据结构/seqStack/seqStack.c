#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    int a[N];
    int top;
}seq_stack;

void init(seq_stack *st)        //ջ�ĳ�ʼ��
{
    st->top = 0;
}

int empty(seq_stack st)     //�ж�ջ�Ƿ�Ϊ��
{
    return (st.top ? 0:1);
}

int readTopStack(seq_stack st)        //��ȡջ��Ԫ��
{
    if(empty(st)){
        printf("\nջ�ǿյ�");
        exit(1);
    }else{
        printf("ջ����Ԫ��Ϊ%d:",st.a[st.top-1]);
        return st.a[st.top-1];
    }
}

void readStack(seq_stack st)
{
    if(empty(st)){
        printf("\nջ�ǿյ�");
        exit(1);
    }else{
        for(int i = 0;i < st.top;i++)
            printf("%d ",st.a[i]);
    }
}

void push(seq_stack *st,int x)      //ջ�Ĳ������
{
    if(st->top == N){
        printf("\nջ������");
        exit(1);
    }
    st->a[st->top] = x;
    st->top++;
}

void pop(seq_stack *st)
{
    if(st->top == 0){
        printf("\nջ�ǿյ�");
        exit(1);
    }
    st->top--;
}

int main()
{
    seq_stack S;
    init((&S));
    //empty(S);
    push(&S,5);
    push(&S,6);
    push(&S,7);
    push(&S,8);
    pop(&S);
    printf("ջ��Ԫ���У�");
    readStack(S);
    return 0;
}
