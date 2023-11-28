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
    if(a>b)
    {
        return r=Gcd(a-b,b);
    }
    if(a<b)
    {
        return r=Gcd(a,b-a);       
    }
    if(a=b)
    {
        return a;
    }
}