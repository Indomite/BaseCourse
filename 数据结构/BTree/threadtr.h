typedef char datatype;
typedef struct node{
    datatype data;
    int ltag,rtag;
    struct node *lchild,*rchild;
}Bthrnode;
Bthrnode * BthrTree;

//创建中序穿线二叉树
BthrTree pre = NULL;
BthrTree createbintree()        //按谦虚前序遍历创建二叉树
{
    char ch;
    BthrTree t;
    if((ch = getchar()) == '#')
        return NULL;
    else{
        t = (Bthrnode *)malloc(sizeof(Bthrnode));
        t->data = ch;
        t->lchild = creatrbintree();
        t->rchild = creatrbintree();
    }
    return t;
}

//对二叉树进行中序线索化
void inthreading(BthrTree *p)
{
    if(*p){
        inthreading(&((*p)->lchild));           //中序线索化左子树
        (*p)->ltag = ((*p)->lchild) ? 0:1;          //对当前结点及其前驱结点进行穿线
        (*p)->rtag = ((*p)->rchild) ? 0:1;
        if(pre){
            if(pre->rtag == 1)
                pre->rchild = *p;
            if((*p)->ltag == 1)
                (*p)->lchild = pre;
        }
        pre = *p;
        inthreading(&((*p)->rchild));
    }
}


//创建中序穿线二叉树
void createthrtree(BthrTree *p)
{
    *p = createthrtree();
    inthreading(p);
}

//中序遍历中序穿线二叉树
BthrTree insuccnode(BthrTree p)         //寻找结点p在中序遍历下的后继结点
{
    BthrTree q;
    if(p->rtag == 1)
        return p->rchild;
    else{
        q = p->rchild;
        while(q->ltag == 0)
            q = q->lchild;
        return q;
    }
}

//中序遍历中序穿线二叉树
void inthrtree(BthrTree p)
{
    if(p){
        while(p->ltag == 0)
            p = p->lchild;
        do{
            printf("%c ",p->data);
            p = inthrtree(p);
        }
        while(p);
    }
}

int main()
{
    BthrTree t;
    createthrtree(&root);
}
