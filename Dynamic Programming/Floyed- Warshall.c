/* Write a program to implement all pair of Shortest path for
a given graph (Floyed- Warshall Algorithm) using
Dynamic Programing approach. 

            1  2  3  4  5
        __  _  _  _  _  _
        |
    1   |   0  3  8  X  -4
    2   |   X  0  X  1   7
    3   |   X  4  0  X   X      ==> D[0]
    4   |   2  X  -5 0   X
    5   |   X  X  X  6   0


            1  2  3  4  5
        __  _  _  _  _  _
        |
    1   |   X  1  1  X   1
    2   |   X  X  X  2   2
    3   |   X  3  X  3   X      ==> pi[0]
    4   |   X  X  4  X   X
    5   |   X  X  X  5   X

*/

#include<stdio.h>
#define infinity 1000000
int D[100][100],PI[100][100],i,j,n,k;
int main(){
	printf("Enter no. of nodes:	");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if (i==j){
				D[i][j] = 0;
			}
			if (i!=j){			
				printf("Enter cost of D[%d][%d]	", i,j);
				scanf("%d", &D[i][j]);
			}
		}
		printf("\n");
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Enter value of PI[%d][%d]	", i,j);
			scanf("%d", &PI[i][j]);	
		}
		printf("\n");
	}
	printf("\n\nMatrix D\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",D[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatrix PI\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",PI[i][j]);
		}
		printf("\n");
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(D[i][j] > (D[i][k] + D[k][j])){
					D[i][j] = (D[i][k] + D[k][j]);
					PI[i][j] = PI[k][j];
				}
			}
		}
	}
	printf("\n\nFinal D Matrix\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",D[i][j]);
		}
		printf("\n");
	}
	printf("\n\nFinal PI Matrix\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",PI[i][j]);
		}
		printf("\n");
	}
}
