#include<stdio.h>
int gcd(int num1,int num2)
{
    int factor = 2;
    int gcd = 1;
    
    while(num2>=factor){
            if(num1%factor == 0 && num2%factor == 0){
                    gcd *= factor;
                    num1 = num1/factor;
                    num2 = num2/factor;
            }
            else
                    factor += 1;
    }
    return gcd;
}
int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("The GCD of %d and %d is: %d",a,b,gcd(a,b));
    return 0;
}
