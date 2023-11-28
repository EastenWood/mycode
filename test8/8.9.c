#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10
void InputMatrix(int a[N][N],int n);
int AddDiagonal(int a[N][N],int n);
int main(void)
{
    int a[N][N],n,sum;
    printf("Input n:");
    scanf("%d",&n);
    InputMatrix(a,n);
    sum=AddDiagonal(a,n);
    printf("sum=%d\n",sum);
    system("pause");
    return 0;
}
void InputMatrix(int a[N][N],int n)
{
    int i,j;
    printf("Input %d*%d matrix:\n",n,n);
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
}
int AddDiagonal(int a[N][N],int n)
{
    int i,j,sum=0;
    for ( i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j || i+j == n-1)
            {
                sum=sum+a[i][j];
            }      
        }
    }
    return sum;
}