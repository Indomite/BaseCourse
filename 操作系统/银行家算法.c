#include <stdio.h>

int Available[5];       //������Դ��
int Allocation[5][5];       //�ѷ�����Դ��
int Max[5][5];          //���������
int Need[5][5];         //ʣ��������
int Request[5][5];      //������Դ��
int avl[5];     //ʣ����Դ��
int alloc[5] = {0};
int running[5];
int safe=0;
int count = 0;
int i, j;       // ����i��j��ʾ��������
int exec= 1;
int n,m;    //�ֱ��ʾ������������Դ����

void initialize()
{
    printf("\n�������������: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        running[i] = 1;
        count++;
    }

    printf("\n��������Դ��������: ");
    scanf("%d", &m);

    printf("\n�����������Դ����:");
    for (i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    printf("\n�������ѷ���ĸ�����Դ��:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\n������Դ���������:\n");
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

    printf("\nʣ����Դ��:");
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
                    printf("\n����%d �����ڽ���\n", i + 1);
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
            printf("\n���̲���ȫ.\n");
            break;
        } else {
            printf("\n���̰�ȫ");
            printf("\n������Դ�Դ�ʣ��:");

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
