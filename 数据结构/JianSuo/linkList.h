#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node{
    datatype data;
    struct node *next;
}linknode;
typedef linknode *linklist;

linklist linkSearch(linklist head,datatype key)             //���Ա��˳�����
{
    linklist p=head->next;
    while(p && p->next != key)
        p = p->next;
    return p;
}
