#include <stdio.h>

int Available[5];       //������Դ��
int Allocation[5][5];       //�ѷ�����Դ��
int Max[5][5];          //���������
int Need[5][5];         //ʣ��������
int Request[5][5];      //������Դ��
int avl[5];     //ʣ����Դ��
int alloc[5] = {0};     //ͳ����Դ��
int running[5];
int safe=0;
int count = 0;
int i, j;       // ����i��j��ʾ��������
int a;      //������Դ��
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

    printf("��������Դ��������: ");
    scanf("%d", &m);

    printf("\n�����������Դ����:\n");
    for (j = 0; j < m; j++) {
        printf("��%d����Դ����",j);
        scanf("%d", &Available[j]);
    }

    printf("\n�������ѷ���ĸ�����Դ��:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
                printf("��%d�������ѷ����%d����Դ����",i,j);
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\n������Դ���������:\n");
    for (i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("��%d�������е�%d����Դ�������������",i,j);
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
                    printf("\n����%d ���ڽ���\n", i + 1);
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
            return 0;
        } else {
            printf("\n���̰�ȫ");
            return 1;
        }
    }
}

void RequestResource()
{
    printf("������������Դ�Ľ��̣�");
    scanf("%d", &a);
    for (i = 0; i < n; i++)
    {
        printf("���������%d��%d����Դ����������", a, i);
        scanf("%d", &Request[a][i]);
        if (Request[a][i] > Need[a][i])
        {
            printf("\n���������������Դ���������Լ��걨�����������\n");
            return;
        }
        if (Request[a][i] > Available[i])
        {
            printf("\n%d�������Դ�����ڿ�����Դ��������ȴ�\n", a);
            return;
        }

    }
    for (i = 0; i < n; i++)
    {
        //��������̽�Է���
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
    printf("������Ҫѡ���ģ��\n\t1->��ʼ��\n\t2->������Դ\n\t3->��ȫ�Լ��\n");
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
