#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(void)
{
   int n=1;
   float term=1.0,sign=1,sum=0;
   while(n<=10000)
   {
       term=(1.0/n)*sign;
       sum=sum+term;
       sign=-sign;
       n++;
   }
   printf("sum=%f\n",sum);
   system("pause");
   return 0;
}