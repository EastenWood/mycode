#include <stdio.h>
#include <stdlib.h>

int main()
{
   int C,F;
   for(F=0;F<=300;F=F+10)
   {
        C=5.0/9*(F-32);
       printf("%d华氏温度对应%d摄氏温度\n",F,C);
   }
   system("pause");
   return 0;
}