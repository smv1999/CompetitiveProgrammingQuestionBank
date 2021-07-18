//Left rotate an Array by D - extra space

//A left rotation operation on an array of size n
//shifts each of the array's elements 1 unit to the left.
//Given an integer d, rotate the array that many steps left and return the result.

//O(n) O(d)
//approach 2

//i/p : n=5, 1 2 3 4 5, d=2
//o/p : 3 4 5 1 2

//1st we copy D elements in arr[D]
//2nd we move arr[i] one by one back
//3rd insert arr[D] in arr[i] [n-d+i]


#include<bits/stdc++.h>
using namespace std;

int leftRotateByD(int arr[],int n,int d)
{
    int temp[d];
    for(int i=0;i<d;i++) //O(D)
        temp[i]=arr[i];

    for(int i=d;i<n;i++) //O(n-D)
        arr[i-d]=arr[i]; //i-d will place element at 0th

    for(int i=0;i<d;i++) //O(D)
        arr[n-d+i]=temp[i]; //5-3+1 =3, 4 ,5

        // so here we have, d + n - d + d = n + d = n (d is negligible)
}
int main()
{
    int n,d;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the number of rotations\n";
    cin>>d;
    leftRotateByD(arr,n,d);
      for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}


