#include<stdio.h>
#include<stdlib.h>
#define N 20
#define M 2
int MyStrcmp(char s[],char t[])
{
    int i;
    for ( i = 0; s[i]==t[i]; i++)
    {
        if(s[i]=='\0') return 0;
    }
    return s[i]-t[i];
    
}
int main()
{
    int i;
    char len[M][N];
    printf("请输入两个字符串:\n");
    for ( i = 0; i < M; i++)
    {
        gets(len[i]);
    }
    printf("%d",MyStrcmp(&len[0][0],&len[1][0]));
    system("pause");
    return 0;
    
}