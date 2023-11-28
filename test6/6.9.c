#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1;
    float term=1.0,sum=1;
    while(term>=0.00001)
    {
        term=term*(1.0/n);
        sum=sum+term;
        n++;

    }
    printf("e=%f",sum);
    printf("累加的项数有%d项",n);
    system("pause");
    return 0;

}
