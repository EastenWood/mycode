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
    int i,j,sum[30];
    STUDENT stu[30]={{100310121,"王刚",'M',{1991,5,19},{72,83,90,82}},{100310122,"李小红",'M',{1992,8,20},{88,92,78,78}},{100310123,"王丽红",'F',{1991,9,19},{98,72,89,66}},{100310124,"陈莉莉",'F',{1992,3,22},{87,95,78,90}}};
    for ( i = 0; i < 4; i++)
    {
        sum[i]=0;
        for ( j = 0; j < 4; j++)
        {
            sum[i]=sum[i]+stu[i].socre[j];
        }
        printf("%10ld%8s%6d/%02d/%02d%4d%4d%4d%4d%6.1f  ",stu[i].studentID,stu[i].studentName,stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day,stu[i].socre[0],stu[i].socre[1],stu[i].socre[2],stu[i].socre[3],sum[i]/4.0);
        if(stu[i].studentSex=='M')
        printf("性别为男\n");
        else
        printf("性别为女\n");
    }
    system("pause");
    return 0;
    
}