#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int find=0,x=1;
    int n;
    printf("请输入一个大于1的数:");
    scanf("%d",&n);
    while(!find)
    {
        if(x<=n)
        {
            printf("%d的平方=%d\n",x,x*x);
            printf("%d的立方=%d\n",x,x*x*x);
            x++;
        }

    }
    system("pause");
    return 0;
}