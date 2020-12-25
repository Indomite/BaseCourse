#include <stdio.h>
#define FINITY 5000             //表示无穷大
#define M 20                //最大的顶点数

typedef char vertextype;        //顶点
typedef int edgetype;       //权值
typedef struct{
    vertextype vexs[M];         //顶点信息域
    edgetype edges[M][M];           //邻接矩阵
    int n,e;            //顶点数和边数
}Mgraph;

//邻接矩阵的创建
void creat(Mgraph *g,char *s,int c)
{
    int i,j,k,w;
    FILE *rf;
    tf = fopen(s, "r");     //从文件中读取图的边的信息
    if(rf){
        fscanf(rf,"%d%d",&g->n,&g->e);
        for(i = 0;i < g->n;i++)             //读取图中的顶点值
            fscanf(rf,"%1s",&g->vexs[i]);
        for(i = 0;i < g->n;i++)             //初始化邻接矩阵
            for(i = 0;i < g->n;i++)
                if(i == j)
                    g->edges[i][j] = 0;
                else
                    g->edges[i][j] = FINITY;
        for(k = 0;k < g->e;k++){            //读取边
            fscanf(rf,"%d%d%d",&i,&j,&w);
            g->edges[i][j] = w;
            if(c == 0)              //表示建立无向图向图
                g->edges[j][i] = w;
        }
        fclose(rf);
    }
    else
        g->n = 0;
}
