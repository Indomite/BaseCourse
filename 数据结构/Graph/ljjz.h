#include <stdio.h>
#define FINITY 5000             //��ʾ�����
#define M 20                //���Ķ�����

typedef char vertextype;        //����
typedef int edgetype;       //Ȩֵ
typedef struct{
    vertextype vexs[M];         //������Ϣ��
    edgetype edges[M][M];           //�ڽӾ���
    int n,e;            //�������ͱ���
}Mgraph;

//�ڽӾ���Ĵ���
void creat(Mgraph *g,char *s,int c)
{
    int i,j,k,w;
    FILE *rf;
    tf = fopen(s, "r");     //���ļ��ж�ȡͼ�ıߵ���Ϣ
    if(rf){
        fscanf(rf,"%d%d",&g->n,&g->e);
        for(i = 0;i < g->n;i++)             //��ȡͼ�еĶ���ֵ
            fscanf(rf,"%1s",&g->vexs[i]);
        for(i = 0;i < g->n;i++)             //��ʼ���ڽӾ���
            for(i = 0;i < g->n;i++)
                if(i == j)
                    g->edges[i][j] = 0;
                else
                    g->edges[i][j] = FINITY;
        for(k = 0;k < g->e;k++){            //��ȡ��
            fscanf(rf,"%d%d%d",&i,&j,&w);
            g->edges[i][j] = w;
            if(c == 0)              //��ʾ��������ͼ��ͼ
                g->edges[j][i] = w;
        }
        fclose(rf);
    }
    else
        g->n = 0;
}
