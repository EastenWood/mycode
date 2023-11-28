#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int Min(void);
void main(void)
{
    printf("原来至少有%d个",Min());
    system("pause");
}

int Min(void)
{
    int n ;
    float m,x;
    m=5*x+1;
    for(n=1;n<=4;)
    {
        m=m*5.0/4+1;
        n++;
        if (m!=(int)m)
        {
            x++;
            m=5*x+1;
            n=1;
        }
        
    }
    return (int)m;
    
}