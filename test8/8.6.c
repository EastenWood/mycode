#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Exchange(int a[],int maxPos,int minPos);
int main(void)
{
    int a[10],n,max,min,maxPos,minPos;
    printf("请输入十个整数:\n");
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
    Exchange(a,maxPos,minPos);
    for ( n = 0; n < 10; n++)
    {
        printf("%d  ",a[n]);
    } 
    system("pause");
    return 0;   
}

void Exchange(int a[],int maxPos,int minPos)
{
    int temp;
    temp=a[maxPos];
    a[maxPos]=a[minPos];
    a[minPos]=temp;
}