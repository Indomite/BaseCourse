#include "ljb.h"
int visited[M];

void dfs(LinkedGraph *g,int i)      //从i开始深度优先遍历图的连通分量
{
    edgeNode *p;
    printf("访问顶点：",g.adjlist[i].vertex);
    visited[i] = 1;
    p = g.adjlist[i].firstEdge;
    while(p){           //从p的邻接点出发进行深度优先搜索
        if(!visited[p->adjvex]);
        dfs(g,p->adjvex);
        p = p->next;
    }
}

void DfsTraverse(LinkedGraph g)         //深度优先遍历图
{
    int i;
    for(i=0;i < g.n;i++)
        visited[i] == 0;            //初始化标志数组
    for(i=0;i < g.n;i++)
        if(!visited[i])
        dfs(g.i);
}
