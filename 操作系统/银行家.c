#include <stdio.h>

int Available[5];       //可用资源数
int Allocation[5][5];       //已分配资源数
int Max[5][5];          //最大需求数
int Need[5][5];         //剩余需求数
int Request[5][5];      //请求资源数
int avl[5];     //剩余资源数
int alloc[5] = {0};     //统计资源数
int running[5];
int safe=0;
int count = 0;
int i, j;       // 其中i、j表示各个进程
int a;      //请求资源数
int exec= 1;
int n,m;    //分别表示进程总数和资源总数

void initialize()
{
    printf("\n请输入进程总数: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        running[i] = 1;
        count++;
    }

    printf("请输入资源类型总数: ");
    scanf("%d", &m);

    printf("\n请输入各类资源总数:\n");
    for (j = 0; j < m; j++) {
        printf("第%d类资源数：",j);
        scanf("%d", &Available[j]);
    }

    printf("\n请输入已分配的各类资源数:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
                printf("第%d个进程已分配第%d类资源数：",i,j);
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\n各类资源最大需求数:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("第%d个进程中第%d类资源数最大需求数：",i,j);
            scanf("%d", &Max[i][j]);
        }
    }
}

int SecurityCheck()
{
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            alloc[j] += Allocation[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        avl[i] = Available[i] - alloc[i];
    }

    for (i = 0; i < m; i++) {
        Need[i][j] = Max[i][j] - Allocation[i][j];
    }

    printf("\n剩余资源数:");
    for (i = 0; i < m; i++) {
        printf("\t%d", avl[i]);
    }
    printf("\n");

    while (count != 0) {
        safe = 0;
        for (i = 0; i < n; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < m; j++) {
                    if (Need[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
                if (exec) {
                    printf("\n进程%d 正在进行\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = 1;

                    for (j = 0; j < m; j++) {
                        avl[j] += Allocation[i][j];
                    }
                    break;
                }
            }
        }
        if (!safe) {
            printf("\n进程不安全.\n");
            return 0;
        } else {
            printf("\n进程安全");
            return 1;
        }
    }
}

void RequestResource()
{
    printf("请输入申请资源的进程：");
    scanf("%d", &a);
    for (i = 0; i < n; i++)
    {
        printf("请输入进程%d对%d类资源的申请量：", a, i);
        scanf("%d", &Request[a][i]);
        if (Request[a][i] > Need[a][i])
        {
            printf("\n出错！进程申请的资源数多于它自己申报的最大需求量\n");
            return;
        }
        if (Request[a][i] > Available[i])
        {
            printf("\n%d请求的资源数大于可用资源数，必须等待\n", a);
            return;
        }

    }
    for (i = 0; i < n; i++)
    {
        //以下是试探性分配
        Available[i] = Available[i] - Request[a][i];
        Allocation[a][i] = Allocation[a][i] + Request[a][i];
        Need[a][i] = Need[a][i] - Request[a][i];
    }
    int ret = SecurityCheck();
    if (ret == 1)
    {
        int key = 0;
        for (j = 0; j < n; j++)
        {
            if (Need[a][j] == 0)
            {
                key++;
            }
        }
        if (key == n)
        {
            for (j = 0; j < n; j++)
            {
                Available[j] += Allocation[a][j];
                Allocation[a][j] = 0;
            }
        }
    }
}

int main()
{
    int in;
    printf("请输入要选择的模块\n\t1->初始化\n\t2->请求资源\n\t3->安全性检测\n");
    scanf("%d",&in);
    switch(in)
    {
        case 1:
            initialize();
        case 2:
            RequestResource();
        case 3:
            SecurityCheck();
    }
}
