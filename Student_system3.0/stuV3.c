/* 学生成绩管理系统v3.0

  某班有最多不超过30人（具体人数由键盘输入）参加期末考试，最多不超过6门（具体门数由键盘输入）

 （1）录入每个学生的学号、姓名和各科考试成绩；
 （2）计算每门课程的总分和平均分；
 （3）计算每个学生的总分和平均分；
 （4）按照每个学生的总分由高到低排出名次表；
 （5）按照每个学生的总分由低到高排出名次表；
 （6）按照学号由小到大排出成绩表；
 （7）按照姓名的字典顺序排出成绩表；
 （8）按照学号查询学生排名及其各科考试成绩；
 （9）按照姓名查询学生排名及其各科考试成绩；
 （10）按照优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60-69分）、不及格（0-59分）5个类别，统计每个类别的人数以及所占的百分比。
 （11）输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。	//比v3.0增加了“多门课程”

  实验要求：定义结构体类型，用结构体数组作函数参数。
			菜单驱动，即：程序运行后，先显示菜单，按照用户输入的选项执行相应的操作。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10	 // 字符串的最大长度
#define STU_NUM 30	 // 最多的学生人数
#define COURSE_NUM 6 // 最多的考试科目数

typedef struct student
{
	long long num;			 // 每个学生的学号
	char name[MAX_LEN];		 // 每个学生的姓名
	float score[COURSE_NUM]; // 每个COURSE_NUM门功课的成绩
	float sum;				 // 每个学生的总成绩
	float aver;				 // 每个学生的平均成绩
} STU;

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

int main()
{
	int itemSelected;
	int n = 0, m = 0; // m门课程，n个学生
	STU stu[STU_NUM];

	// 输入学生的个数
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);

	// 输入课程的门数
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);

	while (1)
	{
		itemSelected = Menu(); // 显示菜单，并读取用户输入
		switch (itemSelected)
		{
		case 1:
			ReadScore(stu, n, m);
			break;
		case 2:
			AverSumofEveryCourse(stu, n, m);
			break;
		case 3:
			AverSumofEveryStudent(stu, n, m);
			break;
		case 4:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 5:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Ascending);
			printf("\nSort in ascending order by score:\n");
			PrintScore(stu, n, m);
			break;
		case 6:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			AsSortbyNum(stu, n, m);
			printf("\nsort in ascending order by number:\n");
			PrintScore(stu, n, m);
			break;
		case 7:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyName(stu, n, m);
			printf("\nsort in dictionary order by name:\n");
			PrintScore(stu, n, m);
			break;
		case 8:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);		 // sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			SearchbyNum(stu, n, m);
			break;
		case 9:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			SortbyScore(stu, n, m, Descending);		 // sort in descending order by score
			printf("\nSort in descending order by score:\n");
			PrintScore(stu, n, m);
			SearchbyName(stu, n, m);
			break;
		case 10:
			StatisticAnalysis(stu, n, m);
			break;
		case 11:
			AverSumofEveryStudent_no_out(stu, n, m); // must run this function first, then run next funcion
			PrintScore(stu, n, m);
			AverSumofEveryCourse(stu, n, m);
			break;
		case 0:
			printf("End of program!\n");
			exit(0);
		default:
			printf("Input error!\n");
		}
	}
	return 0;
}

/* 显示菜单，并获得用户键盘输入的数据 */
int Menu(void)
{
	int itemSelected;
	printf("\nManagement for student's scores \n");
	printf("1—input record \n");									  // 录入每个学生的学号、姓名和考试成绩；
	printf("2—caculate total and average acore of every course \n");  // 计算每门课程的总分和平均分；
	printf("3—caculate total and average acore of every student \n"); // 计算每个学生的总分和平均分；
	printf("4—sort in descending order by score of sum \n");		  // 按照每个学生的总分由高到低排出名次表
	printf("5—sort in ascending order by score of sum \n");			  // 按照每个学生的总分由低到高排出名次表
	printf("6—sort in ascending order by number \n");				  // 按照学号由小到大排出成绩表
	printf("7—sort in dictionary order by name \n");				  // 按照姓名的字典顺序排出成绩表；
	printf("8—search by number \n");								  // 按照学号查询学生排名及其各科考试成绩；
	printf("9—search by name \n");									  // 按照姓名查询学生排名及其各科考试成绩；
	printf("10—statistic analysis \n");								  // 统计各个分数段的学生人数及其所占的百分比
	printf("11—list record \n");									  // 输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。
	printf("0—exit \n");

	printf("please input your choice:\n");
	scanf("%d", &itemSelected); // 读入用户输入

	return itemSelected;
}

/* 输入n个学生的m门课的成绩 */
void ReadScore(STU stu[], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("Input record%d:eg. 101 陈根\n", i + 1);
		scanf("%lld", &stu[i].num);
		scanf("%s", stu[i].name);
		printf("输入成绩：\n");
		for (j = 0; j < m; j++)
		{
			scanf("%f", &stu[i].score[j]);
		}
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
			if (stu[j].score[i] >= 50 && stu[j].score[i] <= 59)
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
		printf("%lld\t%s\t的第1门成绩为%.0f\n", stu[i].num, stu[i].name, stu[i].score[0]);
		for (j = 1; j < m; j++)
		{
			printf("		第%d门成绩为%.0f\n", j + 1, stu[i].score[j]);
		}
		printf("该生总分为%f\t平均分为%f\n", stu[i].sum, stu[i].aver);
	}
}
