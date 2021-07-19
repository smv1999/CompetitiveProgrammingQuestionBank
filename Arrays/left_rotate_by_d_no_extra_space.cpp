//Left rotate an Array by D - no extra space

//A left rotation operation on an array of size n
//shifts each of the array's elements 1 unit to the left.
//Given an integer d, rotate the array that many steps left and return the result.


//O(n) O(1)
//approach 3

//i/p : n=5, 1 2 3 4 5, d=2
//o/p : 3 4 5 1 2

// 1st we reverse D
//then reverse D to N
// and finally we reverse whole the array
// so we get as desire output


#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int low,int high)
{
    while(low<high)
    {
        swap(arr[low],arr[high]); //reverse till low and high overlap
        low++;
        high--;
    }
}

void leftRotateByD(int arr[],int n,int d)
{                            //e.g.n=5, 1 2 3 4 5 d=2

        reverse(arr,0,d-1); //call to reverse start to D th element  2 1 3 4 5

        reverse(arr,d,n-1); //call to reverse for D th to N-1 number 2 1 5 4 3

        reverse(arr,0,n-1); //call to reverse for 0th to N-1 number  3 4 5 1 2

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

