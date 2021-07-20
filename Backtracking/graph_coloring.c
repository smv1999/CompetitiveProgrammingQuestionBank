/*Write a program to implement the graph coloring problem with  m=3 using back tracking method. Consider the  
following adjacency matrix for the graph. 
           1 2 3 4
        1  0 1 1 1
        2  1 0 1 0
        3  1 1 0 1
        4  1 0 1 0
*/
#include<stdio.h>
#define v 4
void printsol(int color[]) {
	int i;
	printf("The assigned colors are: ");
	for (i = 0; i < v; i++)
		printf(" %d ", color[i]);
	printf("\n");
}

int isSafe(int adj[v][v], int color[]) {
	int i,j;
	for (i = 0; i < v; i++)
		for (j = i + 1; j < v; j++)
			if (adj[i][j] && color[j] == color[i]){
				return 1;
			}
	return 0;
}
int graphcolor(int adj[v][v], int m, int i, int color[v]){
	int j;
	if (i == v){ // If we got all the vertex colored we check if it is safe
		if (isSafe(adj, color) == 0) {
			// If yes we print solution and return 0
			printsol(color);
			return 0;
		} else{
			return 1;
		}
	}
	//Recursively colors all the vertex
	for(j=1;j<=m;j++){
		color[i] = j;
		if (graphcolor(adj,m,i+1,color) == 0){ // Since we returned 0 i.e we got one solution we return the func
			return 0;
		}
		color[i] = 0; // If we didn't get safe solu (i.e return value is 1) we start again
	}
	return 1;
}

int main(){
	int i,j,m;
	printf("Enter the number of colors [m] : ");
	scanf("%d",&m);
	int adj[v][v];
	printf("\nEnter values of the Adjacency Matrix: \n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("\nEnter the value of adj[%d][%d]: ",i,j);
			scanf("%d",&adj[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	printf("Adjacency Matrix: \n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	printf("\nThe value of m is: %d \nThe value of v is: %d\n",m,v);
	
	int color[v]; //Keeps record of the color, each vertex is colored with
    for (i = 0; i < v; i++){
        color[i] = 0; //first set all the nodes color as 0
    }
 
    if (graphcolor(adj, m, 0, color) == 1){
    	printf("Solution does not exist");
	}
	return 0;
}

