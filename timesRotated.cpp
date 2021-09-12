/*
	Consider an array of distinct numbers sorted in increasing order. 
	The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.
	
	Examples: 
	
	Input : arr[] = {15, 18, 2, 3, 6, 12}
	Output: 2
	Explanation : Initial array must be {2, 3, 6, 12, 15, 18}. 
	Finding the index of minimum element in the array will tell us, how many times array had been rotated.
	
	Input : arr[] = {7, 9, 11, 12, 5}
	Output: 4
	
	Input: arr[] = {7, 9, 11, 12, 15};
	Output: 0
*/
#include<bits/stdc++.h>
using namespace std;

int findMin(int a[], int l, int h)
{
	while(h >= l)
	{
		int mid = l + (h-l)/2;
		if(a[mid-1] > a[mid] && a[mid] < a[mid+1])
			return mid;
			
		else if(a[l] < a[mid])
			l = mid+1;
		else if(a[mid] < a[h])
			h = mid-1;
	}
	return -1;
}

int main()
{
	int a[] = { 15, 18, 2, 3, 6, 12 };
	int n = sizeof(a)/sizeof(int);
	cout << findMin(a, 0, n-1);
}
