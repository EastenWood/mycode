#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define N 80
void Insert(char a[]);
int main(void)
{
    char a[N];
    printf("Input a string:\n");
    gets(a);
    Insert(a);
    printf("插入空格后的字符串为：\n");
    puts(a);
    system("pause");
    return 0;
}
void Insert(char a[])
{
    int i,j;
    char b[N];
    strcpy(b,a);
    for ( i = 0,j=0; b[i]!='\0'; i++,j++)
    {
        a[j]=b[i];
        j++;
        a[j]=' ';
    }
    a[j]='\0';
}
