//Move all zeros to End
//Approach 1
//O(n^2) O(1)

// i/p: n=5  
// 		0 1 0 3 12
// o/p: 1 3 12 0 0

#include<iostream>
using namespace std;
void moveToEnd(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)				//so we 1st find is there any 0 present
			{
				for(int j=i+1;j<n;j++)
					if(arr[j]!=0)		//if non zero then swap with ith 0
					{
							swap(arr[i],arr[j]); //and swap both
							break;
					}
			}
	}
}
/*
5
0 0 1 2 3
1 0 0 2 3
1 2 0 0 3
1 2 3 0 0
*/

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
