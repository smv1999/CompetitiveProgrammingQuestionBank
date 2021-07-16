//Move all zeros to End
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Approach 2
//O(n) O(1)


// i/p: n=5, 0 1 0 3 12
// o/p: 1 3 12 0 0

// Here we replace another loop with count

#include<iostream>
using namespace std;
void moveToEnd(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			//if we get 0 we ignore it
			//and if we get non zero we swap with count which point at 0
			swap(arr[i],arr[count]); 
			count++;				 
									
		}
	}
}

int main()
{
	int n,i;
	cout<<"Enter the number of elements in array\n";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in array\n";
	for(i=0;i<n;i++)
	  cin>>arr[i];
	moveToEnd(arr,n);
	cout<<"Array having zeroes at end\n";
	for(i=0;i<n;i++)
	  cout<<arr[i]<<" ";

}
