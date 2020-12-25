//前序遍历二叉树的递归算法
void preorder(Btree t)
{
    if(t){
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

//前序遍历二叉树的非递归算法
void preorder1(Btree t)
{
    seqstack s;
    s.top = 0;
    while((t) || (s.top != 0)){
        if(t){
            printf("%c",t->data);
            push(&s,t);
            t = t->lchild;
        }
        else{
            t = pop(&s);            //如果左子树为空，从栈中取出右子树，再进行遍历
            t = t->rchild;
        }
    }
}

//中序遍历二叉树的递归算法
void inorder(Btree t)
{
    if(t){
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}

//中序遍历二叉树的非递归算法
void inorder1(Btree t)
{
    seqstack s;
    s.top = 0;
    while((t)!=NULL) || (s.top != 0)){
        if(t){
            push(&s,t);
            t = t->lchild;
        }else{
            t = pop(&s);
            printf("%c ",t->data);
            t = t->rchild;          //先访问左子树，所以左子树先入栈，然后出栈，输出左子树，根结点，在输出右子树
        }
    }
}

//后序遍历二叉树的递归算法
void postorder(Btree t)
{
    if(t){
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

//后序遍历二叉树的非递归算法
void postorder1(Btree t)
{
    seqstack s;
    s.top = 0;
    while((t) || t.top != 0){
        if(t){
            s.data[s.top] = t;
            s.tag[s.top] = 0;
            s.top++;
            t = t->lchild;
        }else if(s.tag[s.top - 1] == 1){
            s.top--;
            t = s.data[s.top];
            printf("%c ",t->data);
            t = NULL;
        }else{
            t = s.data[s.top - 1];
            s.tag[s.top - 1] = 1;
            t = t->rchild;
        }
    }
}
