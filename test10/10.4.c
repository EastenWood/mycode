#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 80
int letter(char a[]);
int main(void)
{
    char a[N];
    printf("Input a string:\n");
    gets(a);
    printf("共计%d个单词",letter(a));
    system("pause");
    return 0;
    
}
int letter(char a[])
{
    int i,letter;
    letter=(a[0]=='\0')?0:1;//首字母是不是空格
    for ( i = 0; a[i]!='\0'; i++)
    {
        if(a[i]!=' '&&a[i-1]==' ')//本身不是空格，前者为空格
        {
            letter++;
        }
    }
    return letter;
    
}