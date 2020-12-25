#include <stdio.h>
#include <stdlib.h>
#define M 20

typedef char datatype;
typedef struct node{
    int adjvex;
    struct node *next;
}edgeNode;          //边表结点

typedef struct vnode{
    datatype vertex;
    edgeNode *fiastEdge;
}vertexNode;        //头结点

typedef struct{
    vertexNode adjlist[M];
    int n,e;
}LinkedGraph;       //邻接表

void creat(LinkedGraph *g,char *filename,int c)
{
    int i,j,k;
    edgeNode *s;
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp){
        fscanf(fp,"%d%d",&g->n,&g->e);
        for(i=0;i < g->n;i++){
            fscanf(fp,"%1s",&g->adjlist[i].vertex);
            g->adjlist[i].firstEdge = NULL;
        }
        for(k=0;k < g->e;k++){
            fscanf(fp,"%d%d",&i,&j);
            s = (edgeNode *)malloc(sizeof(edgeNode));
            s->adjlist = j;
            s->next = g->adjlist[i],firstEdge;
            g->adjlist[i].firstEdge = s;
            if(c == 0){             //创建无向图
                s = (edgeNode *)malloc(sizeof(edgeNode));
                s->adjlist[j].firstEdge;
                g->adjlist[j].firstEdge = s;
            }
        }
        fclose(fp);
    }
    else
        g->n = 0;
}
