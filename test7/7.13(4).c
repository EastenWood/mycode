#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int IsPrime(int m);//判断是不是素数的声明
int main()//主函数
{
    int m,c,i;
    printf("请输入一个正整数：");
    scanf("%d",&m);
    c=IsPrime(m);
    if(c==0)
    {
        for ( i = 2; i < m; i++)
        {
            if(m%i==0)
            {
                printf("%d  ",i);
            }
        }
        
    }//因子求和
    else
    {
        printf("No divisor!It is a prime number");
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
    return m;
}