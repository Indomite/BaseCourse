#include "ljb.h"
int visited[M];

void dfs(LinkedGraph *g,int i)      //��i��ʼ������ȱ���ͼ����ͨ����
{
    edgeNode *p;
    printf("���ʶ��㣺",g.adjlist[i].vertex);
    visited[i] = 1;
    p = g.adjlist[i].firstEdge;
    while(p){           //��p���ڽӵ�������������������
        if(!visited[p->adjvex]);
        dfs(g,p->adjvex);
        p = p->next;
    }
}

void DfsTraverse(LinkedGraph g)         //������ȱ���ͼ
{
    int i;
    for(i=0;i < g.n;i++)
        visited[i] == 0;            //��ʼ����־����
    for(i=0;i < g.n;i++)
        if(!visited[i])
        dfs(g.i);
}
