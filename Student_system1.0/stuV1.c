/* 学生成绩管理系统v1.0

  某班有最多不超过30人（具体人数由键盘输入）参加某门课程的考试，实现以下功能：
 （1）录入每个学生的学号和考试成绩；
 （2）计算课程的总分和平均分；
 （3）按照成绩由高到低排出名次表；
 （4）按照成绩由低到高排出名次表； //比v1.0增加的功能
 （5）按照学号由小到大排出成绩表；
 （6）按照学号查询学生排名及其考试成绩；
 （7）按照优秀（90-100分）、良好、中等、及格、不及格5个类别，统计每个类别的人数以及所占的百分比。
 （8）输出每个学生的学号、考试成绩、以及课程的总分和平均分。

  要求：使用一维数组、指针和函数指针作为函数参数。
        程序运行后，先显示菜单，按照用户输入的选项执行相应的操作。
*/

#include <stdio.h>
#include <stdlib.h>
#define STU_NUM 30 // 最多的学生人数
// 填写函数声明
int Menu(void);
void ReadScore(long num[], float score[], int n);
void AverSumofScore(float score[], int n);
void SortbyScore(long num[], float score[], int n, int (*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void SwapFloat(float *x, float *y);
void SwapLong(long *x, long *y);
void AsSortbyNum(long num[], float score[], int n);
void SearchbyNum(long num[], float score[], int n);
void StatisticAnalysis(float score[], int n);
void PrintScore(long num[], float score[], int n);

int main()
{
  int itemselected;
  int n = 0;
  float score[STU_NUM];
  long num[STU_NUM];

  // 输入学生的个数
  printf("input student number(n<%d):\n", STU_NUM);
  scanf("%d", &n);

  while (1)
  {
    itemselected = Menu(); // 显示菜单，并读取用户输入
    switch (itemselected)
    {
    case 1:
      ReadScore(num, score, n);
      break;
    case 2:
      AverSumofScore(score, n);
      break;
    case 3:
      SortbyScore(num, score, n, Descending);
      printf("\nSort in descending order by score:\n");
      PrintScore(num, score, n);
      break;
    case 4:
      SortbyScore(num, score, n, Ascending);
      printf("\nSort in ascending order by score:\n");
      PrintScore(num, score, n);
      break;
    case 5:
      AsSortbyNum(num, score, n);
      printf("\nsort in ascending order by number:\n");
      PrintScore(num, score, n);
      break;
    case 6:
      SearchbyNum(num, score, n);
      break;
    case 7:
      StatisticAnalysis(score, n);
      break;
    case 8:
      PrintScore(num, score, n);
      AverSumofScore(score, n);
      break;
    case 0:
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
  printf("\nManagement for student's scores \n");
  printf("1. input record \n");
  printf("2. caculate total and average acore of course \n");
  printf("3. sort in descending order by score \n");
  printf("4. sort in ascending order by score \n");
  printf("5. sort in ascending order by number \n");
  printf("6. search by number \n");
  printf("7. statistic analysis \n");
  printf("8. list record \n");
  printf("0. exit \n");

  printf("please input your choice:");
  scanf("%d", &itemSelected); // 读入用户输入
  return itemSelected;
}

/* 输入n个学生的某门课的成绩 */
void ReadScore(long num[], float score[], int n)
{
  int i;
  printf("input student's ID and score:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%10ld", &num[i]);
    scanf("%f", &score[i]);
  }
}

/* 计算课程的总分和平均分 */
void AverSumofScore(float score[], int n)
{
  int i;
  float sum = 0;

  for (i = 0; i < n; i++)
  {
    sum = sum + score[i];
  }

  printf("sum=%.0f, aver=%.2f\n", sum, n > 0 ? sum / n : 0);
}

/* 用选择法，将成绩（存于数组score的元素）排序 */
void SortbyScore(long num[], float score[], int n, int (*compare)(float a, float b))
{
  int i, j, k;
  for (i = 0; i < n - 1; i++)
  {
    k = i;
    for (j = i + 1; j < n; j++)
    {
      if ((*compare)(score[j], score[k]))
      {
        k = j;
      }
    }
    if (k != i)
    {
      SwapFloat(&score[k], &score[i]);
      SwapLong(&num[k], &num[i]);
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
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/* 交换两个长整型数据 */
void SwapLong(long *x, long *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

/* 按照选择法，将数组num的元素值按照从小到大排序 */
void AsSortbyNum(long num[], float score[], int n)
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
      SwapLong(&num[k], &num[i]);
      SwapFloat(&score[k], &score[i]);
    }
  }
}

/* 按照学号，查询学生排名及其考试成绩； */
void SearchbyNum(long num[], float score[], int n)
{
  int i, j, rank = 1, flag = 0, k;
  long m;
  printf("Input the searching number:\n");
  scanf("%d", &m);
  for (i = 0; i < n; i++)
  {
    if (num[i] == m)
    {
      k = i;
      for (j = 0; (j != i) && (j < n); j++)
      {
        if (score[j] > score[i])
          rank++;
      }
      flag = 1;
    }
  }
  if (flag == 1)
    printf("排名为%d,考试成绩为%f\n", rank, score[k]);
  else
    printf("未找到\n");
}

/* 统计各个分数段的学生人数及其所占的百分比 */
void StatisticAnalysis(float score[], int n)
{
  int A = 0, B = 0, C = 0, D = 0, E = 0, i;
  for (i = 0; i < n; i++)
  {
    if (score[i] >= 90 && score[i] <= 100)
      A++;
    if (score[i] >= 80 && score[i] <= 89)
      B++;
    if (score[i] >= 70 && score[i] <= 79)
      C++;
    if (score[i] >= 60 && score[i] <= 69)
      D++;
    if (score[i] >= 0 && score[i] <= 59)
      E++;
    printf("优秀有%d人,占比%f\n", A, (float)A / n);
    printf("良好有%d人,占比%f\n", B, (float)B / n);
    printf("中等有%d人,占比%f\n", C, (float)C / n);
    printf("及格有%d人,占比%f\n", D, (float)D / n);
    printf("不及格有%d人,占比%f\n", E, (float)E / n);
  }
}

/* 打印学生成绩 */
void PrintScore(long num[], float score[], int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    printf("%ld\t%.0f\n", num[i], score[i]);
  }
}