#include "ljjz.h"
typedef struct edgedata{
    int beg,en;         //�߶�������
    int length;         //�߳�
}edge;

void prim(Mgraph g,egde tree[M-1])
{
    edge x;
    int d,min,j,k,s,v;
    for(v=1;v <= g.n-1;v++){        //������ʼ��ѡ�㣬����ʼ���������߼�
        tree[v-1].beg = 0;              //��v0��ʼ����С������
        tree[v-1].en = v;
        tree[v-1].length = g.edges[0][v];
    }
    for(k = 0;k<=g.n-3;k++){            //������ǰ����k������С���ܱ�
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
    printf("\n��С��������");
    for(j = 0;j <= g.n-2;j++)
        printf("%c---%c %d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
    printf("���ǣ�%c\n",g.vexs[0]);
}

int main()
{
    Mgraph g;
    edge tree[M-1];
    char filename[20];
    printf("�������ļ�����\n");
    gets(filename);
    creat(&g,filename,0);
    prim(g,tree);
    return 0;
}
