#include<stdio.h>
#include<stdlib.h>
#define N 10

void ReadData(int a[], int n);
void PrintData(int a[], int n);
void  Swap(int *x, int *y);

int main()
{
	int  a[N], b[N], i, n;
	printf("Input array size(n<=10):");
	scanf("%d", &n);
	printf("Input array a:");
	ReadData(a,n);					//调用ReadData函数，给a数组输入值
	printf("Input array b:");
	ReadData(b,n);				    //调用ReadData函数，给b数组输入值
	for (i=0; i<n; i++)     
	{
		Swap(&a[i],&b[i]);   //交换两个数组中对应元素的值
	}
	printf("Output array a:");
	PrintData(a,n);					//调用PrintData函数，输出a数组的值
	printf("Output array b:");
	PrintData(b,n);	
    system("pause");				//调用PrintData函数，输出b数组的值
	return 0;
}

//函数功能：输入数组a的n个元素值
void ReadData(int a[], int n) 
{
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
}
void PrintData(int a[], int n) 
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d",a[i]);
	}
	printf("\n");						//输出换行
}
void  Swap(int *x, int *y)
{
	int  temp;
    temp=*x;
    *x=*y;
    *y=temp;
}