/* Q. Given an integer array ‘arr[]’ of size n, find sum of all sub-arrays of given array. 
   Input : a[] = {1, 2, 3}
   Output: 20

   Explanation: We have to generate all the subarrays using two for loops and then compute their sum.
   subarrays     -->  {1} {12} {123} {2} {23} {3}
   subarrays sum -->  1 + 3 + 6 + 2 + 5 + 3 --> 20

   Time Complexity: O(n^2)
*/

#include <iostream>
using namespace std;
int main()
{
    int n, sum=0, result = 0;
    cin>>n;
    int a[n];
    for( int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    for( int i=0; i<n; i++)
    {
        sum = 0;
        for( int j=i; j<n; j++)
        {
            sum = sum + a[j];
            result = result + sum;
        }
    }

    cout<<"Sum of all Subarrays : "<<result;

    return 0;
}