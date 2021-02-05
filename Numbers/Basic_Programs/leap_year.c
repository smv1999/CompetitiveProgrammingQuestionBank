/* Write a c program, to check whether the given year is a leap year or not. A leap year is a calendar year containing one additional day (Feb 29th) 
added to keep the calendar year synchronized with the astronomical year.*/

#include <stdio.h>

int main()
{
    int year;
    printf("Enter a year: ");
    scanf("% d", &year);
    printf("\n");
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                printf("% d is a leap year", year);
            else
                printf("% d is not a leap year", year);
        }
        else
            printf("% d is a leap year", year);
    }
    else
        printf("% d is not a leap year", year);
    printf("\n");
    return 0;
}

/* Output
Input- Enter a year:2004 Output- 2004 is a leap year
*/
