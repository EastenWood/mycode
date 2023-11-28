#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct person
{
    char name[20];
    int count;
}candidate[3]={"zhang",0,"li",0,"wang",0};
int main(void)
{
    int i,j,n,wrong=0,flag;
    char candidate_name[20];
    for ( i = 0; i < 10; i++)
    {
        printf("请输入候选人名字:\n");
        scanf("%s",candidate_name);
        strlwr(candidate_name);
        flag=1;
        for ( j = 0; j < 3; j++)
        {
            if (strcmp(candidate_name,candidate[j].name)==0)
            {
                candidate[j].count++;
                flag=0;
            }
        }
        if(flag)
        {
            wrong++;
        }    
    }
    for ( i = 0; i < 3; i++)
    {
        printf("%5s:得票为%d\n",candidate[i].name,candidate[i].count);
    }
    printf("弃票为%d\n",wrong);
    system("pause");
    return 0;  
}
