#include<stdlib.h>
#include<stdio.h>
int main(void)
{
    int month;
    char *Emonth[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("请输入一个月份(1-12):\n");
    scanf("%d",&month);
    if ((1<=month)&&(month<=12))
    {
        printf("%s",Emonth[month-1]);
    }
    else
        printf("Illegal month");
        system("pause");
    

}