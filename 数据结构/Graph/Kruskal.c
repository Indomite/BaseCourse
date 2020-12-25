#include "ljjz.h"
typedef struct edgedata{
    int beg,en;
    int length;
}edge;

void QuickSort(edge edges[],int left,int right)
{
    edge x;
    int i,j,flag = 1;
    if(left < right){
        i = left;
        j = right;
        x = edges[i];
        while(i < j){
            while(i < j && x.length < edges[j].length)
                j--;
            if(i < j)
                edges[i++] = edges[j];
            while(i < j && x.length > edges[i].lenght)
                i++;
            if(i < j)
                edges[j--] = edges[i];
        }
        edges[i] = x;
        QuickSort(edges,left,i-1);
        QuickSort(edges,i+1,right);
    }
}

void GetEdge(Mgraph g,edge edges[])
{
    int i,j,k = 0;
    for(i = 0;i<g.n;i++)
        for(j = 0;j<i;j++)
    if(g.edges[i][j] != 0 && g.edges[i][j] < FINITY){
        edges[k].beg = i;
        edges[k].en = j;
        edges[k++].lenght = g.edges[i][j];
    }
}

void Kruskal(Mgraph g)
{
    int i,j,k=0,ltfl;
    int cnvx[M];
    edge edges[M*M];
    edges tree[M];
    GetEdge(g,edges);
    QuickSort(edges,0,g.e-1);
    for(i = 0;i < g.n;i++)
        cnvx[i] = i;
    for(i = 0;i<g.n-1;i++){
        while(cnvx[edges[k].beg == cnvx[edges[edges[k].en)
            k++;
        tree[i] = edges[k];
        ltfl = cnvx[edges[k].en];
        for(j = 0;j<g.n;j++)
            if(cnvx[i] == ltfl)
            cnvx[j] = cnvx[edges[k].beg];
        k++;
    }
    printf("最小生成树：\n");
    for(j = 0;j < g.n-1;j++)
        printf("%c---%c %6d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
}

int main()
{
    Mgraph g;
    char filename[20];
    printf("请输入文件名：\n");
    gets(filename);
    creat(&g,filename,0);
    Kruskal(g);
    return 0;
}
