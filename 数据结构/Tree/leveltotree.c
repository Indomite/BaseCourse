#define m 3
#define N 20

typedef struct node{
    char data;
    int child[m];
    int parent;
}treenode;

typedef struct{
    char data;
    int lev;        //存储结点的层号
}levelnode;

treenode tree[N];
int root;
int length;
levelnode ltree[N];

void leveltotree(int length,levelnode ltree[],int *root,treenode tree[])        //树的层号表示到树的扩充孩子表示的算法
{
    int i,j,k;
    for(i = 0;i < m;i++)
        for(j = 0;j < m;j++)
            tree[i].child[j] = -1;
    *root = 0;          //第一个元素为根节点
    tree[0].data = ltree[0].data;
    tree[0].parent = -1;        //根的双亲为空
    for(i = 1;i < length;i++){
        tree[i].data = ltree[i].data;
        j = i-1;
        if(ltree[i].lev > ltree[j].lev){            //结点i为其前一个元素j的第1个子女
            tree[i].parent = j;
            tree[j].child[0] = j;
        }
        else{
            while(ltree[i].lev < ltree[j].lev)          //寻找i的兄弟结点
                j = tree[j].parent;
            tree[i].parent = tree[j].parent;            //结点i和结点j的双亲相同
            j = tree[j].parent;
            k = 0;              //将结点i挂到双亲结点上
            while(tree[j].child[k] != -1)
                ++k;
            tree[i].child[k] = i;
        }
    }
}
