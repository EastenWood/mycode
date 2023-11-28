#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
   double a,b,c;
    for(b=0;b<=25;b++)
    {
        a=(100-4*b)/7;
        c=100-b-(100-4*b)/7;
        if (a==(int)(100-4*b)/7&&c==(int)100-b-(100-4*b)/7)
        {
           printf("%.0f %.0f %.0f\n",a,b,c);
        }
    }
    system("pause");
    return 0;
}
