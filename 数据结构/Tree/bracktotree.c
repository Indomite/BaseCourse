#define m 3
#define N 20        //树的孩子表示法对应的数组大小
#define M 50        //树的括号表示对应的数组大小

typedef struct node{        //孩子表示法
    char data;
    int child[m];
}treenode;
treenode tree[N];
int root;
int length;
char p[M];

void bracktotree(char p[],int *root,int *length,treenode tree[])        //将树的括号表示转换成树的孩子表示
{
    int stack[N];
    int top;
    int i,j,k,l,done;
    k = 0,j = 0,*root = 0;
    top = 0;done = 1;           //done为程序结束的标志，初始化操作
    tree[j].data = p[k];        //产生孩子表示法中的根节点
    k++;
    for(i = 0;i < m;i++)
        tree[j].child[i] = -1;
    while(done){
        if(p[k] == '('){            //遇到左括号，则其前面的元素对应的结点进栈
            stack[top] = j;
            ++top;
            ++k;
           }
        else if(p[k] == ')'){       //遇到右括号，栈顶元素出栈
            --top;
            if(top == 0)        //栈为空时算法结束
                done = 0;
            else
                ++k;
        }
        else if(p[k] == ',')
            ++k;
        else{           //将当前被扫描的元素作为栈顶元素的子女
            ++j;
            tree[j].data = p[k];
            for(i = 0;i < m;++i)
                tree[j].child[i] = -1;
            l = stack[top - 1];
            i = 0;
            while(tree[l].child[i] != -1)           //寻找栈顶元素当前的第1个空子女
                ++i;
            tree[l].child[i] = j;
            ++k;
        }
    }
    *length = j+1;
}
