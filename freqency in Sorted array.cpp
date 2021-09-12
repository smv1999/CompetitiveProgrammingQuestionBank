/*
	Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. 
	Expected time complexity is O(Logn) 
	
	Examples: 

	  Input: arr[] = {1, 2, 2, 2, 2, 3},   x = 2
	  Output: 4 // x (or 2) occurs 4 times in arr[]
	
	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
	  Output: 1 
	
	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 1
	  Output: 2 
	
	  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 4
	  Output: -1 // 4 doesn't occur in arr[] 
*/

#include<bits/stdc++.h>
using namespace std;

int first(int a[], int l, int h, int x)
{
	int res = -1;
	while(h >= l)
	{
		int mid = l + (h-l)/2;
         
        if(a[mid] > x)
            h = mid - 1;
        else if(a[mid] < x)
            l = mid + 1;
        else
		{
            res = mid;
            h = mid-1;
        }
	}
	return res;
}

int last(int a[], int l, int h, int x, int size)
{
	int res = -1;
	while(h >= l)
	{
		int mid = l + (h-l)/2;
         
        if (a[mid] > x)
            h = mid - 1;
        else if (a[mid] < x)
            l = mid + 1;
        else
        {
            res = mid;
            l = mid + 1;
        }
	}
	return res;
}

int main()
{
	int a[] = { 1, 2, 2, 2, 2, 3 };
	int n = sizeof(a)/sizeof(int);
	int x = 2;
	int start = first(a, 0, n-1, x);
	int end = last(a, 0, n-1, x, n);
	cout << end - start + 1;
}
