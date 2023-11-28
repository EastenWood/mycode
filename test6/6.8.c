#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n=1;
   float term=1.0,sign=1,sum=0,pi;
   while(n<=10000)
   {
       term=(1.0/n)*sign;
       sum=sum+term;
       sign=-sign;
       n=n+2;
   }
   printf("pi=%f\n",4*sum);
   n=(n-2+1)/2.0+1;
   printf("累加的项数有%d项",n);
   system("pause");
   return 0;
}
