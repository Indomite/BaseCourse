typedef char datatype;
typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
    struct node *parent;            //����ָ��˫�׵�ָ��
}Bnode;

typedef Bnode * Btree;
Btree root;
