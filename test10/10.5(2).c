#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define N 80
void Pass(char *pa);
int main(void)
{
    char a[N];
    printf("Input a string:\n");
    gets(a);
    Pass(a);
    printf("删除后的字符串为：\n");
    puts(a);
    system("pause");
    return 0;
}
void Pass(char *pa)
{
    char c;
    printf("请输入你要删除的某字符：\n");
    scanf("%c",&c);
    for (;*pa!='\0';pa++)
    {
        if(*pa==c)
        {
            *pa=' ';
        }
    } 
}