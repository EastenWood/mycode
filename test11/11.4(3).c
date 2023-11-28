#include<stdlib.h>
#include<stdio.h>
#define N 10
void Transpore(int *a,int n);
void swap(int *p,int *q);
int main(void)
{
    int n,a[N][N],i,j;
    int *p;
    p=*a;
    printf("输入需要的nxn阶矩阵的转置矩阵(n<=10):\n");
    scanf("%d",&n);
    printf("输入n阶矩阵:\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&p[i*n+j]);
        }   
    }
    Transpore(*a,n);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d\t",p[i*n+j]);
        }
        printf("\n");   
    }
    system("pause");
    return 0;
}
void Transpore(int *a,int n)
{
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = i; j < n; j++)
        {
            swap(&a[i*n+j],&a[j*n+i]);
        }   
    }
    
}
void swap(int *p,int *q)//转置矩阵
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}