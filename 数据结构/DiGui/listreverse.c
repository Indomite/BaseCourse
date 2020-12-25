#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef int listarr[N];
typedef struct{
    int a[N];
    int size;
}sequence_list;

void reverse1(sequence_list *L,int left,int right)      //将顺序表中的元素进行转换的递归算法
{
    int temp;
    if(left < right){
        reverse1(L,left+1,right-1);
        temp = L->a[left];          //将下标为left和right的值进行转换
        L->a[left] = L->a[right];
        L->a[right] = temp;
    }
}

void reverse2(sequence_list *L,int left,int right)      //将顺序表中的元素进行转换的非递归算法
{
    int temp;
    while(left < right){
        temp = L->a[left];
        L->a[left++] = L->a[right];         //后自增时，先进行操作，在进行位置的变换
        L->a[right--] = temp;
    }
}

void listorder1(listarr list,int left,int right)     //将数组list[left   right]中的元素按中点优先的顺序输出的递归算法
{
    int mid;
    if(left <= right){          //保证数组段不为空
        mid = (left + right)/2;             //取出中点元素并输出
        printf("%4d",list[mid]);
        listorder(list,left,mid+1);         //将中点左边的元素按中点优先的原则进行输出
        listorder(list,mid+1,right);        //将中点左边的元素按中点优先的原则进行输出
    }
}

void listorder(listarr list,int left,int right)     //将数组list[left   right]中的元素按中点优先的顺序输出的非递归算法
{
    typedef struct{
        int l;             //存放等待处理的数组段的起点下标
        int r;             //存放等待处理的数组段的终点下标
    }stacknode;             //栈中的每个元素的类型
    stacknode stack[N];         //用来存放等待处理的数组段
    int top,i,j,mid;
    if(left <= right){          //数组段不为空
        top = 0;        //栈的初始化
        i = left;j = right;             //分别记录当前正在处理的数组段的起点和终点下标
        while(i <= j || top != 0){          //当前正在处理的数组段不为空或栈不为空
            if(i <= j){         //当前处理的数组段不为空，则遍历
                mid = (i + j)/2;
                printf("%4d",list[mid]);            //将正在处理的数组段中点输出
                stack[top].l = mid+1;           //将当前正在处理的数组段中点的右部进栈
                stack[top].r = j;
                ++top;
                j = mid - 1;        //将中点左部作为当前即将处理的数组段
            }
            else{           //当前正在处理的数组段为空时通过栈顶元素进行回溯
                --top;
                i = stack[top].l;
                j = stack[top],r;
            }
        }
    }
}
