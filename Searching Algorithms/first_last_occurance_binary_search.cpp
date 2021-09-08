/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5. 
 

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

 

Constraints:
1 = N = 107
*/

// Code

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
	int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
	int n = sizeof(arr)/sizeof(int);
	int x = 5;
	cout << first(arr, 0, n-1, x) << " " << last(arr, 0, n-1, x, n);
}
