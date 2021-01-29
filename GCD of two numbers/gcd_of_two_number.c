#include <stdio.h>

int main()
{
    int a,b;
    printf("ENTER FIRST NUMBER :");
    scanf("%d",&a);

printf("ENTER SECOND NUMBER :");
    scanf("%d",&b);
    
    int i;
    int gcd;
    for( i =1; i <= a && i <= b ; ++i){
    if(a%i == 0 && b%i == 0){
        gcd = i;
       
    }
    }
    printf("%d",gcd);
    
    
    return 0;
}