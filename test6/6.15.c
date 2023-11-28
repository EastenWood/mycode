#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    for(a=0;a<=98;a++)
    {
        for (b=0;b<+98; b++)
        {
           if(2*a+4*b==386&&a+b==98)
           printf("%d %d\n",a,b);
        }
        
    }
    
    system("pause");
    return 0;
}