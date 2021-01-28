// C program to check whether the given number is a perfect number or not

#include<stdio.h>

int main()
{
int i, num, sum = 0;

printf("\nEnter a number : ");
scanf("%d", &num);

for(i=1; i<num; i++)
{
if(num%i == 0)
{
sum += i;
}
}

if(sum == num)
{
printf("\n%d is a Perfect Number\n", num);
}
else
{
printf("\n%d is not a Perfect Number\n", num);
}

return 0;
}

/* Input- Enter a number:35 
Output- 35 is not a Perfect Number
*/

