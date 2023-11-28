#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int money=100,year;
    float rate;
    printf("请输入产值增长率(小数):");
    scanf("%f",&rate);
    for(year=0;money<200;year++)
    {
        money=money*(1+rate);
    }
    printf("工业产值过%d年后可实现翻一番",year);
    system("pause");
    return 0;
}
