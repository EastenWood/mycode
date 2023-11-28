#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int Year(int x);
int main(void)
{
    int n;
    printf("请输入总人数：");
    scanf("%d",&n);
    printf("这个人的年龄是%d岁",Year(n));
    system("pause");
    return 0;
}
int Year(int x)
{
    int age;
    if(x==1)
        age=10;
    else
        age=Year(x-1)+2;
    return age;
}