#include <stdio.h>
#include <stdlib.h>
#define n 10
#define m 10

int Available[m];            //���õ���Դ��
int Allocation[n][m];              //�������Դ��
int Need[n][m];                //�������Դ��
int Work[m];              //�ɷ������Դ��
int request[n][m];          //�������Դ��
bool Finish[n];              //�����Ƿ����
bool Found;

bool safe()
{
    for(i = 0;i < m;i++){
        Work[i] = Available[i];
    }

    for(i = 0;i < n;i++){
        Finish[i] = false;
    }

    while(true){
        //���ϵ��ҿ�ִ�н���
        Found = false;
        for(i=1; i<=n; i++){
            if(Finish[i]==false && Need[i]<=Work){
                Work = Work + Allocation[i];
                Finish[i] = true;
                Found = true;
            }
        }
       if(Found==false)
            break;
     }

    for(i=1;i<=n;i++){
        if(Finish[i]==false){
            printf("ϵͳ�ǲ���ȫ��");
            return false;
        }else{
            printf("ϵͳ�ǰ�ȫ��");
            return true;
        }
    }

}
