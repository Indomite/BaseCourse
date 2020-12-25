//´´½¨¶ş²æÊ÷

Btree creatBtree()
{
    char ch;
    Btree t;
    if((ch = getchar()) == '#')
        t = NULL;
    else{
        t = (Btree)malloc(sizeof(Bnode));
        t->data = ch;
        t->lchild = creatBtree();
        t->rchild = creatBtree();
    }
    return t;
}
