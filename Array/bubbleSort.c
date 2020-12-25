#include "Array.h"
#define N 100

void bubbleSort(int a[],int n)
{
    int i,temp;
    while(n > 1){
        for(i = 0;i < n - 1; i++)
        if(a[i] > a[i+1]){
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
        n--;
    }
}

int main()
{
    int a[N];
    init(a,N);
    print(a,N);
    bubbleSort(a,N);
    print(a,N);
    return 0;
}
