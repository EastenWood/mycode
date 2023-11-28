#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int LCM(int a,int b);
int main()
{
    int a,b;
    printf("输入两个正整数：");
    scanf("%d %d",&a,&b);
    printf("二者的最小 公倍数为%d",LCM(a,b));
    system("pause");
    return 0;
}

int LCM(int a,int b)
{
    int i;
    for(i=1;;i++)
    {
        if(i%a==0&&i%b==0)
        break;
    }
    return i;

}