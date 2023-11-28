#include<stdio.h>
#include<stdlib.h>
int  DayofYear(int year, int month, int day);

int main()
{
	int    year, month, day, yearDay;			
	printf("Please enter year, month, day:");
    scanf("%d,%d,%d", &year, &month, &day);
    yearDay=DayofYear(year,month,day);				
    printf("yearDay = %d\n", yearDay);
    system("pause");
    return 0;
}


int  DayofYear(int year, int month, int day)
{
	int  i, leap;
	
	int dayTab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31}};
	

	leap =((year%4==0)&&(year%100!=0))||(year%100==0);
	
	for (i=1; i<month; i++)
	{
		day = day + dayTab[leap][i];
	}
	return day;       
}
