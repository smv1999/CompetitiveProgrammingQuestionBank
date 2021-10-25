//Write a program to find the transpose of a square matrix of size N*N. The transpose of a matrix is obtained by changing rows to columns and columns to rows.

#include <bits/stdc++.h> 
using namespace std; 

//Function to find transpose of a matrix.
void transpose(vector<vector<int> > &matrix, int n)
{ 
    for(int i=0; i< n; i++)
    {
            
    for(int j=i; j< n; j++)
        {
           swap(matrix[i][j], matrix[j][i]);
        }  
    }
}
    
int main() 
{

int t;
cin>>t;
    
while(t--) 
{
    int n;
    cin>>n;
    vector<vector<int> > matrix(n); 

    for(int i=0; i<n; i++)
    {
        matrix[i].assign(n, 0);
        for( int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }

    transpose(matrix,n);
    for (int i = 0; i < n; ++i)
       { 
           for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
        }
}
return 0;

}  
