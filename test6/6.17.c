#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int count;
    double a,b,c;
    for(a=0;a<=10;a++)
    {
        for(b=0;b<=20;b++)
        {
            for(c=0;c<=100;c++)
            {
                if (a+b+c==50&&10*a+5*b+c==100)
                {
                    printf("10元有%.0f张 5元有%.0f张 1元有%.0f张\n",a,b,c);
                    count=count+1;
                    printf("count=%d",count);
                }
                
            }
        }
    }
    system("pause");
    return 0;
}