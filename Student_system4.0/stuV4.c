#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10	 // 字符串的最大长度
#define STU_NUM 30	 // 最多的学生人数
#define COURSE_NUM 6 // 最多的考试科目数
#define MAX_LINE 100 // 每行长度

char reg_name[STU_NUM] = "", reg_password[STU_NUM] = "";
char input_name[STU_NUM], input_password[STU_NUM];

typedef struct student
{
	long long num;			 // 每个学生的学号
	char name[MAX_LEN];		 // 每个学生的姓名
	float score[COURSE_NUM]; // 每个COURSE_NUM门功课的成绩
	float sum;				 // 每个学生的总成绩
	float aver;				 // 每个学生的平均成绩
} STU;

typedef struct account
{
	char username[12]; // 学生账号
	char password[20]; // 学生密码
} ACC;

int Menu(void);
void ReadScore(STU stu[], int n, int m);
void AverSumofEveryCourse(STU stu[], int n, int m);
void AverSumofEveryStudent(STU stu[], int n, int m);
void AverSumofEveryStudent_no_out(STU stu[], int n, int m);
void SortbyScore(STU stu[], int n, int m, int (*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float *x, float *y);
void SwapLong(long long *x, long long *y);
void SwapChar(char x[], char y[]);
void AsSortbyNum(STU stu[], int n, int m);
void SortbyName(STU stu[], int n, int m);
void SearchbyNum(STU stu[], int n, int m);
void SearchbyName(STU stu[], int n, int m);
void StatisticAnalysis(STU stu[], int n, int m);
void PrintScore(STU stu[], int n, int m);
void WritetoFile(STU stu[], int n, int m);
void ReadfromFile(STU stu[], int *n, int *m);
void register_student(ACC *account);				   // 学生注册系统
int ReadAccount(ACC *account);						   // 读文件信息
void WriteAccount(char *reg_name, char *reg_password); // 将账户写入文件

int main()
{
	int itemSelected;
	int n = 0, m = 0; // m门课程，n个学生
	STU stu[STU_NUM];
	ACC account[STU_NUM];
	printf("\033[1m");	// 设置粗体字属性
	printf("\033[34m"); // 设置前景色为蓝色
	printf("\033[3m");	// 斜体
	int x, flag = 1;
	while (flag)
	{
		system("cls");
		printf("\n\n\t\t\t学生管理系统\n\n");
		printf("\t\t\t1:注册\n");
		printf("\t\t\t2:登录\n");
		printf("\t\t\t0.退出\n\n");

		printf("\t\t\t输入功能序号:");
		scanf("%d", &x);

		switch (x)
		{
		case 1:
			register_student(account);
			break;
		case 2:
			if (ReadAccount(account) == 1)
			{
				flag = 0;
			}
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("\n\t\t输入的序号有误,请重新输入!\n");
		}
	}
	system("pause"); // 清屏
	system("cls");
	printf("\033[1m");	// 设置粗体字属性
	printf("\033[35m"); // 设置前景色为紫色
	printf("\033[3m");	// 斜体

	// 输入学生的个数
	printf("\t\t\t\t\tinput student number(n<%d):", STU_NUM);
	scanf("%d", &n);
	printf("\n");
	// 输入课程的门数
	printf("\t\t\t\t\tinput course number(n<=%d):", COURSE_NUM);
	scanf("%d", &m);

	while (1)
	{
		printf("\033[1m");	   // 设置粗体字属性
		printf("\033[31m");	   // 设置前景色为红色
		printf("\033[3m");	   // 斜体
		itemSelected = Menu(); // 显示菜单，并读取用户输入
		switch (itemSelected)
		{
		case 1:
			system("cls");
			ReadScore(stu, n, m);
			break;
		case 2:
			system("cls");
			AverSumofEveryCourse(stu, n, m);
			break;
		case 3:
			system("cls");
			AverSumofEveryStudent(stu, n, m);
			break;
		case 4:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 5:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Ascending);
			printf("\nSort in ascending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 6:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			AsSortbyNum(stu, n, m);
			printf("\nsort in ascending order by number:\n");
			PrintScore(stu, n, m);
			break;
		case 7:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyName(stu, n, m);
			printf("\nsort in dictionary order by name:\n");
			PrintScore(stu, n, m);
			break;
		case 8:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);		 // sort in descending order by score
			printf("\nSort in descending order by score:\n");
			SearchbyNum(stu, n, m);
			break;
		case 9:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);		 // sort in descending order by score
			printf("\nSort in descending order by score:\n");
			SearchbyName(stu, n, m);
			break;
		case 10:
			system("cls");
			StatisticAnalysis(stu, n, m);
			break;
		case 11:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			PrintScore(stu, n, m);
			AverSumofEveryCourse(stu, n, m);
			break;
		case 12:
			system("cls");
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			WritetoFile(stu, n, m);
			break;
		case 13:
			system("cls");
			ReadfromFile(stu, &n, &m);
			PrintScore(stu, n, m);
			break;
		case 0:
			system("cls");
			printf("End of program!\n");
			exit(0);
		default:
			printf("Input error!\n");
		}
	}
	system("pause");
	return 0;
}

/* 显示菜单，并获得用户键盘输入的数据 */
int Menu(void)
{
	int itemSelected;
	printf("\n\t\t\t\t\tManagement for student's scores \n");
	printf("\t\t\t\t\t1—input record \n");										// 录入每个学生的学号、姓名和考试成绩；
	printf("\t\t\t\t\t2—caculate total and average acore of every course \n");	// 计算每门课程的总分和平均分；
	printf("\t\t\t\t\t3—caculate total and average acore of every student \n"); // 计算每个学生的总分和平均分；
	printf("\t\t\t\t\t4—sort in descending order by score of sum \n");			// 按照每个学生的总分由高到低排出名次表
	printf("\t\t\t\t\t5—sort in ascending order by score of sum \n");			// 按照每个学生的总分由低到高排出名次表
	printf("\t\t\t\t\t6—sort in ascending order by number \n");					// 按照学号由小到大排出成绩表
	printf("\t\t\t\t\t7—sort in dictionary order by name \n");					// 按照姓名的字典顺序排出成绩表；
	printf("\t\t\t\t\t8—search by number \n");									// 按照学号查询学生排名及其各科考试成绩；
	printf("\t\t\t\t\t9—search by name \n");									// 按照姓名查询学生排名及其各科考试成绩；
	printf("\t\t\t\t\t10—statistic analysis \n");								// 统计各个分数段的学生人数及其所占的百分比
	printf("\t\t\t\t\t11—list record \n");										// 输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。
	printf("\t\t\t\t\t12—Write to a file \n");									// 将每个学生的记录信息写入文件；
	printf("\t\t\t\t\t13—Read from a file \n");									// 从文件中读出每个学生的记录信息并显示；
	printf("\t\t\t\t\t0—exit \n");
	printf("\033[33m"); // 设置为黄色
	printf("\t\t\t\t\tplease input your choice:");
	scanf("%d", &itemSelected); // 读入用户输入
	printf("\n");

	return itemSelected;
}

void register_student(ACC *account) // 学生注册系统
{
	system("pause");
	system("cls");

	printf("\n\n\t\t\t欢迎使用学生管理系统\n\n");
	while (1)
	{
		printf("\n\t\t请输入用户名[不大于10个字符]:");
		scanf("%s", reg_name);

		if (strlen(reg_name) <= 10)
		{
			while (1)
			{
				printf("\n\t\t请输入密码[密码长度不大于8位]:");
				scanf("%s", reg_password);

				if (strlen(reg_password) <= 8)
				{
					printf("\n\n\t\t注册成功");
					WriteAccount(reg_name,reg_password);
					break;
				}
				else
				{
					printf("\n\t\t密码长度超过8位，请重新输入\n");
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t用户名的长度超过10位，请重新输入\n");
		}
	}
}

/* 输入n个学生的m门课的成绩 */
void ReadScore(STU stu[], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("输入第%d位同学的学号:", i + 1);
		scanf("%lld", &stu[i].num);
		printf("姓名:");
		scanf(" %s", stu[i].name);
		printf("分别输入%d门科目成绩:", m);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &stu[i].score[j]);
		}
		printf("\n");
	}
}

/* 计算每门课程的总分和平均分 */
void AverSumofEveryCourse(STU stu[], int n, int m) // m门课程，n个学生
{
	int i, j;
	float sum[m];
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			sum[j] = sum[j] + stu[i].score[j];
		}
	}
	for (j = 0; j < m; j++)
	{
		printf("第%d门课的总分为%f,平均分为%f\n", j + 1, sum[j], sum[j] / n);
	}
}

/* 计算每个学生各门课程的总分和平均分——有输出 */
void AverSumofEveryStudent(STU stu[], int n, int m) // m门课程，n个学生
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		stu[i].sum = 0;
		for (j = 0; j < m; j++)
		{
			stu[i].sum = stu[i].sum + stu[i].score[j];
		}
		printf("第%d位学生的总分为%f，平均分为%f\n", i + 1, stu[i].sum, stu[i].sum / m);
	}
}

/* 计算每个学生各门课程的总分和平均分——无输出 */
void AverSumofEveryStudent_no_out(STU stu[], int n, int m) // m门课程，n个学生
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		stu[i].sum = 0;
		for (j = 0; j < m; j++)
		{
			stu[i].sum = stu[i].sum + stu[i].score[j];
		}
		stu[i].aver = stu[i].sum / m;
	}
}

/* 用选择法，将数组sum的元素值排序 */
void SortbyScore(STU stu[], int n, int m, int (*compare)(float a, float b))
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*compare)(stu[j].sum, stu[k].sum))
			{
				k = j;
			}
		}
		if (k != i)
		{
			int p;
			for (p = 0; p < m; p++)
			{
				SwapFloat(&stu[k].score[p], &stu[i].score[p]);
			}
			SwapLong(&stu[k].num, &stu[i].num);
			SwapFloat(&stu[k].sum, &stu[i].sum);
			SwapFloat(&stu[k].aver, &stu[i].aver);
			SwapChar(stu[k].name, stu[i].name);
		}
	}
}

/* 使得数据按照升序排序 */
int Ascending(float a, float b)
{
	return a < b;
}

/* 使得数据按照降序排序 */
int Descending(float a, float b)
{
	return a > b;
}

/* 交换两个单精度浮点型数据 */
void SwapFloat(float *x, float *y)
{
	float temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* 交换两个长整型数据 */
void SwapLong(long long *x, long long *y)
{
	long long temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/* 交换两个字符串 */
void SwapChar(char x[], char y[])
{
	char temp[MAX_LEN];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}

/* 按照选择法，将数组num的元素值按照从小到大排序 */
void AsSortbyNum(STU stu[], int n, int m)
{
	int i, j, k;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu[j].num < stu[k].num)
			{
				k = j;
			}
		}
		if (k != i)
		{
			int p;
			for (p = 0; p < m; p++)
			{
				SwapFloat(&stu[k].score[p], &stu[i].score[p]);
			}
			SwapLong(&stu[k].num, &stu[i].num);
			SwapFloat(&stu[k].sum, &stu[i].sum);
			SwapFloat(&stu[k].aver, &stu[i].aver);
			SwapChar(stu[k].name, stu[i].name);
		}
	}
}

/* 使用交换法，实现字符串按字典顺序排序 */
void SortbyName(STU stu[], int n, int m)
{
	int i, j;
	char temp[MAX_LEN];
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(stu[j].name, stu[i].name) < 0)
			{
				strcpy(temp, stu[i].name);
				strcpy(stu[i].name, stu[j].name);
				strcpy(stu[j].name, temp);
				int p;
				for (p = 0; p < m; p++)
				{
					SwapFloat(&stu[i].score[p], &stu[j].score[p]);
				}
				SwapLong(&stu[i].num, &stu[j].num);
				SwapFloat(&stu[i].sum, &stu[j].sum);
				SwapFloat(&stu[i].aver, &stu[j].aver);
			}
		}
	}
}

/* 按照学号，查找学生成绩并显示查找结果 */
void SearchbyNum(STU stu[], int n, int m)
{
	int i, j, rank = 1, flag = 0, k;
	long long x;
	printf("Input the searching number:\n");
	scanf("%lld", &x);
	for (i = 0; i < n; i++)
	{
		if (stu[i].num == x)
		{
			k = i;
			for (j = 0; j < n; j++)
			{
				if (stu[j].sum > stu[i].sum)
					rank++;
			}
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("排名为%d\n", rank);
		for (j = 0; j < m; j++)
		{
			printf("第%d门的成绩为:%f\n", j + 1, stu[k].score[j]);
		}
	}
	else
		printf("未找到\n");
}

/* 按照姓名，查询学生排名并显示查找结果 */
void SearchbyName(STU stu[], int n, int m)
{
	int i, j, rank = 1, flag = 0, k;
	char x[100];
	printf("请输入您要查询的学生名字:\n");
	scanf("%s", x);
	for (i = 0; i < n; i++)
	{
		if (strcmp(stu[i].name, x) == 0)
		{
			k = i;
			for (j = 0; j < n; j++)
			{
				if (stu[j].sum > stu[i].sum)
					rank++;
			}
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("排名为%d\n", rank);
		for (j = 0; j < m; j++)
		{
			printf("第%d门的成绩为:%f\n", j + 1, stu[k].score[j]);
		}
	}
	else
		printf("未找到\n");
}

/* 统计各个分数段的学生人数及其所占的百分比 */
void StatisticAnalysis(STU stu[], int n, int m) // m门课程，n个学生
{
	int A, B, C, D, E, i, j;
	for (i = 0; i < m; i++)
	{
		A = 0, B = 0, C = 0, D = 0, E = 0;
		for (j = 0; j < n; j++)
		{
			if (stu[j].score[i] >= 90 && stu[j].score[i] <= 100)
				A++;
			if (stu[j].score[i] >= 80 && stu[j].score[i] <= 89)
				B++;
			if (stu[j].score[i] >= 70 && stu[j].score[i] <= 79)
				C++;
			if (stu[j].score[i] >= 60 && stu[j].score[i] <= 69)
				D++;
			if (stu[j].score[i] >= 0 && stu[j].score[i] <= 59)
				E++;
		}
		printf("第%d门课中优秀有%d人,占比%f\n", i + 1, A, (float)A / n);
		printf("\t良好有%d人,占比%f\n", B, (float)B / n);
		printf("\t中等有%d人,占比%f\n", C, (float)C / n);
		printf("\t及格有%d人,占比%f\n", D, (float)D / n);
		printf("\t不及格有%d人,占比%f\n", E, (float)E / n);
	}
}

/* 打印学生成绩 */
void PrintScore(STU stu[], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("num--%lld\tname--%s\t", stu[i].num, stu[i].name);
		for (j = 0; j < m; j++)
		{
			printf("第%d门成绩--%.0f\t", j + 1, stu[i].score[j]);
		}
		printf("sum=%.0f\t", stu[i].sum);
		printf("aver=%.0f\n", stu[i].aver);
	}
}

/* 输出n个学生的学号、姓名及m门课程的成绩，到文件student.txt中 */
void WritetoFile(STU stu[], int n, int m)
{
	FILE *fp;
	if ((fp = fopen("student.txt", "w")) == NULL) // 打开文件
	{
		printf("打开文件失败！\n");
		exit(1);
	}
	fprintf(fp, "%d %d\n", n, m); // 写入学生数量和科目数量
	for (int i = 0; i < n; i++)	  // 循环输出每个学生信息
	{
		fprintf(fp, "%lld %s", stu[i].num, stu[i].name);
		for (int j = 0; j < m; j++) // 循环输出每个学生的科目成绩
		{
			fprintf(fp, " %.2lf", stu[i].score[j]);
		}
		fprintf(fp, " %f", stu[i].sum); // 计算学生的平均分
		fprintf(fp, " %f\n", stu[i].aver);
	}
	fclose(fp); // 关闭文件
}

/* 从文件中读取学生的学号、姓名及成绩等信息，写入到结构体数组stu中 */
void ReadfromFile(STU stu[], int *n, int *m)
{
	FILE *fp;
	if ((fp = fopen("student.txt", "r")) == NULL) // 打开文件
	{
		printf("打开文件失败！\n");
		exit(1);
	}
	fscanf(fp, "%d %d", n, m);	 // 读取学生数量和科目数量
	for (int i = 0; i < *n; i++) // 循环读取每个学生信息
	{
		fscanf(fp, "%lld %s", &stu[i].num, stu[i].name);
		for (int j = 0; j < *m; j++) // 循环读取每个学生的科目成绩
		{
			fscanf(fp, "%f", &stu[i].score[j]);
		}
		fscanf(fp, "%f", &stu[i].sum); // 计算学生的平均分
		fscanf(fp, "%f", &stu[i].aver);
	}
	fclose(fp); // 关闭文件
}

void WriteAccount(char *reg_name, char *reg_password) // 将账户写入文件
{
	FILE *fp;
	if ((fp = fopen("account.txt", "a")) == NULL) // 打开文件
	{
		printf("打开文件失败！\n");
		exit(1);
	}
	fprintf(fp, "%s %s\n", reg_name, reg_password);
	fclose(fp); // 关闭文件
}

int ReadAccount(ACC *account) // 读文件信息
{
	int i;
	system("pause");
	system("cls");

	printf("\n\n\t\t\t欢迎使用学生管理系统\n\n");
	printf("\t\t请输入用户名:");
	scanf("%s", input_name);
	printf("\n\t\t请输入密码:");
	scanf(" %s", input_password);
	FILE *fp = fopen("account.txt", "r");
	if (fp == NULL)
	{
		printf("打开文件失败!\n");
		exit(1);
	}

	for (int i = 0; fscanf(fp, "%s %s", &account[i].username, &account[i].password) == 2; i++)
	{

		if (strcmp(account[i].username, input_name) == 0 && strcmp(account[i].password, input_password) == 0)
		{
			printf("\n\n\t登陆成功\n\n");
			return 1;
		}
	}
	printf("\n\n\t\t尚未注册！\n\n");
	system("pause");
	return 0;
}