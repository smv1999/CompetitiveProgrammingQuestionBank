/*
	Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. 
	The task is to find the index of the given element key in the array A.
	
	Example 1:
	
	Input:
	N = 9
	A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
	key = 10
	Output:
	5
	Explanation: 10 is found at index 5.

*/
#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int l, int h, int key)
{
	while(l <= h)
	{
		int m = (l+h)/2;
		if(a[m] == key)
			return m;
		if(a[l] < a[m])
		{
			if(key >= a[l] && key < a[m])
				return binary_search(a, l, m-1, key);
			else
				return binary_search(a, m+1, h, key);
		}
		else
		{
			if(key > a[m] && key <= a[h])
				return binary_search(a, m+1, h, key);
			else
				return binary_search(a, l, m-1, key);
		}
	}
}

int main()
{
	int a[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = sizeof(a)/sizeof(int);
	int key = 10;
	int x = binary_search(a, 0, n-1, key);
	if(x != -1)
		cout << x;		// index
	else
		cout << -1;
}
