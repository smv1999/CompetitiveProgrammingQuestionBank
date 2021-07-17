//Left rotate an Array by D - brute force

//A left rotation operation on an array of size n
//shifts each of the array's elements 1 unit to the left.
//Given an integer d, rotate the array that many steps left and return the result.

//O(nD) O(1)
//approach 1

//we simply call left rotate by one for D times

//i/p : n=5, 1 2 3 4 5, d=2
//o/p : 3 4 5 1 2

#include<bits/stdc++.h>
using namespace std;

void leftrotatebyone(int arr[],int n)
{
     //store 0th element in temp
    int temp=arr[0];
    for(int i=1;i<n;i++)
         {
             //move other element back bye one
         	arr[i-1]=arr[i];
		 }
         //insert temp element at end
       arr[n-1]=temp;
}

void leftRotateByD(int arr[],int n,int d)
{
	for(int i=0;i<d;i++)
		leftrotatebyone(arr,n);
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
