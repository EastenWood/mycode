#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 40
void FindMax(int score[],int Num[],int n);
int ReadScore(int score[],int Num[]);
int main(void)
{
    int score[N],Num[N],n;
    n=ReadScore(score,Num);
    FindMax(score,Num,n);
    system("pause");
    return 0;
}

int ReadScore(int score[],int Num[])//输入分数,学号
{
    int i=-1;
    do
    {
        i++;
        printf("Input score:\n");
        scanf("%d",&score[i]);
        printf("Input this Student's Number:\n");
        scanf("%d",&Num[i]);
        printf("\n");
    } while (score[i]>=0);
    return i;
    
}

void FindMax(int score[],int Num[],int n)//找最高分和对应的学号
{
    int max,i,MaxNum,count=0;
    max=score[0];
    MaxNum=Num[0];
    for ( i = 1; i < n; i++)
    {
        if (score[i]>max)
        {
            max=score[i];
            MaxNum=Num[i];
            count=i;
        }
        
    }
    printf("最高分是%d,对应的学号是%d,最大元素的下标是%d",max,MaxNum,count);
    
}