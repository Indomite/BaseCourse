#include "Array.h"
#define N 100

//����������
int findMax(int a[],int n)
{
    int i,max;
    max = a[0];
    for(i = 1;i < n; i++){
        if(a[i] > max)
            max = a[i];
        //maxIndex = i;   ������������±�
    }
    return max;
}

int main()
{
    int a[N],n;
    init(a,N);
    print(a,N);
    printf("�������ǣ�");
    n = findMax(a,N);
    printf("%d",n);
    return 0;
}
