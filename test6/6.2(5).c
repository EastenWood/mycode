#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int n=1,count=1;
    double x ;
    double sum,term;
    printf("Input x:");
    scanf("%lf",&x);
    sum=x;
    term=x;
    do
    {
        term=term*(-1)*x*x/((n+1)*(n+2));
        sum=sum+term;
        n=n+2;
        count=count+1;
    } while (fabs(term)>=0.00001);
    printf("sin(%f)=%f,count=%d\n",x,sum,count);
    system("pause");
    return 0;
    

}