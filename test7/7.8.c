#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int Min();
void main(void)
{
    printf("原来至少有%d个",Min());
    system("pause");
}
int Min()
{
   int i=1;
   float x=1,y;
   y=5*x+1;
   do
   {
    y=y*5/4+1;
    i++;
    if(y!=(int)y)
    {
        x=x+1;
        y=5*x+1;
        i=1;
    }
   } while (i<5);
   return (int)y;
}