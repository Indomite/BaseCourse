#include <stdio.h>
#define maxsize 100
typedef int datatype;
typedef struct{
    datatype data[maxsize];
    int len;
}seqlist;

int seaSearch(seqlist l,datatype key)           //���Ա��˳�����
{
    int k=l.len-1;
    while(k >= 0 && l.data != key)
        k--;
    return k;
}
