#include "Array.h"
#define N 100

int selectSort(int a[],int n)
{
    int i,j,minIndex,temp;
    for(i = 0;i < n - 1; i++){
        minIndex = i;
        for(j = i + 1; j < n; j++)
            if(a[j] < a[minIndex])
                minIndex = j;
        if(minIndex != i){
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main()
{
    int a[N];
    init(a,N);
    print(a,N);
    selectSort(a,N);
    print(a,N);
    return 0;
}
