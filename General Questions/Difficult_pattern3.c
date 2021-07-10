/* WAP to generate the given pattern
123
12345
1234567
123456789
*/
#include<stdio.h>
int main(){
    int i,j,k;
    for(i=1;i<=4;i++){
        for(j=1;j<=i;j++)
            printf("%d",j);
        for(k=1;k<=j;k++)
            printf("%d",i+k);
        printf("\n");
    }
}
