// Problem Description:
//   Here, we have an array arr[]. The array contains n integer values.
//   We have to find the maximum value and minimum value out of all values of the array.

//   Let’s take an example to understand the problem

//   Input  : n = 5
//            a[n] = { 10, 20, 30, 40, 50}

//   Output :  Maximum element of array is 50
//             Minimum element of array is 10

// Explanation : 
//
// There can be multiple solution for this problem. 
// One solution is to directly compare the elements of  array. This can be done by using two different approaches :
//      1.Iterative approach  
//      2.Recursive approach 

// Here we are using iterative approach to solve this problem. 
// initially we will set a[0] as min/max. Then we iterate over each elemnts using loop and compare it with max/min element of array. 

// Time Complexity  : O(n)
// Space Complexity : O(1)

#include <iostream>
using namespace std;

int getmax( int a[], int n){
    int max = a[0];
    for( int i=1; i<n; i++)
    {
        if( a[i] > max )
           max = a[i];
    }

    return max;
}

int getmin( int a[], int n){
    int min = a[0];
    for( int i=1; i<n; i++)
    {
        if( a[i] < min )
           min = a[i];
    }

    return min;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   for( int i=0; i<n; i++)
   {
       cin>>a[i];
   }
   int max = getmax( a, n);
   int min = getmin( a, n);
   cout<<"Maximum element of array is :"<<max<<endl;
   cout<<"Minimum element of array is :"<<min<<endl;

}


