#include <stdio.h>

//将奇数放在左边，偶数放在右边
partJiOu(int a[],int low,int high)
{
    if(low >= high)
        return -1;
    if(a[low]%2 == 1 && a[high]%2 == 0)             //1.左边是奇数，右边是偶数
        partJiOu(a,low+1,high-1);
    else if(a[low]%2 == 1 && a[high]%2 == 1)        //2.左边是奇数，右边是奇数
        partJiOu(a,low+1,high);
    else if(a[low]%2 == 0 && a[high]%2 == 1)        //3.左边是偶数，右边是奇数
        int temp;
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
        partJiOu(a,low-1,high-1);
    else if(a[low]%2 == 0 && a[high]%2 == 0)        //4.左边是偶数，右边是偶数
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
