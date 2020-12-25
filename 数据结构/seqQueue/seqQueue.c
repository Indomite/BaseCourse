#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct{
    int a[N];
    int front;
    int rear;
}seq_queue;

void init(seq_queue *sq)       //��ʼ������
{
    sq->front = sq->rear = 0;
}

int empty(seq_queue sq)       //�ж϶����Ƿ�Ϊ��
{
    return (sq.front == sq.rear? 1:0);
}

void display(seq_queue sq)     //��ӡ���еĽ��ֵ
{
    int i;
    if(empty(sq)){
        printf("\n�����ǿյ�");
    }else
    for(i = sq.front;i < sq.rear;i++)
        printf("%5d",sq.a[i]);
}

int get(seq_queue sq)      //ȡ�ö��׵Ľ��ֵ
{
    if(empty(sq)){
        printf("\n�����ǿյ�");
        exit(1);
    }
    return sq.a[sq.front];
}

void insert(seq_queue *sq,int x)       //������в���Ԫ��
{
    int i;
    if(sq->rear == N){
        printf("\n��������");
        exit(1);
    }
    sq->a[sq->rear] = x;
    sq->rear = sq->rear+1;
}

void delete(seq_queue *sq)
{
    if(sq->front == sq->rear){
        printf("\n�����ǿյģ�����ɾ��");
        exit(1);
    }
    sq->front++;
}

//ѭ������
void insert_cycle(seq_queue *sq,int x)
{
    if((sq->rear+1) % N == sq->front){
        printf("\n���������ģ��޷����в���");
        exit(1);
    }
    sq->a[sq->rear] = x;
    sq->rear = (sq->rear+1) % N;
}

void delete_cycle(seq_queue *sq)
{
    if(sq->front == sq->rear){
        printf("\n�����ǿյģ��޷�ɾ��");
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
    printf("�����е�Ԫ���У�");
    display(Q);
    return 0;
}
