#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int PositiveNum(int a[],int n);
int main(void)
{
    int a[10],i;
    printf("请输入10个整数\n");
    for ( i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("这些数中有%d个正数\n",PositiveNum(a,10));
    system("pause");
    return 0;
}
int PositiveNum(int a[],int n)
{
    int i,count=0;
    for ( i = 0; i < n; i++)
    {
        if(a[i]>0)
        count++;
    }
    return count;
    
}