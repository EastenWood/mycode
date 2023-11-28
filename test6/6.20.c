#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    for(a=0;a<=9;a++)
    {
        for(b=0;b<=9;b++)
        {           
            for (c=0; c<=100; c++)
            {
                if(a*1000+a*100+b*10+b==c*c&&a!=b)
                printf("%d%d%d%d",a,a,b,b);
            }
                    
        }
    }
    system("pause");
    return 0;

}