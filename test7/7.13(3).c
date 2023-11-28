#include<stdlib.h>
#include<stdio.h>
#include<math.h>
long int SumPrime(int n);
int IsPrime(int m);

int main()
{
    int n;
    printf("请输入一个正整数n:");
    scanf("%d",&n);
    printf("1~%d之间的所有素数之和为%ld",n,SumPrime(n));
    system("pause");
    return 0;
}

long int SumPrime(int n)
{
    int i;
    long int sum=0;
    for(i=2,sum;i<=n;i++)
    {
        sum=sum+IsPrime(i);
    }
    return sum;
}

int IsPrime(int m)
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
    return m;
}