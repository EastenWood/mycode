#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int Gcd(int a,int b);
int main()
{
    int a,b;
    printf("输入两个正整数：");
    scanf("%d %d",&a,&b);
    printf("这两个数的最大公约数是%d",Gcd(a,b));
    system("pause");
    return 0;

}
int Gcd(int a,int b)
{
    int c;
    c=a>b?a:b;
    for(c;c>=1;c--)
    {
        if(a%c==0&&b%c==0)
        break;
    }
    return c;
    

}