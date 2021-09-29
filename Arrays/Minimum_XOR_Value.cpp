/*
Given an integer array A of N integers, find the pair of integers 
in the array which have minimum XOR value. Report the minimum XOR value. 
Explanation: According to the problem, we are given the size of the array 
and the numbers present in it. So we have to find two such numbers that are 
the elements of the array and their xor is the minimum in value in comparison 
to all the possible pairs of the array.
*/

#include<bits/stdc++.h>
using namespace std;

void Min_xor(int*A,int n)
{
    //ele1 and ele2 will store the value of the elements that gives minimum xor value
    int ele1,ele2;
    //ans will store the minimum xor value
    int ans=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        //x will store xor value for each possible pair of elements of array
        int x=A[i]^A[i+1];
        if(x<ans)
        {
            ans=x;
            ele1=A[i];
            ele2=A[i+1];
        } 
    }
    //printing the output
    cout<<"The Minimum xor value is : "<<ans<<endl;
    cout<<"The corresponding elements are : "<<ele1<<" and "<<ele2;
}

int main() {
    //n will store the size of the array
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array : ";
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    //sort() will sort the array in increasing order
    sort(A,A+n);
    //calling the function
    Min_xor(A,n);
    return 0;
}

/*
INPUT:
Enter the size of array : 4
Enter the array : 0 2 5 7
OUTPUT:
The Minimum xor value is : 2
The corresponding elements are : 0 and 2

Time Complexity : O(nlogn)
Space Complexity : O(1)
*/