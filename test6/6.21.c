#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int t,n;
    for(t=0,n=0;t<=140;t++)
    {
        if(t%5==0&&t<=100)
        {
            n++;
        continue;
        }
        if(t%6==0&&t<=120)
        {
            n++;
        continue;
        }
        if(t%7==0&&t<=140)
        {
            n++;
        continue; 
        }       
    }
    printf("%d",n);   
    system("pause");
    return 0;    
}