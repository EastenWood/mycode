#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(void)
{
    int i,sum=0;
    for(i=1;i<=101;i=i+2)
    {
        sum=sum+i;
    }
    printf("sum=%d\n",sum);
    system("pause");
    return 0;
}