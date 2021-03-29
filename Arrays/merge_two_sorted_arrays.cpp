// Problem - Merge two sorted arrays without using extra space
//     Since, extra space should not be used, use the input arrays itself to perform this task
// For example: If the input array is, 
// 				a = [0 , 2 , 4 , 6 , 8]
// 				b = [1 , 3 , 5 , 7]
// The output arrays should be,
// 				a = [0 , 1 , 2 , 3 , 4]
// 				b = [5 , 6 , 7 , 8]

// Sample Input - 1
// 		a = [5 , 8 , 9 , 10]
// 		b = [1 , 2 , 100]

// Sample Output - 1
// 		a = [1 , 2 , 5 , 8]
//      b = [9 , 10 , 100]

// Time Complexity: O(nlogn)
// Auxiliary Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge two arrays without extra space
void merge_two_arrays(vector <int> &arr1 , vector <int> &arr2) {

	int i = arr1.size() - 1 , j = 0;

	while(true) {
		if(arr1[i] > arr2[j]) {
			swap(arr1[i] , arr2[j]);
			sort(arr1.begin() , arr1.end());
			sort(arr2.begin() , arr2.end());
		} else {
			break;
		}
	}

}

int main() {

	int n1 , n2;
	cout << "Enter the size of the first array : " << endl;
	cin >> n1;

	cout << "Enter the size of the second array : " << endl;
	cin >> n2;

	vector <int> arr1(n1) , arr2(n2);

	cout << "Enter the elements of first array in sorted order : " << endl;
	for(int i = 0; i < n1; i++) {
		cin >> arr1[i];
	}

	cout << "Enter the elements of second array in sorted order : " << endl;
	for(int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}

	merge_two_arrays(arr1 , arr2);

	cout << "After merging : " << endl;
	for(int i = 0; i < n1; i++) {
		cout << arr1[i] << " ";
	}
	for(int i = 0; i < n2; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	return 0;
}