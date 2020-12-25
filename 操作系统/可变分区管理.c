#include <stdio.h>
#include <stdlib.h>

typedef struct udata{
	int number;
	int address;
	int length;
	char flag[10];
}data;
typedef struct used_table{
	data udata;
	data* next;
}used_table;
typedef struct fdata{
    int number;
    int address;
    int length;
}fdata;
typedef struct free{
	fdata fdata;
	fdata* next;
}free_table;

//��ʼ��ϵͳ״̬
void InitOS(used_table* usedtable,free_table* freetable){
	used_table* p = usedtable;
	free_table* p1 = freetable;
	used_table* upt;
	free_table* fpt;
	int i,j;
	printf("----��ʼ���ѷ�����----\n");
	for(i=1;i<5;i++){
		upt = (used_table*)malloc(sizeof(used_table));
		printf("�����������Ϣ��");
		upt->udata.number = i;
		printf("��������ʼ��ַ��");
		scanf("%d",&upt->udata.address);
		printf("�����볤�ȣ�");
		scanf("%d",&upt->udata.length);
		printf("��������ҵ����");
		scanf("%s",upt->udata.flag);
		p->next = upt;
		upt->next = NULL;
		p = upt;
	}
	printf("----��ʼ��δ������----\n");
	for(j=1;j<4;j++){
		fpt = (free_table*)malloc(sizeof(free_table));
		printf("�����������Ϣ��");
		fpt->fdata.number = j;
        printf("��������ʼ��ַ��");
		scanf("%d",&fpt->fdata.address);
		printf("�����볤�ȣ�");
		scanf("%d",&fpt->fdata.length);
		p1->next = fpt;
		fpt->next = NULL;
		p1 = fpt;
	}
}

//����ѷ��������δ��������
void Output(used_table *usedtable,free_table *freetable){
    printf("�ѷ�������\n");
    printf("��� ��ʼ��ַ ���� ��ҵ��\n");
    used_table* p = usedtable->next;
	while(p != NULL){
        if(p->udata.length != 0){
            printf("%d       %d       %d    %s\n",p->udata.number,p->udata.address,p->udata.length,p->udata.flag);
        }

        p=p->next;
	}
	printf("------------------\n");
	printf("δ��������\n");
    printf("��� ��ʼ��ַ ���� \n");
	free_table* p1=freetable->next;
    while(p1 != NULL){
        if(p1->fdata.length != 0){
            printf("%d       %d    %d\n",p1->fdata.number,p1->fdata.address,p1->fdata.length);
        }
        p1=p1->next;
	}
}
//�������ϲ�
void combine(free_table* freetable){
    free_table* pt = NULL;
    free_table* pt1 = NULL;
    fdata temp;
    for(pt=freetable->next;pt->next != NULL;pt=pt->next){
        for(pt1=freetable->next;pt1->next != NULL;pt1=pt1->next){
            if(pt->fdata.address+pt->fdata.length == pt1->fdata.address){
                pt->fdata.length = pt->fdata.length + pt1->fdata.length;
                pt1->fdata.address = 0;
                pt1->fdata.length = 0;
            }
        }
    }
}

//�������ƶ�����
void move(free_table* freetable,int len){
    //printf("�ƶ�����\n");
    free_table* p = freetable->next;
    free_table* tmp = freetable->next;
    free_table* tmp1 = freetable->next;
    int sum = 0;
    free_table* stop = NULL;//��¼ֹͣ�ƶ�ʱ����ǰ��ָ��
    while(p != NULL){
	//printf("jinru\n");
        sum+=p->fdata.length;
	//printf("sum = %d",sum);
        if(sum>=len){//��ַ�ռ��㹻ʱ,ֹͣ�ƶ�
            stop = p;
            break;
        }
        p = p->next;
    }
    if(sum < len){
    	printf("��������Ҳ����\n");
    }else{
       	//printf("stop = %d\n",stop->fdata.address);
    	//printf("stop = %d\n",stop->fdata.length);
   	stop->fdata.address = tmp->fdata.address;
   	stop->fdata.length = sum;
    	while(tmp1 != stop){
       	   tmp1->fdata.address = 0;
           tmp1->fdata.length = 0;
           tmp1->fdata.number = 0;
           tmp1 = tmp1->next;
        }
    }
}

//�������
void allocate(used_table* usedtable,free_table* freetable){
    printf("������Ҫװ����ҵ�ĳ��ȣ�");
    int len;
    scanf("%d",&len);
    printf("������Ҫװ����ҵ�����ƣ�");
    char name[10];
    scanf("%s",name);
    printf("������Ҫװ����ҵ�����:");
    int number;
    scanf("%d",&number);
    free_table* p = freetable->next;
    free_table* tmp = NULL;//��¼�ҵ�����С����
    int min = 1000;
    int temp = 0;
    int flag = 0;//�ж�ÿһ������Ƿ�����
    while(p != NULL){//Ѱ���������û����̵���С����
        if(p->fdata.length >= len){
            if(p->fdata.length-len < min && p->fdata.length-len >= 0){//Ѱ����С�Ŀռ�
                min = p->fdata.length-len;
                tmp = p;
            }
        }else{
            flag++;
        }
        p = p->next;
        temp++;
    }
    if(flag == temp){//ÿһ���ַ�ռ䶼С��job
        printf("��ַ�ռ䲻��,�����ƶ�����\n");
        move(freetable,len);
    }else{
        used_table* p1 = NULL;
    	used_table* pt = (used_table*)malloc(sizeof(used_table));
    	strcpy(pt->udata.flag,name);
    	pt->udata.length = len;
    	pt->udata.number = number;
    	pt->udata.address = tmp->fdata.address;
    	p1 = usedtable->next;
    	usedtable->next = pt;
   	 pt->next = p1;
    	//�޸�δ������
    	if(tmp->fdata.length == len){
     	   tmp->fdata.length =0;
       	   tmp->fdata.address = 0;
   	}else{
      	  tmp->fdata.length-=len;
       	  tmp->fdata.address = tmp->fdata.address+len;
   	}
    }

}
//���ݿ�������ʼ��ַ��������
void sort_free_table(free_table* freetable){
    free_table* pt = NULL;
    free_table* pt1 = NULL;
    fdata temp;
    for(pt=freetable->next;pt->next != NULL;pt=pt->next){
        for(pt1=freetable->next;pt1->next != NULL;pt1=pt1->next){
            if(pt->fdata.address < pt1->fdata.address && pt->fdata.address != 0){
                temp = pt->fdata;
                pt->fdata = pt1->fdata;
                pt1->fdata = temp;
            }
        }
    }
}
//�������
void reclaim(used_table* usedtable,free_table* freetable){
    printf("������Ҫ���յ���ҵ���\n");
    int number;
    scanf("%d",&number);
    free_table* pt = (free_table*)malloc(sizeof(free_table));
    used_table* tmp = NULL;//��¼Ҫ���յ���ҵ
    used_table* p = usedtable->next;
    while(p != NULL){
        if(p->udata.number == number){
            tmp = p;
            break;
        }
        p = p->next;
    }
    pt->fdata.number = tmp->udata.number;
    pt->fdata.length = tmp->udata.length;
    pt->fdata.address = tmp->udata.address;
    //�����ռ�
    tmp->udata.number = -1;
    tmp->udata.length = 0;
    tmp->udata.address = 0;
    //���뵽δ������
    free_table* p1 = freetable->next;
    freetable->next = pt;
    pt->next = p1;
}


int main(){
    used_table usedtable;
    free_table freetable;
    //��ʼ���ڴ����
    InitOS(&usedtable,&freetable);
    //1.�����ʱ���ѷ��������δ��������
    Output(&usedtable,&freetable);
    printf("-------------------\n");
    //2.װ�� Job3(15K)���������������ѷ��������δ��������
    allocate(&usedtable,&freetable);
    Output(&usedtable,&freetable);
    printf("-------------------\n");
//    3.���� Job2��ռ�õ�����ռ䣬���������պ���ѷ��������δ��������
    reclaim(&usedtable,&freetable);

    sort_free_table(&freetable);
    combine(&freetable);
    Output(&usedtable,&freetable);
    printf("-------------------\n");
    //4.װ�� Job4(130K)���������������ѷ��������δ��������
    allocate(&usedtable,&freetable);
    printf("����������һ��\n");
    allocate(&usedtable,&freetable);
    Output(&usedtable,&freetable);
    return 0;
}
