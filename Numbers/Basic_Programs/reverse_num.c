// C program to reverse a number

#include <stdio.h>
int main()
{
int n, rev = 0, rem;
printf("\nEnter a number : ");
scanf("%d", &n);
printf("\nReversed Number : ");
while(n != 0)
{
rem = n%10;
rev = rev*10 + rem;
n /= 10;
}

printf("%d\n", rev);

return 0;
}