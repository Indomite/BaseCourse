#include ¡°seqlist.h¡±

int binsearch1(seqlist l,datatype key)
{
    int low=0,high=l.len-1,mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(l.data[mid]==key)
            return mid;
        if(l.data[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int binsearch2(seqlist l,datatype key,int low,int high)
{
    int mid,k;
    if(low > high)
        return -1;
    else{
        mid = (low+high)/2;
        if(l.data[mid] == key)
            return mid;
        if(l.data[mid]>key)
            return binsearch2(l,key,low,mid-1);
        else
            return binsearch2(l,key,mid+1,high);
    }
}
