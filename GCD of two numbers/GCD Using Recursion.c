#include <stdio.h>
#include <conio.h>

int FindGCD(int n,int m)
{
    if(m==0)
        return n;
    return FindGCD(m,n%m);
}

int main()
{
    int n,m,gcd;
    printf("Enter first number: ");
    scanf("%d",&n);
    printf("Enter second number: ");
    scanf("%d",&m);
    gcd=FindGCD(n,m);
    printf("GCD of %d and %d is: %d",n,m,gcd);
    return 0;
}
