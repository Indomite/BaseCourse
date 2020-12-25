typedef char datatype;
typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
}Bnode;

typedef Bnode * Btree;
Btree root;             //定义根结点
