/* Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element 
and place the maximum element at the end. We repeat the same process for the remaining elements.
*/

// C++ program for implementation of Heap Sort

#include <iostream>
 
using namespace std;
 
// A function to heapify the array.
void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;
		// Break if parent value is already greater than child value.
		if (temp > a[j])
			break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		MaxHeapify(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}
	// Building max heap.
	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
 
	for (i = 1; i < n; i++)
		cout<<"->"<<arr[i];
 
	return 0;
}
/* Output
Enter the number of data element to be sorted: 10
Enter element 1: 9
Enter element 2: 6
Enter element 3: 4
Enter element 4: 3
Enter element 5: 8
Enter element 6: 7
Enter element 7: 5
Enter element 8: 2
Enter element 9: 0
Enter element 10: 1
 
Sorted Data ->0->1->2->3->4->5->6->7->8->9
/*
