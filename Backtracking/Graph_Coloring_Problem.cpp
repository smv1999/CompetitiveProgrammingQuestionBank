/* C++ implementation of Graph Coloring Problem */
#include <bits/stdc++.h>
using namespace std;

//Function for generating a next color
/*x[1],...,x[k-1] have been assigned integer values 
in the range [1,m] such that adjacent vertices have
distinct integers*/
//A value for x[k] is determined in the range [0,m]
/*x[k] is assigned the next highest numbered color while
maintaining distinctness from the adjacent vertices of vertex k.
If no such color exists, then x[k] is 0.*/

void nextvalue(int x[50],int g[50][50],int k,int n,int m)
{
	int j;
 	while(1)
 	{
   		x[k] = (x[k]+1) % (m+1);    			//next higher color
   		if(x[k] == 0)             				//all colors have been used
      		return;
      		
      	//checking if this color is distinct from adjacent colors	
   		for(j=1; j<=n; j++)         
   		{                          
     		if(g[k][j] != 0 && (x[k] == x[j]))	//if (k,j) is an edge and if adjacent vertices have the same color
        		break; 
   		}
     	if(j == n+1)           //new color found       
       		return;                     
  	}
}

//Finding all m-colorings of a given graph
/*All assignments of 1,2,...,m to the vertices of the graph such that 
adjacent vertices are assigned distinct integers are printed*/
//k is the index of the next vertex to color
//set the array x[] to zero, and then invoke mcoloring(1)
void mcoloring(int x[50],int g[50][50],int k,int n,int m)
{
	int i;
  	do								//loop for generating all legal assignments for x[k]
 	{                         
   		nextvalue(x, g, k,n ,m);    //Assign to x[k] a legal color
		     
   		if(x[k] == 0)             	//No new color possible
     		return; 
   		
		if(k == n)                //Atmost m colors have been used to color the n vertices
   		{
    		for(i=1 ;i<=n; i++)
      			cout<<"V"<<i<<": "<<x[i]<<"\t";     
      		cout<<"\n";
   		}
  		else
		mcoloring(x, g, k+1, n, m); 
		
 	}while(k<n+1); 
}

//Main function
int main()
{
	int n,ne,u,v,i,j,x[50],g[50][50],m;
	 
	cout<<"\nEnter number of vertices: ";
	cin>>n;				//reading number of vertices of the graph from user
	 
	cout<<"\nEnter number of edges: ";
	cin>>ne;			//reading number of edges of the graph from user
  
  	m = n-1;
  	cout<<"\nThe maximum possible colours that can be assigned is "<<m<<endl;
  	
  	//The graph is represented by its boolean adjacency matrix G[1:n,1:n]
  	for(i=0; i<=n; i++)
    	for(j=0; j<=n; j++)
       		g[i][j] = 0;
       
  	for(i=1; i<=ne; i++)
	{
	 	cout<<"\nEnter the first terminal vertex of edge "<<i<<": ";
	 	cin>>u;
	 	
	 	cout<<"\nEnter the second terminal vertex of edge "<<i<<": ";
	 	cin>>v;
	 	
		g[u][v] = 1;
   		g[v][u] = 1;
  	}
   
   	for(i=0; i<=n; i++)
      	x[i] = 0;
   
	cout<<endl<<"The colouring possibilities are:"<<endl;
    mcoloring(x ,g ,1 ,n ,m);
}

/*
Input-

Number of vertices= 4
Number of edges= 4

Adjacency matrix:

	0	1	0	1
	1	0	1	0
	0	1	0	1
	1	0	1	0

Output-

Enter number of vertices: 4

Enter number of edges: 4

The maximum possible colours that can be assigned is 3

Enter the first terminal vertex of edge 1: 1

Enter the second terminal vertex of edge 1: 2

Enter the first terminal vertex of edge 2: 2

Enter the second terminal vertex of edge 2: 3

Enter the first terminal vertex of edge 3: 3

Enter the second terminal vertex of edge 3: 4

Enter the first terminal vertex of edge 4: 1

Enter the second terminal vertex of edge 4: 4

The colouring possibilities are:
V1: 1   V2: 2   V3: 1   V4: 2
V1: 1   V2: 2   V3: 1   V4: 3
V1: 1   V2: 2   V3: 3   V4: 2
V1: 1   V2: 3   V3: 1   V4: 2
V1: 1   V2: 3   V3: 1   V4: 3
V1: 1   V2: 3   V3: 2   V4: 3
V1: 2   V2: 1   V3: 2   V4: 1
V1: 2   V2: 1   V3: 2   V4: 3
V1: 2   V2: 1   V3: 3   V4: 1
V1: 2   V2: 3   V3: 1   V4: 3
V1: 2   V2: 3   V3: 2   V4: 1
V1: 2   V2: 3   V3: 2   V4: 3
V1: 3   V2: 1   V3: 2   V4: 1
V1: 3   V2: 1   V3: 3   V4: 1
V1: 3   V2: 1   V3: 3   V4: 2
V1: 3   V2: 2   V3: 1   V4: 2
V1: 3   V2: 2   V3: 3   V4: 1
V1: 3   V2: 2   V3: 3   V4: 2

Time Complexity: O(m^V)
Space Complexity: O(V)

where V= number of vertices and m= maximum possible colors
*/