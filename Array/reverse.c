#include "Array.h"
#define N 100

//Êı×éµÄµ¹ÖÃ
void reverse(int a[],int n)
{
    int i = 0,j = n-1,temp;
    while(i < j){
        temp = a[i];
        a[i++] = a[j];
        a[j--] = temp;
    }
}

int main()
{
    int a[N];
    init(a,N);
    print(a,N);
    reverse(a,N);
    print(a,N);
    return 0;
}
