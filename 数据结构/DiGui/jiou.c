#include <stdio.h>

//������������ߣ�ż�������ұ�
partJiOu(int a[],int low,int high)
{
    if(low >= high)
        return -1;
    if(a[low]%2 == 1 && a[high]%2 == 0)             //1.������������ұ���ż��
        partJiOu(a,low+1,high-1);
    else if(a[low]%2 == 1 && a[high]%2 == 1)        //2.������������ұ�������
        partJiOu(a,low+1,high);
    else if(a[low]%2 == 0 && a[high]%2 == 1)        //3.�����ż�����ұ�������
        int temp;
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        partJiOu(a,low-1,high-1);
    else if(a[low]%2 == 0 && a[high]%2 == 0)        //4.�����ż�����ұ���ż��
        partJiOu(a,low,high-1);
}

partJiOu(int a[],int low,int high)
{
    if(low >= high)
        return -1;
    while(low < high && a[low]%2 == 1)
        low++;
    while(low < high && a[high]%2 == 0)
        high--;
    if(low < high){
        int temp;
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        partJiOu(a,low+1,high-1);
    }
}
