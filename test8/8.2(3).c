#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int a[10],n,max,min,maxPos,minPos;
    for ( n = 0; n < 10; n++)
    {
        scanf("%d",&a[n]);
    }
    max=min=a[0];
    maxPos=minPos=0;
    for ( n = 0; n < 10; n++)
    {
        if(a[n] > max)
        {
            max=a[n];
            maxPos=n;
        }
        else if(a[n] < min)
        {
            min=a[n];
            minPos=n;
        }
    }
    printf("max=%d,pos=%d\n",max,maxPos);
    printf("min=%d,pos=%d\n",min,minPos);
    system("pause");
    return 0;
    
    
}