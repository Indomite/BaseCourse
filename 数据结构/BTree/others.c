//实现二叉树的查找
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
            return p;               //如果在左子树中找到结点，则返回，否则，递归遍历右子树
        else
            return locate(t->rchild,x);
    }
}

//统计二叉树中结点的个数
int numofnode(Btree t)
{
    if(t == NULL)
        return NULL;
    else
        return (numofnode(t->lchild) + numofnode(t->rchild) + 1);
}

//判断二叉树是否相等
int isequal(Btree t1,Btree t2)
{
    int t;
    t = 0;
    if(t1 == NULL && t2 == NULL)        //当左右子树均为空时
        t = 1;
    else if(t1 != NULL && t2 != NULL)
        if(t1->data == t2->data)
            if(isequal(t1->lchild,t2->lchild))          //当左子树全相等时，去判读右子树
                t = isequal(t1->rchild,t2->rchild);         //只有当左右子树都相等时才返回值
    return t;
}

//求二叉树的深度
int depth(Btree t)
{
    int h,lh,rh;
    if(t == NULL)
        h = 0;
    else{
        lh = depth(t->lchild);
        rh = depth(t->rchild);
        if(lh >= rh)            //分别得到左右子树的高度，再求最大值加上根结点
            h = lh + 1;
        else
            return rh + 1;
    }
    return h;
}
