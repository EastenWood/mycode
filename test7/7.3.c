#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int max(int a,int b);//函数原型声明
int main()
{
    int a,b,c;
    printf("输入两个整数：");
    scanf("%d %d",&a,&b);
    c=max(a,b);
    printf("max=%d\n",c);
    system("pause");
    return 0;
}

int max(int a,int b)
{
    return a>b?a:b;
}