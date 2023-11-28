#include<stdio.h>
#include<stdlib.h>

 int main( )
{
  int i;
  long p=1,sum=0;
  float n;
  printf("please input a n:");
  scanf("%f",&n) ;
  for (i=1;sum<n ; i++)
  {
    p=p*i;
    sum=sum+p;
    
  }
  printf("%ld",i-2);
  system("pause");
  return 0;

}