#include<stdio.h>
#include<stdlib.h>
#define N 20
unsigned int MyStrlen(char *p)
{
    unsigned int len;
    len=0;
    for (; *p!='\0'; p++)
    {
        len++;
    }
    return len;    
}
int main()
{
    char len[N];
    printf("输入字符串：");
    gets(len);
    printf("长为%d",MyStrlen(len));
    system("pause");
    return 0;
}