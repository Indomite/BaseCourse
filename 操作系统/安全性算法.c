#include <stdio.h>
#include <stdlib.h>
#define n 10
#define m 10

int Available[m];            //可用的资源数
int Allocation[n][m];              //分配的资源数
int Need[n][m];                //需求的资源数
int Work[m];              //可分配的资源数
int request[n][m];          //所需的资源数
bool Finish[n];              //进程是否结束
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
        //不断的找可执行进程
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
            printf("系统是不安全的");
            return false;
        }else{
            printf("系统是安全的");
            return true;
        }
    }

}
