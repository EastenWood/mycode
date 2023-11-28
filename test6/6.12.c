#include<stdio.h>
#include<stdlib.h>

int main( )
{
  float n,sum=0;
  printf("input a number:");
  scanf("%f",&n);
  while (n>0)
  {
    sum=sum+n;
    printf("input a number:");
    scanf("%f",&n);
  }
  printf("%f",sum);
  system("pause");
  return 0;
  
}