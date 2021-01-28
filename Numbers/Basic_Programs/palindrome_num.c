/* Palindrome or not using iterative approach */

#include <stdio.h>
int main()
{
int n, reverse = 0, remainder, number;

printf("Enter an integer: ");
scanf("%d", &n);

number = n;

while( n!=0 )
{
remainder = n%10;
reverse = reverse*10 + remainder;
n /= 10;
}

if (number == reverse)
printf("\n%d is a palindrome\n", number);
else
printf("\n%d is not a palindrome\n", number);

return 0;
}

/* Input- Enter an integer:1234321 
Output- 1234321 is a palindrome
*/