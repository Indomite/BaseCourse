#include <stdio.h>

int Available[5];       //可用资源数
int Allocation[5][5];       //已分配资源数
int Max[5][5];          //最大需求数
int Need[5][5];         //剩余需求数
int Request[5][5];      //请求资源数
int avl[5];     //剩余资源数
int alloc[5] = {0};
int running[5];
int safe=0;
int count = 0;
int i, j;       // 其中i、j表示各个进程
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

    printf("\n请输入资源类型总数: ");
    scanf("%d", &m);

    printf("\n请输入各类资源总数:");
    for (i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    printf("\n请输入已分配的各类资源数:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\n各类资源最大需求数:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }
}

void Securitycheck()
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
                    printf("\n进程%d 正正在进行\n", i + 1);
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
            break;
        } else {
            printf("\n进程安全");
            printf("\n各类资源以此剩余:");

            for (i = 0; i < m; i++) {
                printf("\t%d", avl[i]);
            }
            printf("\n");
        }
    }
}

int main()
{
    initialize();
    Securitycheck();
}
