#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Fib(long f[],int n);
int main(void)
{
    
    int n,i;
    printf("请输入需要的斐波那契数列的项数：\n");
    scanf("%d",&n);
    long f[n+1];
    printf("前%d项为:\n",n);
    Fib(f,n);
    for ( i = 1; i <= n; i++)
    {
        printf("%ld  ",f[i]);
    }
    system("pause");
    return 0;
}
void Fib(long f[],int n)
{
    int i;
    f[0]=0;
    f[1]=1;
    for ( i = 2; i <= n; i++)
    {
        f[i]=f[i-1]+f[i-2];
    }

}