#include "seqlist.h"
typedef struct{
    datatype key;
    int address;
}indexnode;

int IndexSearch(seqlist l,indxnode index[],int m,datatype key)
{
    int i=0,j,last;
    while(i < m && key > index[i].key)
        i++;
    if(i >= m)
        return -1;
    else{
        if(i == m-1)
            j=l.len-1;
        else
            j=index[i+1].address-1;
        while(j>=index[i].address && key!=l.data[j])
            j--;
        if(j<index[i].address)
            return -1;
        else
            return j;
    }
}
