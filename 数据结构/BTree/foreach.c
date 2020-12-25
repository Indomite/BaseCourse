//ǰ������������ĵݹ��㷨
void preorder(Btree t)
{
    if(t){
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

//ǰ������������ķǵݹ��㷨
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
            t = pop(&s);            //���������Ϊ�գ���ջ��ȡ�����������ٽ��б���
            t = t->rchild;
        }
    }
}

//��������������ĵݹ��㷨
void inorder(Btree t)
{
    if(t){
        inorder(t->lchild);
        printf("%c",t->data);
        inorder(t->rchild);
    }
}

//��������������ķǵݹ��㷨
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
            t = t->rchild;          //�ȷ�������������������������ջ��Ȼ���ջ�����������������㣬�����������
        }
    }
}

//��������������ĵݹ��㷨
void postorder(Btree t)
{
    if(t){
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

//��������������ķǵݹ��㷨
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
