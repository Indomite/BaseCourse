//ʵ�ֶ������Ĳ���
Btree locate(Btree t,datatype x)
{
    Btree p;
    if(t == NULL)
        return NULL;
    else if(t->data == x)
        return t;
    else{
        p = locate(t->lchild,x);
        if(p)
            return p;               //��������������ҵ���㣬�򷵻أ����򣬵ݹ����������
        else
            return locate(t->rchild,x);
    }
}

//ͳ�ƶ������н��ĸ���
int numofnode(Btree t)
{
    if(t == NULL)
        return NULL;
    else
        return (numofnode(t->lchild) + numofnode(t->rchild) + 1);
}

//�ж϶������Ƿ����
int isequal(Btree t1,Btree t2)
{
    int t;
    t = 0;
    if(t1 == NULL && t2 == NULL)        //������������Ϊ��ʱ
        t = 1;
    else if(t1 != NULL && t2 != NULL)
        if(t1->data == t2->data)
            if(isequal(t1->lchild,t2->lchild))          //��������ȫ���ʱ��ȥ�ж�������
                t = isequal(t1->rchild,t2->rchild);         //ֻ�е��������������ʱ�ŷ���ֵ
    return t;
}

//������������
int depth(Btree t)
{
    int h,lh,rh;
    if(t == NULL)
        h = 0;
    else{
        lh = depth(t->lchild);
        rh = depth(t->rchild);
        if(lh >= rh)            //�ֱ�õ����������ĸ߶ȣ��������ֵ���ϸ����
            h = lh + 1;
        else
            return rh + 1;
    }
    return h;
}
