/*Write program to find the maximum  profit and the solution vector for Knapsack problem. 
  Consider the following constraints for knapsack. N=3,  M=20
  Profit : 25 24 15
  Weight : 18 15 10
*/

#include<stdio.h>
#include<conio.h>
int main(){
	int p[100],w[100],n,m,i,j,b,s,c;
	float Iv[100],a,profit,mul[100];
	printf("Enter knapsack capacity:  ");
	scanf("%d",&m);
	printf("\nEnter number of data items:	");
	scanf("%d",&n);
	//profit array
	printf("\nEnter the values of profit array\n");
	for(i=1;i<=n;i++){
		printf("Enter p[%d] data item: ",i);
		scanf("%d",&p[i]);
	}
	//weight array
	printf("\nEnter the values of weight array\n");
	for(i=1;i<=n;i++){
		printf("Enter w[%d] data item: ",i);
		scanf("%d",&w[i]);
	}
	//I (profit/weight) value array
	for(i=1;i<=n;i++){
		Iv[i]= ((float)p[i]/(float)w[i]);
	}
	//sorting Iv,weight, and profit array
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (Iv[j] < Iv[i]){
				a = Iv[i];
				b = w[i];
				c = p[i];
				Iv[i] = Iv[j];
				w[i] = w[j];
				p[i] = p[j];
				Iv[j] = a;
				w[j] = b;
				p[j]= c;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(m==0){
			mul[i] = 0;
			break;
		}
		else {
			s = m - w[i];
			if (s>0){		
				m = m - w[i];
				mul[i] = 1;
			}
			else{
				mul[i] = ((float)m/w[i]);
				m = m - (w[i] * ((float)m/w[i]));
			}
		}
	}
	for(i=1;i<=n;i++){
		profit += (mul[i] * p[i]);
	}
	printf("\nHence the total profit will be :  %.2f\n",profit);	
	//printing array Iv again
	printf("\nThe solution vector will be \n");
 	for(i=1;i<=n;i++){
		printf("%.2f ",Iv[i]);
	}
 	return 0;
}