#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() 
{ 
    int a[40][40]= {0}; 
    int i,j,k;
    printf("请输入你想要表示的杨辉三角形的大小k:\n");
    scanf("%d",&k);
    for(i=1; i<=k;i++)  
    { 
        a[i][1]=1;    //杨辉三角形的首元素为1
        a[i][i]=1;   //杨辉三角形的末元素为1
        if(i>=2) 
        { 
            for(j=1; j<=i; j++)   //杨辉三角形的首元素为1
            { 
                a[i][j]=a[i-1][j-1]+a[i-1][j];   
            } 
        } 
    } 
    printf("你想要表示的杨辉三角形为:\n");
    for(i=1; i<=k;i++)     //杨辉三角形的首元素为1 
    { 
        for(j=1; j<=i; j++)   //杨辉三角形的首元素为1
        { 
            printf("%d ",a[i][j]); 
        } 
        printf("\n");
    } 
    system("pause");
    return 0; 
}