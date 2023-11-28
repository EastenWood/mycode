#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int Gcd(int a,int b);
int main()
{
    int a,b;
    printf("输入两个正整数：");
    scanf("%d %d",&a,&b);
    printf("两个数的最大公约数是%d",Gcd(a,b));
    system("pause");
    return 0;
}
int Gcd(int a,int b)
{
    int r;
    r=a%b;
    for(r;r!=0;)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}