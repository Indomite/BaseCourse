#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    int a[N];
    int front;
    int rear;
}seq_queue;

void init(seq_queue *sq)       //初始化队列
{
    sq->front = sq->rear = 0;
}

int empty(seq_queue sq)       //判断队列是否为空
{
    return (sq.front == sq.rear? 1:0);
}

void display(seq_queue sq)     //打印队列的结点值
{
    int i;
    if(empty(sq)){
        printf("\n队列是空的");
    }else
    for(i = sq.front;i < sq.rear;i++)
        printf("%5d",sq.a[i]);
}

int get(seq_queue sq)      //取得队首的结点值
{
    if(empty(sq)){
        printf("\n队列是空的");
        exit(1);
    }
    return sq.a[sq.front];
}

void insert(seq_queue *sq,int x)       //向队列中插入元素
{
    int i;
    if(sq->rear == N){
        printf("\n队列已满");
        exit(1);
    }
    sq->a[sq->rear] = x;
    sq->rear = sq->rear+1;
}

void delete(seq_queue *sq)
{
    if(sq->front == sq->rear){
        printf("\n队列是空的！不能删除");
        exit(1);
    }
    sq->front++;
}

//循环队列
void insert_cycle(seq_queue *sq,int x)
{
    if((sq->rear+1) % N == sq->front){
        printf("\n队列是满的，无法进行插入");
        exit(1);
    }
    sq->a[sq->rear] = x;
    sq->rear = (sq->rear+1) % N;
}

void delete_cycle(seq_queue *sq)
{
    if(sq->front == sq->rear){
        printf("\n队列是空的，无法删除");
        exit(1);
    }
    sq->front = (sq->front + 1) % N;
}

int main()
{
    seq_queue Q;
    init(&Q);
    //empty(Q);
    insert(&Q,6);
    insert(&Q,7);
    insert(&Q,8);
    insert_cycle(&Q,9);
    //delete(&Q);
    printf("队列中的元素有：");
    display(Q);
    return 0;
}
