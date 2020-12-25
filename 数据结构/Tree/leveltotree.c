#define m 3
#define N 20

typedef struct node{
    char data;
    int child[m];
    int parent;
}treenode;

typedef struct{
    char data;
    int lev;        //�洢���Ĳ��
}levelnode;

treenode tree[N];
int root;
int length;
levelnode ltree[N];

void leveltotree(int length,levelnode ltree[],int *root,treenode tree[])        //���Ĳ�ű�ʾ���������亢�ӱ�ʾ���㷨
{
    int i,j,k;
    for(i = 0;i < m;i++)
        for(j = 0;j < m;j++)
            tree[i].child[j] = -1;
    *root = 0;          //��һ��Ԫ��Ϊ���ڵ�
    tree[0].data = ltree[0].data;
    tree[0].parent = -1;        //����˫��Ϊ��
    for(i = 1;i < length;i++){
        tree[i].data = ltree[i].data;
        j = i-1;
        if(ltree[i].lev > ltree[j].lev){            //���iΪ��ǰһ��Ԫ��j�ĵ�1����Ů
            tree[i].parent = j;
            tree[j].child[0] = j;
        }
        else{
            while(ltree[i].lev < ltree[j].lev)          //Ѱ��i���ֵܽ��
                j = tree[j].parent;
            tree[i].parent = tree[j].parent;            //���i�ͽ��j��˫����ͬ
            j = tree[j].parent;
            k = 0;              //�����i�ҵ�˫�׽����
            while(tree[j].child[k] != -1)
                ++k;
            tree[i].child[k] = i;
        }
    }
}
