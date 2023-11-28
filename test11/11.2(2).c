#include<stdlib.h>
#include<stdio.h>
void InputArray(int *pa,int n);
void OutputArray(int *pa,int n);
int main(void)
{
    int a[5];
    printf("Input five numbers:");
    InputArray(a,5);
    OutputArray(a,5);
    system("pause");
    return 0;
}
void InputArray(int *pa,int n)
{
    int *p=pa;
    for ( ; p < pa+n; p++)
    {
        scanf("%d",p);
    }
    
}
void OutputArray(int *pa,int n)
{
    int *p=pa;
    for ( ; p < pa+n; p++)
    {
        printf("%4d",*p);
    }
     
}