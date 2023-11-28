#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
int main()
{
    int i;
    srand(time(NULL));
    for(i=1;;i++)
    {
        int a,b,c,flag;
        a=rand()%10+1;
        b=rand()%10+1;
        do
        {
            printf("%d*%d=? 请输入正确答案：\n",a,b);
            scanf("%d",&c);
            if(a*b==c)
            {
                printf("Right!\n");
                flag=1;
            }
            else
            {
                int count=1;
                do
                {
                    printf("Wrong!Please try again.\n");
                    scanf("%d",&c);
                    count=count+1;
                } while (c!=a*b&&count<3);
                goto end;   
            }
        } while (flag!=1);        
    }
    end:
    printf("Wrong!You have tried three times!Test over!");
    system("pause");
    return 0;
}
