#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void IsPrime(int m);

int main()
{
    int m;
    printf("请输入一个正整数：");
    scanf("%d",&m);
    IsPrime(m);
    system("pause");
    return 0;
}

void IsPrime(int m)
{                                          
    int i,n;
    n=(int)(sqrt(m));
    for(i=2;i<=n;i++)
    {
        if(m%i==0)
        {
            printf("%d is not a prime number\n",m);
            goto End;
        }
    }
    printf("%d is a prime number\n",m);
    End:
    return;

}