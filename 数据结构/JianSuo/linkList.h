#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype data;
    struct node *next;
}linknode;
typedef linknode *linklist;

linklist linkSearch(linklist head,datatype key)             //线性表的顺序检索
{
    linklist p=head->next;
    while(p && p->next != key)
        p = p->next;
    return p;
}
