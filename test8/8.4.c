#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 40
int Readscore(int score[]);
int Average(int score[],int n);
int main(void)
{
    int score[N],aver,n,i,count=0;
    n=Readscore(score);
    aver=Average(score,n);
    for ( i = 0; i < n; i++)
    {
        if (score[i]>aver)
        {
            count++;
        }    
    }
    printf("成绩高于平均数的人数有%d",count);
    system("pause");
    return 0;
    
}

int Readscore(int score[])
{
    int i=-1;
    do
    {
        i++;
        printf("Input score:");
        scanf("%d",&score[i]);
    } while (score[i]>=0);
    return i;
}

int Average(int score[],int n)
{
    int i,sum=0;
    for ( i = 0; i < n; i++)
    {
        sum+=score[i];
    }
    return n>0?sum/n:-1;
    
}