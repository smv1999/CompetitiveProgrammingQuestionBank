/* Program to check whether the given number is Armstrong or not is discussed here. A number is an Armstrong number when the sum of nth power of 
each digit is equal to the number itself. */

// C program to check whether the given number is Armstrong or not

#include
#include

int main()
{
int number, temp, remainder, result = 0, n = 0 ;

printf(“Enter an integer: “);
scanf(“%d”, &number);

temp = number;

// Finding the number of digits

while (temp != 0)
{
temp /= 10;
++n;
}

temp = number;

// Checking if the number is armstrong

while (temp != 0)
{
remainder = temp%10;
result += pow(remainder, n);
temp /= 10;
}

if(result == number)
printf(“%d is an Armstrong number\n”, number);
else
printf(“%d is not an Armstrong number\n”, number);

return 0;
}



