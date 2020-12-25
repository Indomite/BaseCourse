#define m 3
#define N 20        //���ĺ��ӱ�ʾ����Ӧ�������С
#define M 50        //�������ű�ʾ��Ӧ�������С

typedef struct node{        //���ӱ�ʾ��
    char data;
    int child[m];
}treenode;
treenode tree[N];
int root;
int length;
char p[M];

void bracktotree(char p[],int *root,int *length,treenode tree[])        //���������ű�ʾת�������ĺ��ӱ�ʾ
{
    int stack[N];
    int top;
    int i,j,k,l,done;
    k = 0,j = 0,*root = 0;
    top = 0;done = 1;           //doneΪ��������ı�־����ʼ������
    tree[j].data = p[k];        //�������ӱ�ʾ���еĸ��ڵ�
    k++;
    for(i = 0;i < m;i++)
        tree[j].child[i] = -1;
    while(done){
        if(p[k] == '('){            //���������ţ�����ǰ���Ԫ�ض�Ӧ�Ľ���ջ
            stack[top] = j;
            ++top;
            ++k;
           }
        else if(p[k] == ')'){       //���������ţ�ջ��Ԫ�س�ջ
            --top;
            if(top == 0)        //ջΪ��ʱ�㷨����
                done = 0;
            else
                ++k;
        }
        else if(p[k] == ',')
            ++k;
        else{           //����ǰ��ɨ���Ԫ����Ϊջ��Ԫ�ص���Ů
            ++j;
            tree[j].data = p[k];
            for(i = 0;i < m;++i)
                tree[j].child[i] = -1;
            l = stack[top - 1];
            i = 0;
            while(tree[l].child[i] != -1)           //Ѱ��ջ��Ԫ�ص�ǰ�ĵ�1������Ů
                ++i;
            tree[l].child[i] = j;
            ++k;
        }
    }
    *length = j+1;
}
