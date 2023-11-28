#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
int Operations(int x,char op,int y);//返回四则运算
char OPerchar(void);//输入一个随机符号

int main()
{
    srand(time(NULL));
    int a,b,c,count=1,right=0; 
    char op;  
    for(right=0,count=1;;)
    {
        int right=0,count=1;
        do
        {
            a=rand()%10+1;
            b=rand()%10+1;
            op=OPerchar();
            printf("%d%c%d=?\n",a,op,b);
            scanf("%d",&c);
            if(Operations(a,op,b)==c)
            {
                printf("Right!\n");
                right+=1;
            }
            else
            {
                printf("Wrong!\n");
            }        
            count+=1;
     
        } while (count<=10);
    right=right*10;
    if(right<=75)
        {
            printf("正确率低于75%,重新写10题\n");
            continue;
        }
    else
        {
            printf("正确率为%d%c\n",right,'%'); 
            break;
        }

    }      
    system("pause");
    return 0;
}

int Operations(int x,char op,int y)
{
    switch (op)
    {
    case '+':
        return x+y;
    case '-':
        return x-y;
    case '/':
        return x/y;
    case '*':
        return x*y;
    default:
        printf("Operator error!");
        return 0;
    }
}
char OPerchar(void)
{
    int op;
    op=rand()%4+1;
    switch (op)
    {
    case 1:
    return '+';
    case 2:
    return '-';
    case 3:
    return '*';
    case 4:
    return '/';
    }
    return 0;
}