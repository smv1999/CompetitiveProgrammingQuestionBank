#include<stdio.h>
int gcd(int a,int b) // to calculate the GCD of two numbers
{
    int r;
    do
    {
        r=a%b;
        a=b;
        b=r;
    } while (b!=0);

    return a;
}
int main(int argc, char const *argv[]) // DRIVER function
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("The GCD of %d and %d is: %d",a,b,gcd(a,b));
    return 0;
}
