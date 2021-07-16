//Move all zeros to End
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Approach 1
//O(n^2) O(1)

// i/p: n=5, 0 1 0 3 12
// o/p: 1 3 12 0 0

/*
Brute froce approach
n=5
traversals :
0 0 1 2 3
1 0 0 2 3
1 2 0 0 3
1 2 3 0 0
*/

#include<iostream>
using namespace std;
void moveToEnd(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
	  //We 1st find is there any 0 present
	  if(arr[i]==0)				
	   {
	   for(int j=i+1;j<n;j++){
		//if non zero then swap with ith 0
		if(arr[j]!=0)		
		{
	         //swap both
		 swap(arr[i],arr[j]); 
		 break;
		}
	     }	   
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
