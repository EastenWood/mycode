#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int IsPrime(int m);
void OutputPrimeFactor(int m);//因子连乘

int main()//主函数
{
    int n;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    if(IsPrime(n))
    {
        printf("It is a prime number");
    }
    else
    {
        printf("%d=",n);
        OutputPrimeFactor(n);
    }
    system("pause");
    return 0;

}

int IsPrime(int m)//判断是不是素数
{
    int i,n;
    n=(int)(sqrt(m));
    for(i=2;i<=n;i++)
    {
        if(m%i==0)
        {
           return 0;
        }
    }
    return 1;
}

void OutputPrimeFactor(int m)
{
    int i;
    for(i=2;i<m;i++)
    {
        if(m%i==0)
        {
            printf("%d*",i);
            OutputPrimeFactor(m/i);
            return;
        }
    }
    printf("%d",m);
}