#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    int a[N];
    int top;
}seq_stack;

void init(seq_stack *st)        //栈的初始化
{
    st->top = 0;
}

int empty(seq_stack st)     //判断栈是否为空
{
    return (st.top ? 0:1);
}

int readTopStack(seq_stack st)        //读取栈顶元素
{
    if(empty(st)){
        printf("\n栈是空的");
        exit(1);
    }else{
        printf("栈顶的元素为%d:",st.a[st.top-1]);
        return st.a[st.top-1];
    }
}

void readStack(seq_stack st)
{
    if(empty(st)){
        printf("\n栈是空的");
        exit(1);
    }else{
        for(int i = 0;i < st.top;i++)
            printf("%d ",st.a[i]);
    }
}

void push(seq_stack *st,int x)      //栈的插入操作
{
    if(st->top == N){
        printf("\n栈是满的");
        exit(1);
    }
    st->a[st->top] = x;
    st->top++;
}

void pop(seq_stack *st)
{
    if(st->top == 0){
        printf("\n栈是空的");
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
    printf("栈内元素有：");
    readStack(S);
    return 0;
}
