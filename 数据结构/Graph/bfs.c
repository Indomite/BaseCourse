#include "ljb.h"
int visited[M]

void bfs(LinkedGraph g,int i)
{
    int j;
    edgeNode *p;
    int queue[M],front,rear;
    front = rear = 0;
    printf("%c ",g.adjlist[i].vertex);
    visited[i] = 1;
    queue[rear ++] = i;
    while(rear > front){
        j = queue[front++];
        p = g,adjlist[j].firstEdge;
            while(p){
            if(visited[p->adjtex] == 0){
                printf("%c ",g.adjlist[p->adjvex].vertex);
                queue[rear++] = p->adjvex;
                visited[p->adjtex] = 1;
            }
            p = p->next;
        }
    }
}

int BfsTraverse(LinkedGraph g)
{
    int i,count = 0;
    for(i = 0;i < g.n;i++)
        visited[i] = 0;
    for(i = 0;i <g.n;i++)
    if(!visited[i]){
        printf("\n");
        count++;
        bfs(g,i);
    }
    return count;
}

int main()
{
    LinkedGraph g;
    int count;
    creat(&g,"",0);
    printf("ͼΪ��");
    print(g);
    count = BfsTraverse(g);
    printf("ͼ��%d����ͨ����",count);
    return 0;
}
