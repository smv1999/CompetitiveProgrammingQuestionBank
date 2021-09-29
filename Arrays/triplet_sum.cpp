/******************************************************************************

Given an array arr of size n and an integer X.
Find if there's a triplet in the array which sums up to the given integer X.

*******************************************************************************/

//SOLUTION (in C++)

#include <bits/stdc++.h>

using namespace std;

void findTripletSum(int A[], int n, int X)
{
    sort(A, A+n);   //sort the array, it becomes easy to take the sum.
    int i, j, k, count = 0;
    for(i = 0;i<=n-3;i++)   //i should only run till n-3 as we need three numbers for a triplet.
    {
        j = i+1;
        k = n-1;
        while(j<k)    //two-pointer appraoch is used.
        {
            if(A[i] + A[j] + A[k] < X)   //since the array is sorted, if the sum if less than X, the we need to increment j.
            {
                j++;
            }
            else if(A[i] + A[j] + A[k] > X)  //If the sum is greater than X, we need to decrement k.
            {
                k--;
            }
            else if(A[i] + A[j] + A[k] == X) //If the sum is equal to X we need to increement j and decrement k, so that we may find other combinations of the given sum.
            {
                j++;
                k--;
                count++;
            }
        }
    }
    if(count == 0)
      cout<<"The triplet doesn't exists"<<endl;
    else
      cout<<"The triplet exists"<<endl;
}

int main()
{
    int n, X;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<"Enter the sum you want to find"<<endl;
    cin>>X;
    cout<<"Enter the array elements"<<endl;
    int A[n];
    for(int i = 0;i<n;i++)
    {
        cin>>A[i];
    }
    findTripletSum(A, n, X);
    return 0;
}
