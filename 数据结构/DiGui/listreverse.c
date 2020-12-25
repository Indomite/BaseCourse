#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef int listarr[N];
typedef struct{
    int a[N];
    int size;
}sequence_list;

void reverse1(sequence_list *L,int left,int right)      //��˳����е�Ԫ�ؽ���ת���ĵݹ��㷨
{
    int temp;
    if(left < right){
        reverse1(L,left+1,right-1);
        temp = L->a[left];          //���±�Ϊleft��right��ֵ����ת��
        L->a[left] = L->a[right];
        L->a[right] = temp;
    }
}

void reverse2(sequence_list *L,int left,int right)      //��˳����е�Ԫ�ؽ���ת���ķǵݹ��㷨
{
    int temp;
    while(left < right){
        temp = L->a[left];
        L->a[left++] = L->a[right];         //������ʱ���Ƚ��в������ڽ���λ�õı任
        L->a[right--] = temp;
    }
}

void listorder1(listarr list,int left,int right)     //������list[left   right]�е�Ԫ�ذ��е����ȵ�˳������ĵݹ��㷨
{
    int mid;
    if(left <= right){          //��֤����β�Ϊ��
        mid = (left + right)/2;             //ȡ���е�Ԫ�ز����
        printf("%4d",list[mid]);
        listorder(list,left,mid+1);         //���е���ߵ�Ԫ�ذ��е����ȵ�ԭ��������
        listorder(list,mid+1,right);        //���е���ߵ�Ԫ�ذ��е����ȵ�ԭ��������
    }
}

void listorder(listarr list,int left,int right)     //������list[left   right]�е�Ԫ�ذ��е����ȵ�˳������ķǵݹ��㷨
{
    typedef struct{
        int l;             //��ŵȴ����������ε�����±�
        int r;             //��ŵȴ����������ε��յ��±�
    }stacknode;             //ջ�е�ÿ��Ԫ�ص�����
    stacknode stack[N];         //������ŵȴ�����������
    int top,i,j,mid;
    if(left <= right){          //����β�Ϊ��
        top = 0;        //ջ�ĳ�ʼ��
        i = left;j = right;             //�ֱ��¼��ǰ���ڴ��������ε������յ��±�
        while(i <= j || top != 0){          //��ǰ���ڴ��������β�Ϊ�ջ�ջ��Ϊ��
            if(i <= j){         //��ǰ���������β�Ϊ�գ������
                mid = (i + j)/2;
                printf("%4d",list[mid]);            //�����ڴ����������е����
                stack[top].l = mid+1;           //����ǰ���ڴ����������е���Ҳ���ջ
                stack[top].r = j;
                ++top;
                j = mid - 1;        //���е�����Ϊ��ǰ��������������
            }
            else{           //��ǰ���ڴ���������Ϊ��ʱͨ��ջ��Ԫ�ؽ��л���
                --top;
                i = stack[top].l;
                j = stack[top],r;
            }
        }
    }
}
