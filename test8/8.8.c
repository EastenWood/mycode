#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 40
#define M 11
float Average(int feedback[],int n);
int Mode(int count[],int n);
float Median(int feedback[],int n);

int main(void)
{
    int i,feedback[N];
    int count[M]={0};
    printf("Input the feedbacks of 40 students:\n");
    for(i=0;i<N;i++)//输入40位学生的反馈意见
    {
        scanf("%d",&feedback[i]);
    }
    printf("平均数为 %f\n",Average(feedback, N));
    for ( i = 0; i < N; i++)
    {
        switch (feedback[i])
        {
        case 1:
            count[1]++;
            break;
        case 2:
            count[2]++;
            break;
        case 3:
            count[3]++;
            break;
        case 4:
            count[4]++;
            break;
        case 5:
            count[5]++;
            break;
        case 6:
            count[6]++;
            break;
        case 7:
            count[7]++;
            break;
        case 8:
            count[8]++;
            break;
        case 9:
            count[9]++;
            break;
        case 10:
            count[10]++;
            break;
        default:
        printf("Input error!");
            break;
        }
    }
    printf("众数为%d\n",Mode(count,M));
    printf("中位数为%f\n",Median(feedback,N));
    system("pause");
    return 0;
}
float Average(int feedback[],int n)//算平均值
{
    int i;
    float sum=0;
    for ( i = 0; i < 40; i++)
    {
        sum=sum+feedback[i];
    }
    return sum/n;
    
}
int Mode(int count[],int n)//找众数
{
    int max,i,c;
    max=count[1];
    for ( i = 2; i < M; i++)
    {
        if (count[i]>max)
        {
            max=count[i];
            c=i;
        }   
    }
    return c;   
}
float Median(int feedback[],int n)//输出中位数
{
    int i,j,temp;
    float Median;
    for ( i = 0; i < n-1; i++)
    {
        for (j= i+1; j < n; j++)
        {
            if (feedback[j]>feedback[i])
            {
                temp=feedback[j];
                feedback[j]=feedback[i];
                feedback[i]=temp;
            }
            
        }
        
    }
    Median=(feedback[20]+feedback[21])/2;
   
}
