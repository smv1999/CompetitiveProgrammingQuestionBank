// Given a square matrix of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space.

#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int matrix[n][n];
     
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
    //rotating the matrix by 90 , anticlockwise        
    // the matrix will have floor(n/2) cycles 
    for(int i=0; i<n/2; i++)
    {
        //parsing through each cycle and rotating
        for(int j=i; j< n-i-1; j++)
        {
            //stored current element in temporary variable temp
            int temp= matrix[i][j];
            
            //shifted right element to top
            matrix[i][j]= matrix[j][n-i-1];
            
            //shifted bottom element to right
            matrix[j][n-i-1]= matrix[n-1-i][n-1-j];
            
            //shifted left element to bottom
            matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
            
            //assign temp to left
            matrix[n-1-j][i]= temp;
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j=0; j<n; j++)
                cout<< matrix[i][j];
        cout<<endl;
    }
    return 0;
}  
