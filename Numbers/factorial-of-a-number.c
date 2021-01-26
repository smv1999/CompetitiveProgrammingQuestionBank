/* We use two types for finding the factorial of a number using function and recursion */
/* Program to find the factorial of a number using functions*/

#include <stdio.h>
int factorial_of_a_number(int n)
{
int fact = 1, i;
if(n == 0)
return 1;
else
for(i = 1; i <= n; i++)
{
fact = fact * i;
}
return fact;
}
int main()
{
int n;
printf("Enter the number : ");
scanf("%d",&n);
if(n < 0)
printf("Invalid output");
else
printf("Factorial of the number %d is %d" ,n, factorial_of_a_number(n));
return 0;
}

/*Input- Enter the number:5 
Output- Factorial of the number 5 is 120
*/

/*Program to find the factorial of a number using recursion*/

#include <stdio.h>
int factorial_of_a_number(int n)
{
if(n == 0)
return 1;
else
return (n * factorial_of_a_number(n-1));
}
int main()
{
int n;
printf("Enter the number : ");
scanf("%d", &n);
if(n < 0)
printf("Invalid input");
else
printf("Factorial of the number %d is %d", n, factorial_of_a_number(n));
return 0;
}

/*Input- Enter the number:5 
Output- Factorial of the number 5 is 120
*/

