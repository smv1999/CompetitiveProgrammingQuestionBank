#include <stdio.h>

void is_leap_year(int year)
{
if(year%4 == 0)
{
if( year%100 == 0)
{
if ( year%400 == 0)
printf(“%d is a leap year”, year);
else
printf(“%d is not a leap year”, year);
}
else
printf(“%d is a leap year”, year);
}
else
printf(“%d is not a leap year”, year);
printf(“\n”);
}

int main()
{
int year;
printf(“\nEnter a year : “);
scanf(“%d”,&year);
printf(“\n”);
is_leap_year(year);
return 0;
}

/* Output
Input- Enter a year:1998 Output- 1998 is not a leap year
/*
