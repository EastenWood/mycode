#include<stdlib.h>
#include<stdio.h>
typedef struct data
{
    int year;
    int month;
    int day;
}DATE;
typedef struct student
{
    long studentID;
    char studentName[10];
    char studentSex;
    DATE birthday;
    int socre[4];
}STUDENT;
int main(void)
{
    int i,j,sum[30],n;
    STUDENT stu[30];
    printf("请输入学生人数：\n");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("输入学生学号,姓名,性别(M/F),出生日期（年，月，日）,数学，英语，计算机原理，程序设计：\n");
        scanf("%ld",&stu[i].studentID);
        scanf("%s",stu[i].studentName);
        getchar();
        scanf("%c",&stu[i].studentSex);
        scanf("%d",&stu[i].birthday.year);
        scanf("%d",&stu[i].birthday.month);
        scanf("%d",&stu[i].birthday.day);
        scanf("%d",&stu[i].socre[0]);
        scanf("%d",&stu[i].socre[1]);
        scanf("%d",&stu[i].socre[2]);
        scanf("%d",&stu[i].socre[3]);        
    }
    for ( i = 0; i < n; i++)
    {
        sum[i]=0;
        for (j = 0; j < 4; j++)
        {
            sum[i]=sum[i]+stu[i].socre[j];
        }
        printf("%10ld%8s%3c%6d/%02d/%02d%4d%4d%4d%4d%6.1f\n ",stu[i].studentID,stu[i].studentName,stu[i].studentSex,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].socre[0],stu[i].socre[1],stu[i].socre[2],stu[i].socre[3],sum[i]/4.0);    
    }
    system("pause");
    return 0;
    
}

