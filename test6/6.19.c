#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    float b,c,sum;
    for(a=1,c=0.01,sum=0;a<=29;a++)
    {
        c=c*2;
        sum=sum+c;
    }
    printf("富豪给陌生人%f\n",sum);
    b=30*100000;
    printf("陌生人给富豪%.0f",b);
    system("pause");
    return 0;
}
