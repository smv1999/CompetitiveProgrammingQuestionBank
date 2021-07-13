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

// Time Complexity --> O(n)

