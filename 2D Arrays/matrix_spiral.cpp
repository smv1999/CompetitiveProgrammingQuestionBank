/*
Spiral Matrix

*/
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,i,row,col,end_row,end_col,count=0;
    cin>>n;
    row=col=end_row=end_col=0;
    int mat[n][n];
    for(i=0;i<n/2;i++)
    {
        row=col=i;
        end_col= n-i-1;
        while (col < end_col)
        {
            mat[row][col] = ++count;
            col++;
        }
        end_row = n-i-1;
        while (row < end_row)
        {
            mat[row][col]= ++count;
            row++;
        }
        end_col = i;
        while (col > end_col)
        {
            mat[row][col]=++count;
            col--;
        }
        end_row = i;
        while (row > end_row)
        {
            mat[row][col]=++count;
            row--;
        }
    }
    if(n%2==1)
    mat[n/2][n/2]= n*n;
     for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
