#include<stdlib.h>
#include<stdio.h>
#include<math.h>
long Fact(int a);
int main(void)
{
    int a;
    printf("输入一个正整数n:");
    scanf("%d",&a);
    printf("%d的阶乘等于%ld",a,Fact(a));
    system("pause");
    return 0;

}
long Fact(int a)
{
    int i;
    long result;
    for(i=1,result=1;i<=a;i++)
    {
        result=result*i;
    }
    return result;

}