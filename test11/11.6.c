#include<stdlib.h>
#include<stdio.h>
#define N 10
#define M 10
void InputArray(int *p,int m,int n);
int FindMax(int *p,int m,int n,int *pRow,int *pCol);
int main(void)
{
    int a[M][N],m,n,Row,Col,max;
    printf("输入一个m行n列的二维数组,输入m,n:\n");
    scanf("%d,%d",&m,&n);
    printf("输入mxn阶矩阵:\n");
    InputArray(*a,m,n);
    max=FindMax(*a,m,n,&Row,&Col);
    printf("max=%d,Row=%d,Col=%d",max,Row,Col);
    system("pause");
    return 0;
        
}
void InputArray(int *p,int m,int n)
{
    int i,j;
    for ( i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&p[i*n+j]);
        } 
    }  
}
int FindMax(int *p,int m,int n,int *pRow,int *pCol)
{
    int i,j, max=p[0];
    *pRow=0;
    *pCol=0;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (p[i*n+j]>max)
            {
                max=p[i*n+j];
                *pRow=i;
                *pCol=j;
            }
            
        }
        
    }
    return max;
    
}