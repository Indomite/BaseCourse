typedef char datatype;
typedef struct node{
    datatype data;
    int ltag,rtag;
    struct node *lchild,*rchild;
}Bthrnode;
Bthrnode * BthrTree;

//���������߶�����
BthrTree pre = NULL;
BthrTree createbintree()        //��ǫ��ǰ���������������
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

//�Զ�������������������
void inthreading(BthrTree *p)
{
    if(*p){
        inthreading(&((*p)->lchild));           //����������������
        (*p)->ltag = ((*p)->lchild) ? 0:1;          //�Ե�ǰ��㼰��ǰ�������д���
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


//���������߶�����
void createthrtree(BthrTree *p)
{
    *p = createthrtree();
    inthreading(p);
}

//������������߶�����
BthrTree insuccnode(BthrTree p)         //Ѱ�ҽ��p����������µĺ�̽��
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

//������������߶�����
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
