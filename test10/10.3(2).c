#include<stdio.h>
#include<stdlib.h>
#define N 20
unsigned int MyStrlen(char s[])
{
    char *p=s;
    while (*p!='\0')
    {
        p++;
    }
    return (p-s);
    
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