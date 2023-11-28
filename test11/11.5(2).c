#include<stdlib.h>
#include<stdio.h>
#define N 10
#define M 10
void Transpose(int (*a)[N],int (*at)[M],int m,int n);
int main(void)
{
    int m,n,a[M][N],at[N][M],i,j;
    printf("输入需要的mxn阶矩阵的转置矩阵(m,n<=10) m,n:\n");
    scanf("%d,%d",&m,&n);
    printf("输入mxn阶矩阵:\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }   
    }
    Transpose(a,at,m,n);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("%d\t",at[i][j]);
        }
        printf("\n");   
    }
    system("pause");
    return 0;
}
void Transpose(int (*a)[N],int (*at)[M],int m,int n)
{
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            *(*(at+j)+i)=*(*(a+i)+j);
        }   
    }
    
}