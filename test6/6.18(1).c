#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    for(a=1;a<=9;a++)
    {
        printf("%2d ",a);
    }
    printf("\n");
    
    for(b=1;b<=9;b++)
    {
         printf(" - ");
    }
   
    printf("\n");
    for(a=1;a<=9;a++)
    {
        for(b=1;b<=9;b++)
        {
            c=a*b;
            printf("%2d ",c);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}