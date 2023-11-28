#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
    int i;
    srand(time(NULL));
    int a,b,c,count=1,right=0;    
    do
    {
        a=rand()%10+1;
        b=rand()%10+1;
        printf("%d*%d=? 请输入正确答案：\n",a,b);
        scanf("%d",&c);
        if(a*b==c)
        {
            printf("Right!\n");
            right+=1;
        }
        else
        {
            printf("Erong!\n");
        }        
        count+=1;
    } while (count<=10);
    printf("正确率为%d%c\n",right*10,'%');        
    system("pause");
    return 0;
}

