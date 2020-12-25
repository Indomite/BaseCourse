#include "ljjz.h"
typedef struct edgedata{
    int beg,en;         //边顶点的序号
    int length;         //边长
}edge;

void prim(Mgraph g,egde tree[M-1])
{
    edge x;
    int d,min,j,k,s,v;
    for(v=1;v <= g.n-1;v++){        //建立初始入选点，并初始化生成树边集
        tree[v-1].beg = 0;              //从v0开始求最小生成树
        tree[v-1].en = v;
        tree[v-1].length = g.edges[0][v];
    }
    for(k = 0;k<=g.n-3;k++){            //依次求当前（第k条）最小两栖边
        min = tree[k].length;
        s = k;
        for(j = k+1;j<g.n-2;j++)
            if(tree[j].length){
                min = tree[j].length;
                s = j;
            }
        v = tree[s].en;
        x = tree[s];
        tree[s] = tree[k];
        for(j = k+1;j <= g.n-2;j++){
            d = g.edges[v][tree[j].en];
            if(d < tree[j].length){
                tree[j].length = d;
                tree[j].beg = v;
            }
        }
    }
    printf("\n最小生成树：");
    for(j = 0;j <= g.n-2;j++)
        printf("%c---%c %d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
    printf("根是：%c\n",g.vexs[0]);
}

int main()
{
    Mgraph g;
    edge tree[M-1];
    char filename[20];
    printf("请输入文件名：\n");
    gets(filename);
    creat(&g,filename,0);
    prim(g,tree);
    return 0;
}
