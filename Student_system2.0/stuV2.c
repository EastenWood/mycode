/* 学生成绩管理系统v2.0
  
  某班有最多不超过30人（具体人数由键盘输入）参加期末考试，最多不超过6门（具体门数由键盘输入）
  
 （1）录入每个学生的学号、姓名和各科考试成绩；	
 （2）计算每门课程的总分和平均分；				
				
 （3）按照每个学生的总分由高到低排出名次表；	
 （4）按照每个学生的总分由低到高排出名次表；	
 （5）按照学号由小到大排出成绩表；  
			
 （6）按照学号查询学生排名及其各科考试成绩；	
	
 （7）按照优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60-69分）、不及格（0-59分）5个类别，统计每个类别的人数以及所占的百分比。
 （8）输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。	

  实验要求：使用二维数组作为函数参数。
        菜单驱动，即：程序运行后，先显示菜单，按照用户输入的选项执行相应的操作。

  实验目的：在“学生成绩管理系统V1.0”的基础上，通过增加任务要求，熟悉二维数组作函数参数、模块化程序设计以及增量测试方法。
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10		//字符串的最大长度
#define STU_NUM 30		//最多的学生人数
#define COURSE_NUM 6	//最多的考试科目数

//填写函数声明
int Menu(void);
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m);
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m);
void AverSumofEveryStudent_no_out(long num[], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM]);
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float *x, float *y);
void SwapLong(long *x, long *y);
void SwapStringArray(char *x, char *y);
void AsSortbyNum(long num[], char name[][MAX_LEN],float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void SearchbyNum(long num[], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);
void StatisticAnalysis(float score[][COURSE_NUM], int n, int m);
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m);

int main()
{
	int itemselected;
	int n = 0, m = 0;
	float score[STU_NUM][COURSE_NUM];
	float sum[STU_NUM], aver[STU_NUM];
	long num[STU_NUM];
	char name[STU_NUM][MAX_LEN];
	
	//输入学生的个数
	printf("input student number(n<%d):\n", STU_NUM);
	scanf("%d", &n);
	
	//输入课程的门数
	printf("input course number(n<=%d):\n", COURSE_NUM);
	scanf("%d", &m);
	
	while(1)
	{
		itemselected = Menu();	//显示菜单，并读取用户输入
		switch(itemselected)
		{
			case 1:	ReadScore(num, name, score, n, m);
					break;
			case 2:	AverSumofEveryCourse(score, n, m);
					break;				
			case 3: AverSumofEveryStudent_no_out(num, score, n, m, sum, aver);	//must run this function first, then run next funcion
					SortbyScore(num, name, score, sum, aver, n, m, Descending);
					printf("\nSort in descending order by score:\n");
					PrintScore(num, name, score, sum, aver, n, m);
					break;
			case 4: AverSumofEveryStudent_no_out(num, score, n, m, sum, aver);	//must run this function first, then run next funcion
					SortbyScore(num, name, score, sum, aver, n, m, Ascending);
					printf("\nSort in ascending order by score:\n");
					PrintScore(num, name, score, sum, aver, n, m);
					break;
			case 5: AverSumofEveryStudent_no_out(num, score, n, m, sum, aver);	//must run this function first, then run next funcion
					AsSortbyNum(num, name, score, sum, aver, n, m);
					printf("\nsort in ascending order by number:\n");
					PrintScore(num, name, score, sum, aver, n, m);
					break;			
			case 6: AverSumofEveryStudent_no_out(num, score, n, m, sum, aver);	//must run this function first, then run next funcion
					SearchbyNum(num, score, sum, aver, n, m);
					break;			
			case 7: StatisticAnalysis(score, n, m);
					break;
			case 8: AverSumofEveryStudent_no_out(num, score, n, m, sum, aver);	//must run this function first, then run next funcion 
					PrintScore(num, name, score, sum, aver, n, m);
					AverSumofEveryCourse(score, n, m);
					break;
			case 0: printf("End of program!\n");
					exit(0);
			default: printf("Input error!\n");			
		}
	}
	system("pause");
	return 0;
}

/* 显示菜单，并获得用户键盘输入的数据 */
int Menu(void)
{
	int itemSelected;
	printf("\nManagement for student's scores \n");
	printf("1—input record \n");										//录入每个学生的学号、姓名和考试成绩；
	printf("2—caculate total and average acore of every course \n");	//计算每门课程的总分和平均分；
	printf("3—sort in descending order by total score of every student\n");			//按照每个学生的总分由高到低排出名次表
	printf("4—sort in ascending order by total score of every student \n");			//按照每个学生的总分由低到高排出名次表
	printf("5—sort in ascending order by number \n");					//按照学号由小到大排出成绩表
	printf("6—search by number \n");									//按照学号查询学生排名及其各科考试成绩；
	printf("7—statistic analysis \n");									//统计各个分数段的学生人数及其所占的百分比
	printf("8—list record \n");										//输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分。
	printf("0—exit \n");
	printf("please input your choice:\n");	
	scanf("%d", &itemSelected);				//读入用户输入
	
	return itemSelected;	
}

/*录入每个学生的学号、姓名和各科考试成绩*/
void ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n, int m)
{
	int i,j;
    for(i = 0; i < n; i++)
	{
		printf("Input student's ID and name eg:101 cg\n");
		scanf("%ld %s", &num[i], name[i]);
		printf("Input student's score:\n");
		for (j = 0; j < m; j++)
		{
			scanf("%f", &score[i][j]);
		}	
	}
}

/* 计算每门课程的总分和平均分 */
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m)  // m门课程，n个学生
{
	int i,j;
	float sum[m];
	for(j = 0; j < m; j++)
	{
		for ( i = 0; i < n; i++)
		{
			sum[j]=sum[j]+score[i][j];
		}
	}
	for(j = 0; j < m; j++)
	{
		printf("第%d门课的总分为%f,平均分为%f\n",j+1,sum[j],sum[j]/n);
	}
}

/* 计算每个学生各门课程的总分和平均分——无输出 */
void AverSumofEveryStudent_no_out(long num[], float score[][COURSE_NUM], int n, int m, float sum[STU_NUM], float aver[STU_NUM])	// m门课程，n个学生
{
	int i,j;
	for ( i = 0; i < n; i++)
	{
		sum[i] = 0;
	    for ( j = 0; j < m; j++)
		{
			sum[i] = sum[i]+score[i][j];
		}
		aver[i]=sum[i]/m;
	}
	
}

/* 用选择法，将数组sum的元素值排序 */
void SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m, int(*compare)(float a, float b))
{
	int i, j, k;
   for (i = 0; i < n - 1; i++)
   {
    k = i;
    for (j = i + 1; j < n; j++)
    {
      if ((*compare)(sum[j], sum[k]))
      {
        k = j;
      }
    }
    if (k != i)
	{
		int p;
		for ( p = 0; p < m; p++)
		{
			SwapFloat(&score[k][p],&score[i][p]);
		}
      	SwapLong(&num[k], &num[i]);
      SwapFloat(&sum[k], &sum[i]);
      SwapFloat(&aver[k],&aver[i]);
      SwapStringArray(name[k],name[i]);
    }
  }
}

/* 使得数据按照升序排序 */
int Ascending(float a, float b)
{
	return a<b;
}

/* 使得数据按照降序排序 */
int Descending(float a, float b)
{
	return a>b;
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
void SwapLong(long *x, long *y)
{
	long temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void SwapStringArray(char *x, char *y)
{
char temp[10];
strcpy(temp,x);
strcpy(x,y);
strcpy(y,temp);
}


/* 按照选择法，将数组num的元素值按照从小到大排序 */
void AsSortbyNum(long num[], char name[][MAX_LEN],float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
    	k=i;
    	for (j = i + 1; j < n; j++)
    	{
      		if (num[j] < num[k])
      		{
        		k = j;
      		}
    	}
    	if (k != i)
    	{
			int p;
			for ( p = 0; p < m; p++)
		{
			SwapFloat(&score[k][p],&score[i][p]);
		}
      	SwapLong(&num[k], &num[i]);
      SwapFloat(&sum[k], &sum[i]);
      SwapFloat(&aver[k],&aver[i]);
      SwapStringArray(name[k],name[i]);
    	}
  }
}

/* 按照学号查询学生排名及其各科考试成绩 */
void SearchbyNum(long num[], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	int i, j, rank = 1, flag = 0, k;
    long x;
  	printf("Input the searching number:\n");
  	scanf("%d", &x);
  	for (i = 0; i < n; i++)
  	{
    	if (num[i] == x)
    	{
      		k = i;
      		for (j = 0; j < n; j++)
      		{
        		if (sum[j] > sum[i])
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
		printf("第%d门的成绩为:%f\n",j+1, score[k][j]);
	}
  }
  else
    printf("未找到\n");
}

/* 按照优秀（90-100分）、良好（80-89分）、中等（70-79分）、及格（60-69分）、不及格（0-59分）5个类别，统计每个类别的人数以及所占的百分比 */
void StatisticAnalysis(float score[][COURSE_NUM], int n, int m)	//m门课程，n个学生
{
	int A,B,C,D,E,i,j;
  for (i = 0; i < m; i++)
  {
	A = 0, B = 0, C = 0, D = 0, E = 0;
	for(j=0; j < n; j++)
	{
    	if (score[j][i]>= 90 && score[j][i] <= 100)
      		A++;
    	if (score[j][i] >= 80 && score[j][i] <= 89)
      		B++;
    	if (score[j][i] >= 70 && score[j][i] <= 79)
      		C++;
    	if (score[j][i] >= 60 && score[j][i]<= 69)
      		D++;
    	if (score[j][i] >= 0 && score[j][i] <= 59)
      		E++;
	}
	printf("第%d门课中优秀有%d人,占比%f\n",i+1, A, (float)A / n);
    printf("\t良好有%d人,占比%f\n", B, (float)B / n);
    printf("\t中等有%d人,占比%f\n", C, (float)C / n);
    printf("\t及格有%d人,占比%f\n", D, (float)D / n);
    printf("\t不及格有%d人,占比%f\n", E, (float)E / n);
  }
  
}

/* 输出每个学生的学号、姓名、各科考试成绩、总分、平均分以及每门课程的总分和平均分 */
void PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float sum[], float aver[], int n, int m)
{
	int i,j;
  	for (i = 0; i < n; i++)
  	{
		printf("%ld\t%s\t的第1门成绩为%.0f\n", num[i],name[i],score[i][0]);
		for ( j = 1; j < m; j++)
		{
			printf("		第%d门成绩为%.0f\n",j+1,score[i][j]);
		}
		printf("该生总分为%f\t平均分为%f\n",sum[i],aver[i]);
  	}
}

