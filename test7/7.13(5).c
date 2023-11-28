#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void IsPerfect(int m);

int main()
{
    int n;
    printf("请输入一个正整数n:");
    scanf("%d",&n);
    IsPerfect(n);
    system("pause");
    return 0;
}

void IsPerfect(int m)
{
    int i,sum;
    for ( i = 1,sum=0; i <m; i++)
    {
        if(m%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum==m)
    {
        printf("%d is a perfect number",m);
    }
    
}