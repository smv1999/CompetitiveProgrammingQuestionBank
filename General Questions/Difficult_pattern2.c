#include<stdio.h>
#include<conio.h>
int main(){
    int i,j,k=10,a=30,l,m,t=5;
    for(i=1;i<=5;i++){
        for(j=i-1;j>=1;j--)
            printf("\t");
        for(l=5;l>=i;l--){
            printf("%d\t",k);
            k += 10;
        }
        for(m=a-t+1;m<=a;m++){
            if(m==a)
                printf("%d",m);
            else
                printf("%d0",m);
        }
        a -= t;
        t -= 1;
        printf("\n");
    }
}
/*
Output:
10      20      30      40      50      26027028029030
        60      70      80      90      22023024025
                100     110     120     19020021
                        130     140     17018
                                150     16

*/
