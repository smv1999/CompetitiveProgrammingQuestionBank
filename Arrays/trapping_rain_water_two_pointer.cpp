// Trapping Rain Water
//Approach 3 (2 pointer approach)
// O(n) O(1)

//i/p: 3 0 1 2 5
//o/p: 6

/*
We take 2 pointer left right
and increment left and decrement right
till we meet at a point
*/


#include<bits/stdc++.h>
using namespace std;
int getwater(int arr[],int n)
{
 	int left=0,right=n-1;
 	int res=0;
 	int leftmax=0,rightmax=0;

 	// i/p: 7 1 4 0 2 8 6 3 5
	//o/p: 23

 	while(left<=right)
 	{
 		//left side

 		if(arr[left]<=arr[right])
		 {
		 	if(arr[left]>=leftmax)
		 		leftmax=arr[left];
		 	else
		 		res+=leftmax-arr[left]; // (7-1)=6 + (7-4)=3 + (7-0)=7 + (7-2)=5 ==> 21

		 	left++; //increment
		 }
		 //right side
		 	else
		 	{
		 		if(arr[right]>=rightmax)
		 		    rightmax=arr[right]; //5
		 		else
		 		    res+=rightmax-arr[right]; //(5-3)=2 ==> 2
		 		right--; //decrement
		    }
	}
	return res;
}
int main()
{
	int n;
    cout<<"Enter the number of elements in the array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in  the array\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Total trapped water is "<<getwater(arr,n);
    return 0;
}
