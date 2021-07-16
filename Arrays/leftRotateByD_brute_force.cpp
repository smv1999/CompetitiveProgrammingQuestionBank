//Left rotate an Array by D
//O(nD) O(1)
//approach 1


//i/p: n=7, 1 2 3 4 5 6 7, k = 3
//o/p: 4 5 6 7 1 2 3

//we simply call left rotate by one for D times

#include<bits/stdc++.h>
using namespace std;

void leftrotatebyone(int arr[],int n)
{
    int temp=arr[0];        //store 0th element in temp
    for(int i=1;i<n;i++)
         {
         	arr[i-1]=arr[i];   //move other element back bye one
		 }
       arr[n-1]=temp;        //insert temp element at end
}

void leftRotateByD(int arr[],int n,int d)
{
	for(int i=0;i<d;i++)
		leftrotatebyone(arr,n);
}

int main()
{
    int n,d;
    cout<<"Enter the number of elements in array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the number of rotations\n";
    cin>>d;
    leftRotateByD(arr,n,d);
    cout<<"Array after "<<d<<" rotation\n";
      for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
