/******************************************************************************

Given an m x n matrix, find all common elements present in all rows in one traversal of matrix.

*******************************************************************************/

//SOLUTION (in C++)

#include <bits/stdc++.h>

using namespace std;
#define M 4
#define N 5


void printCommonElements(int arr[M][N])
{
    int i, j;
    //we'll use a amp to store the count of common numbers in a rows
    unordered_map<int, int> m;
    
    //since, we need to find common elements, it is completely dependent on the first row of the Matrix
    //initially all the 1st row elements count will be 1, even if they contain duplicates
    for(i = 0;i<N;i++)
       m[arr[0][i]] = 1;
       
    //traverse the matrix
    for(i = 1;i<M;i++)
    {
        for(j = 0;j<N;j++)
        {
            
            //for any row, my element's freq should be equal to the previous row's number, 
            //if it is, then there is high chance that it can be common and we;'' increase the count.
            //we are ignoring the elements whose gfreq count is not equal to the row, so it reduces our work
            if(m[arr[i][j]] == i){
                m[arr[i][j]]++;
            }
            
            //if the freq of the element in the row becomes equal to the no. of rows,
            //then it means it is coming in all rows and is the common element.
            if(m[arr[i][j]] == M){ 
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main()
{
    cout<<"Matrix"<<endl;
    int mat[M][N] =
    {
        {1, 2, 3, 1, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 3, 9},
    };
    cout<<"Common eleemnts of each row"<<endl;
    printCommonElements(mat);
    return 0;
}
