// Test_06_18.cpp: 定义控制台应用程序的入口点。
//

#include"stdio.h"
#include"string"
#include"stdlib.h"

#define N 5

typedef struct Message//信息结构体
{
	long id;//病人编号
	char name[10];//姓名
	char sex[10];//性别
	char phone[13];//联系方式
	char illness[100];//病例描述
	char medicine[100];//资料药物
	char doctor[10];//主治医师
}MES;

typedef struct student//病例结构体
{
	MES data;
	struct student*next;
}STU, *STUD;

STUD Create() {//创建链表.初始化病人病例信息

	STUD head, news, end;

	MES stu[N] = { { 178101,"杨文","男","13788245555","腰间盘突出","阿姆斯特朗炮","杨永信" },

	{ 178102,"张江","男","18288245555","扁桃仁发炎","阿姆斯特朗炮","杨永信" },

	{ 178103,"李华","男","15088245555","腰间盘突出","阿姆斯特朗炮","杨永信" },

	{ 178104,"黄丽","男","15888245555","腰间盘突出","阿姆斯特朗炮","杨永信" },

	{ 178105,"刘宁","男","13788245555","腰间盘突出","阿姆斯特朗炮","杨永信" } };

	head = end = (STUD)malloc(sizeof(STU));

	for (int i = 0; i < N; i++) {

		news = (STUD)malloc(sizeof(STU));

		news->data = stu[i];

		end->next = news;

		end = news;

		end->next = NULL;
	}
	return head;

}

bool CheckedExist(STUD p, long id, char name[10]) {//判断病人是否已经存在
	while (p->next != NULL)
	{
		if (p->next->data.id == id) {
			return true;
		}
		else if (strcmp(p->next->data.name, name) == 0) {
			return true;
		}
		p = p->next;
	}

}

void Insert(STUD p) {//添加病人

/*	int site;

	printf("输入要插入的位置:\n");

	scanf("%d", &site);

	if (site > 6 || site < 1) {

		printf("位置错误操作结束\n"); return;

	}

	for (int i = 1; i < site; i++)p = p->next;*/

	STUD NEW = (STUD)malloc(sizeof(STU));

	printf("请分别输入病号--姓名--性别--电话号码--病例描述--资料药物--主治医师:\n");

	scanf("%d", &NEW->data.id);//录入信息

	scanf("%s", &NEW->data.name);

	scanf("%s", &NEW->data.sex);
	
	scanf("%s", &NEW->data.phone);

	scanf("%s", &NEW->data.illness);
	
	scanf("%s", &NEW->data.medicine);

	scanf("%s", &NEW->data.doctor);

	if (CheckedExist(p,NEW->data.id,NEW->data.name) == true) {
		printf("系统提示：病人已经存在");
		return;
	}

	NEW->next = p->next;

	p->next = NEW;

	printf("系统提示：添加成功\n");
}

void Deleted(STUD p) {//删除学生

	long id;

	printf("系统提示：输入要删除的病人病号\n");

	scanf("%ld", &id);

	while (p->next != NULL)

	{

		if (id == p->next->data.id) {

			STUD q = p->next;
			p->next = p->next->next;

			free(q);

			printf("系统提示：删除成功\n");

			return;

		}

		p = p->next;
	}

	printf("系统提示：删除失败,或病号错误，请重新尝试，操作结束\n");
}

void LookUpById(STUD p) {//通过病号查找病人病例

	long id;

	printf("系统提示：请输入要查找病人病号：\n");

	scanf("%ld", &id);

	while (p->next != NULL)

	{

		if (p->next->data.id == id)

		{
			printf("\t系统提示：查找成功!\n");

			printf("病号:\t%d\n", p->next->data.id);

			printf("姓名:\t%s\n", p->next->data.name);

			printf("性别:\t%s\n", p->next->data.sex);

			printf("电话:\t%s\n", p->next->data.phone);

			printf("病例描述:  %s\n", p->next->data.illness);

			printf("治疗药物:  %s\n", p->next->data.medicine);

			printf("主治医师:  %s\n", p->next->data.doctor);

			printf("=======================================\n");
			return;

		}

		p = p->next;

	}
	printf("系统提示：查找失败,或姓名错误，请重新尝试，操作结束\n");
}


void LookUpByName(STUD p) {//通过姓名查找病人病例

	char name[10];

	printf("系统提示：请输入要查找病人的姓名：\n");

	scanf("%s", name);

	while (p->next != NULL)

	{

		if (strcmp(p->next->data.name, name) == 0)

		{
			printf("系统提示：查找成功!\n");

			printf("病号:\t%d\n", p->next->data.id);

			printf("姓名:\t%s\n", p->next->data.name);

			printf("性别:\t%s\n", p->next->data.sex);

			printf("电话:\t%s\n", p->next->data.phone);

			printf("病例描述:  %s\n", p->next->data.illness);
			
			printf("治疗药物:  %s\n", p->next->data.medicine);

			printf("主治医师:  %s\n", p->next->data.doctor);

			return;

		}

		p = p->next;

	}
	printf("系统提示：查找失败,或姓名错误，请重新尝试，操作结束\n");
}

void PrintAll(STUD p) {//遍历打印

	int i = 1;

	while (p->next != NULL)

	{

		printf("第%d名的病人信息\n", i++);

		printf("病号:\t%d\n", p->next->data.id);

		printf("姓名:\t%s\n", p->next->data.name);

		printf("性别:\t%s\n", p->next->data.sex);

		printf("电话:\t%s\n", p->next->data.phone);

		printf("病例描述:  %s\n", p->next->data.illness);

		printf("治疗药物:  %s\n", p->next->data.medicine);

		printf("主治医师:  %s\n", p->next->data.doctor);

		printf("========================================\n");

		p = p->next;

	}

}

void ChangePatient(STUD p) {
	long id;
	printf("系统提示：请输入要修改的病人编号：\n");
	scanf("%d", &id);
	if (!CheckedExist(p, id, NULL)) {
		printf("系统提示：查找失败,或姓名错误，请重新尝试，操作结束\n");
		return;
	}
	while (p->next != NULL)

	{

		if (p->next->data.id==id)

		{
			printf("系统提示：查找成功!\n");

			printf("病号:\t%d\n输入要修改的值：", p->next->data.id);
			scanf("%ld", &p->next->data.id);
			printf("姓名:\t%s\n输入要修改的值：", p->next->data.name);
			scanf("%s", &p->next->data.name);
			printf("性别:\t%s\n输入要修改的值：", p->next->data.sex);
			scanf("%s", &p->next->data.sex);
			printf("电话:\t%s\n输入要修改的值：", p->next->data.phone);
			scanf("%s", &p->next->data.phone);
			printf("病例描述:  %s\n输入要修改的值：", p->next->data.illness);
			scanf("%s", &p->next->data.illness);
			printf("治疗药物:  %s\n输入要修改的值：", p->next->data.medicine);
			scanf("%s", &p->next->data.medicine);
			printf("主治医师:  %s\n输入要修改的值：", p->next->data.doctor);
			scanf("%s", &p->next->data.doctor);
			printf("系统提示：修改成功");
			return;

		}

		p = p->next;

	}
}
void TotalPatient(STUD p){
	int num=0;
	while(p->next!=NULL){
		num++;
		p=p->next;
	}
	printf("病人总数：%d个病人\n",num);
}
void DisplaySelectMessage() {
	printf("=======================病人病例管理系统==============================\n");
	printf("\t1.录入病人病例信息\t\t2.通过病号查找病人\n");
	printf("\t3.通过姓名查找病人\t\t4.打印全部病人信息\n");
	printf("\t5.更改病人病例信息\t\t6.统计病人个数信息\n");
	printf("\t7.删除病人病例信息\t\t8.退出病例管理系统\n");
	printf("=====================================================================\n");
	printf("系统提示：请输入你的选择：\n");
}
void select() {
	int select;
	STUD Phead = Create();//创建
	while (true)
	{
	DisplaySelectMessage();
	scanf("%d", &select);
	while (select<1||select>8)
	{
		printf("系统提醒：输入的选项无效请重新尝试\n");
		scanf("%d", &select);
	}
	switch (select)
	{
	case 1:Insert(Phead); break;
	case 2:LookUpById(Phead); break;
	case 3:LookUpByName(Phead); break;
	case 4:PrintAll(Phead); break;
	case 5:ChangePatient(Phead); break;
	case 6:TotalPatient(Phead); break;
	case 7:Deleted(Phead);break;
	case 8:return; break;
	default:printf("系统提醒：发生错误,程序退出！\n");
		break;
		}
	}
}
int main()

{
	select();

	return 0;

}
