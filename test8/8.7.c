#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 40
int main(void)
{
    int i,j,grade,feedback[N],count[11]={0};
    printf("Input the feedbacks of 40 students:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&feedback[i]);
    }
    for ( i = 0; i < N; i++)
    {
        switch (feedback[i])
        {
        case 1:
            count[1]++;
            break;
        case 2:
            count[2]++;
            break;
        case 3:
            count[3]++;
            break;
        case 4:
            count[4]++;
            break;
        case 5:
            count[5]++;
            break;
        case 6:
            count[6]++;
            break;
        case 7:
            count[7]++;
            break;
        case 8:
            count[8]++;
            break;
        case 9:
            count[9]++;
            break;
        case 10:
            count[10]++;
            break;
        }
    }
    printf("Grade\tCount\tHistogram\n");
    for ( grade=1; grade<=10; grade++)
    {        
        printf("%5d\t%5d\t",grade,count[grade]);
        for ( j = 0; j < count[grade]; j++)
        {
            printf("%c",'*');
        }
        printf("\n");   
    }
    system("pause");
    return 0;
    
    
}