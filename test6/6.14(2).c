#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c;
    for (a=0;a<=30; a++)
    {
        for (b=0; b<=30; b++)
        {
           for (c=0; c<=30; c++)
           {
                if (3*a+2*b+c==50&&a+b+c==30)
                {
                    printf("%d %d %d\n",a,b,c);
                }
            
           }
           
        }
        
    }
    system("pause");
    return 0;
    
}