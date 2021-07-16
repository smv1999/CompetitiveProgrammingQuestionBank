/* Given two sorted arrays, arr1[] and arr2[], the task is to find the 
median of these sorted arrays different size. */

#include<bits/stdc++.h>
using namespace std;

/* Function to find Median of two Sorted array of different size */
int solve()
{
    /* Input n1 = size of array 1
       Input n2 = size of array 2 */
    int n1,n2;
    cout<<"Accept size of 1st Array : ";
    cin >> n1 ;
    cout<<"Accept size of 2nd Array : ";
    cin>>n2;

    int arr1[n1],arr2[n2];

    /* Input values in array 1 */
    cout<<"Accept the values of 1st Array : ";
    for (int i = 0; i < n1; ++i)
    {
        cin >> arr1[i];
    }

    /* Input values in array 2 */
    cout<<"Accept the values of 2nd Array : ";
    for (int i = 0; i < n2; ++i)
    {
        cin >> arr2[i];
    }

    /* Create a vector */
    vector<int> v;

    /* Push array 1 element in vector */
    for (int i = 0; i < n1; ++i)
    {
        v.push_back(arr1[i]);
    }

    /* Push array 2 element in vector */
    for (int i = 0; i < n2; ++i)
    {
        v.push_back(arr2[i]);
    }

    /* Sort the given vector */
    sort(v.begin(), v.end());
    
    /* Find medina using this formula */
    int mid = v[v.size()/2];
    
    /* Return Calculated median */
    return mid;
}

int main()
{
    int Median = solve();

    cout << "Median is : " << Median <<endl;
    return 0;
}

/*
Test cases :
    
    Input :
      Accept size of 1st Array : 1
      Accept size of 2nd Array : 4
      Accept the values of 1st Array : 900
      Accept the values of 2nd Array : 5 8 10 20

    Output :
      Median is : 10
    
    Time complexity: O(nlogn)
    Space Complexity: O(n)
*/