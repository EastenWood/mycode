#include<stdio.h>
#include<stdlib.h>
#define N 20
#define M 2
int MyStrcmp(char *p1,char *p2)
{
    for ( ;*p1==*p2;p1++,p2++)
    {
        if (*p1=='\0')  return 0;
    }
    return (*p1-*p2);
    
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
    printf("%d",MyStrcmp(&len[0][M],&len[1][M]));
    system("pause");
    return 0;
    
}