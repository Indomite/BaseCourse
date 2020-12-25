typedef char datatype;
typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
    struct node *parent;            //用于指向双亲的指针
}Bnode;

typedef Bnode * Btree;
Btree root;
