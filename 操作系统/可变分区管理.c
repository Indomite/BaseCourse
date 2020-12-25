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

//初始化系统状态
void InitOS(used_table* usedtable,free_table* freetable){
	used_table* p = usedtable;
	free_table* p1 = freetable;
	used_table* upt;
	free_table* fpt;
	int i,j;
	printf("----初始化已分配区----\n");
	for(i=1;i<5;i++){
		upt = (used_table*)malloc(sizeof(used_table));
		printf("请输入相关信息：");
		upt->udata.number = i;
		printf("请输入起始地址：");
		scanf("%d",&upt->udata.address);
		printf("请输入长度：");
		scanf("%d",&upt->udata.length);
		printf("请输入作业名：");
		scanf("%s",upt->udata.flag);
		p->next = upt;
		upt->next = NULL;
		p = upt;
	}
	printf("----初始化未分配区----\n");
	for(j=1;j<4;j++){
		fpt = (free_table*)malloc(sizeof(free_table));
		printf("请输入相关信息：");
		fpt->fdata.number = j;
        printf("请输入起始地址：");
		scanf("%d",&fpt->fdata.address);
		printf("请输入长度：");
		scanf("%d",&fpt->fdata.length);
		p1->next = fpt;
		fpt->next = NULL;
		p1 = fpt;
	}
}

//输出已分配区表和未分配区表
void Output(used_table *usedtable,free_table *freetable){
    printf("已分配区表\n");
    printf("序号 起始地址 长度 作业名\n");
    used_table* p = usedtable->next;
	while(p != NULL){
        if(p->udata.length != 0){
            printf("%d       %d       %d    %s\n",p->udata.number,p->udata.address,p->udata.length,p->udata.flag);
        }

        p=p->next;
	}
	printf("------------------\n");
	printf("未分配区表\n");
    printf("序号 起始地址 长度 \n");
	free_table* p1=freetable->next;
    while(p1 != NULL){
        if(p1->fdata.length != 0){
            printf("%d       %d    %d\n",p1->fdata.number,p1->fdata.address,p1->fdata.length);
        }
        p1=p1->next;
	}
}
//空闲区合并
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

//空闲区移动策略
void move(free_table* freetable,int len){
    //printf("移动技术\n");
    free_table* p = freetable->next;
    free_table* tmp = freetable->next;
    free_table* tmp1 = freetable->next;
    int sum = 0;
    free_table* stop = NULL;//记录停止移动时，当前的指针
    while(p != NULL){
	//printf("jinru\n");
        sum+=p->fdata.length;
	//printf("sum = %d",sum);
        if(sum>=len){//地址空间足够时,停止移动
            stop = p;
            break;
        }
        p = p->next;
    }
    if(sum < len){
    	printf("空闲区和也不够\n");
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

//主存分配
void allocate(used_table* usedtable,free_table* freetable){
    printf("请输入要装入作业的长度：");
    int len;
    scanf("%d",&len);
    printf("请输入要装入作业的名称：");
    char name[10];
    scanf("%s",name);
    printf("请输入要装入作业的序号:");
    int number;
    scanf("%d",&number);
    free_table* p = freetable->next;
    free_table* tmp = NULL;//记录找到的最小分区
    int min = 1000;
    int temp = 0;
    int flag = 0;//判断每一块分区是否满足
    while(p != NULL){//寻找能满足用户进程的最小分区
        if(p->fdata.length >= len){
            if(p->fdata.length-len < min && p->fdata.length-len >= 0){//寻找最小的空间
                min = p->fdata.length-len;
                tmp = p;
            }
        }else{
            flag++;
        }
        p = p->next;
        temp++;
    }
    if(flag == temp){//每一块地址空间都小于job
        printf("地址空间不够,采用移动技术\n");
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
    	//修改未分配区
    	if(tmp->fdata.length == len){
     	   tmp->fdata.length =0;
       	   tmp->fdata.address = 0;
   	}else{
      	  tmp->fdata.length-=len;
       	  tmp->fdata.address = tmp->fdata.address+len;
   	}
    }

}
//根据空闲区起始地址递增排列
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
//主存回收
void reclaim(used_table* usedtable,free_table* freetable){
    printf("请输入要回收的作业序号\n");
    int number;
    scanf("%d",&number);
    free_table* pt = (free_table*)malloc(sizeof(free_table));
    used_table* tmp = NULL;//记录要回收的作业
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
    //消除空间
    tmp->udata.number = -1;
    tmp->udata.length = 0;
    tmp->udata.address = 0;
    //插入到未分配区
    free_table* p1 = freetable->next;
    freetable->next = pt;
    pt->next = p1;
}


int main(){
    used_table usedtable;
    free_table freetable;
    //初始化内存分配
    InitOS(&usedtable,&freetable);
    //1.输出此时的已分配区表和未分配区表
    Output(&usedtable,&freetable);
    printf("-------------------\n");
    //2.装入 Job3(15K)，输出主存分配后的已分配区表和未分配区表
    allocate(&usedtable,&freetable);
    Output(&usedtable,&freetable);
    printf("-------------------\n");
//    3.回收 Job2所占用的主存空间，输出主存回收后的已分配区表和未分配区表
    reclaim(&usedtable,&freetable);

    sort_free_table(&freetable);
    combine(&freetable);
    Output(&usedtable,&freetable);
    printf("-------------------\n");
    //4.装入 Job4(130K)，输出主存分配后的已分配区表和未分配区表
    allocate(&usedtable,&freetable);
    printf("请重新输入一次\n");
    allocate(&usedtable,&freetable);
    Output(&usedtable,&freetable);
    return 0;
}
