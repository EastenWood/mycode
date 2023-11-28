#include<stdio.h>
#include<stdlib.h>
void  MonthDay(int year, int yearDay, int *pMonth, int *pDay);

int main()
{
	int    year, month, day, yearDay;
	printf("Please enter year, yearDay:");
    scanf("%d,%d", &year, &yearDay);
    MonthDay(year,yearDay,&month,&day);   		
    printf("month = %d, day = %d\n", month, day);
    system("pause");
    return 0;
}


void  MonthDay(int year, int yearDay, int *pMonth, int *pDay)
{
	int  i, leap;
	int dayTab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	
	leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	
	for (i=1; yearDay>dayTab[leap][i]; i++)
	{
		yearDay = yearDay - dayTab[leap][i];    
	}
	
	*pMonth=i;       
	*pDay=yearDay;      
}
