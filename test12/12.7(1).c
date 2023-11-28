
#include<stdio.h>
#include<stdlib.h>
#define N 30
typedef struct date
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
        int score[4];
        float aver;
        int sum;
}STUDENT;
void InputScore(STUDENT stu[],int n,int m);
void AverScore(STUDENT stu[],int n,int m);
void PrintScore(STUDENT stu[],float aver[],int n,int m);
int main(void)
{
        float aver[N];
        STUDENT stu[N];
        int n;
        printf("How many students?\n");
        scanf("%d",&n);
        InputScore(stu,n,4);
        AverScore(stu,n,4);
        PrintScore(stu,aver,n,4);
        system("pause");
        return 0;
}
void InputScore(STUDENT stu[],int n,int m)
{
        int i,j;
        for(i=0;i<n;i++)
        {
                printf("Input record%d:\n",i+1);
                scanf("%ld",&stu[i].studentID);
                scanf("%s",stu[i].studentName);
                scanf(" %c",&stu[i].studentSex);
                scanf("%d",&stu[i].birthday.year);
                scanf("%d",&stu[i].birthday.month);
                scanf("%d",&stu[i].birthday.day);
                for(j=0;j<m;j++)
                {
                        scanf("%d",&stu[i].score[j]);
                }
        }
}
void AverScore(STUDENT stu[],int n,int m)
{
        int i,j;
        for(i=0;i<n;i++)
        {
                stu[i].sum=0;
                for(j=0;j<m;j++)
                {
                        stu[i].sum=stu[i].sum+stu[i].score[j];
                }
                stu[i].aver=(float)stu[i].sum/m;
        }
}
void PrintScore(STUDENT stu[],float aver[],int n,int m)
{
        int i,j;
        printf("Result:\n");
        for(i=0;i<n;i++)
        {
                printf("%10ld%8s%3c%6d/%02d/%02d%4d%6.1f",stu[i].studentID
                                                 ,stu[i].studentName
                                                 ,stu[i].studentSex
                                                 ,stu[i].birthday.year
                                                 ,stu[i].birthday.month
                                                 ,stu[i].birthday.day
                                                 ,stu[i].sum
                                                 ,stu[i].aver);
                for(j=0;j<m;j++)
                {
                    printf("%4d",stu[i].score[j]);
                }
                printf("\n");
        }
}