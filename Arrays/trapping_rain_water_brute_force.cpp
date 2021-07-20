// Trapping Rain Water
//Approach 1
// O(n^2) O(1)

//i/p: 3 0 1 2 5
//o/p: 6

//Brute force approach

#include<bits/stdc++.h>
using namespace std;
int traprain(int arr[],int n)
{ // To store the maximum water
    // that can be stored
    int res = 0;

// i/p: 3 0 1 2 5
//o/p: 6

    // For every element of the array
    for (int i = 1; i < n-1; i++) {

        // Find the maximum element on its left from o th to i th value
        int left = arr[i];
        for (int j=0; j<i; j++)                 //o(n^2)
           left = max(left, arr[j]);

        // Find the maximum element on its right from j th th value to end
        int right = arr[i];
        for (int j=i+1; j<n; j++)
           right = max(right, arr[j]);

       // Update the maximum water
       res = res + (min(left, right) - arr[i]); // 3 + 2 + 1
    }

    return res;
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in  the array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Total trapped water is "<<traprain(arr,n);
    return 0;
}
