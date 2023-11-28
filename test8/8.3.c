#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 40
int ReadScore(int score[],int n);
int main(void)
{
    int score[N],n;
    printf("Input number n:");
    scanf("%d",&n);
    printf("不及格人数有%d人",ReadScore(score,n));
    system("pause");
    return 0;
}

int ReadScore(int score[],int n)
{
    int i,count=0;
    printf("Input score(百分制):");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&score[i]);
        if(score[i]<60)
        count++;
    }
    return count;
    
}