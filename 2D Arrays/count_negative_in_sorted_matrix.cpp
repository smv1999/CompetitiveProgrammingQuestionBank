// Problem - Count the no. of negative elements in the row and column sorted (descending) matrix
//
// Sample Input - 1
// 		3 4
//      4 3  2 -1
//      3 2 -1 -2
//      1 1 -3 -10
//
// Sample Output - 1
// 		5
//
// Time Complexity: O(m + n)
// Auxiliary Space Complexity: O(1)

#include <iostream>
#include <vector>

// Function to count the no. of negative elements in the sorted matrix
int count_negatives_in_matrix(vector <vector <int>> matrix) {

	int count = 0;
	int i = 0 , j = matrix[0].size() - 1;

	// Perform Staircase Search
	while(i <= matrix.size() - 1 && j >= 0) {
		if(matrix[i][j] < 0) {
			count += i;
			j--;
		} else {
			i++;
		}
	}
	return count;
}

int main() {

	int m , n;
	cin >> m >> n;

	vector <vector <int>> matrix(m , vector <int> (n));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	int count_of_negatives = count_negatives_in_matrix(matrix);

	cout << "The no. of negative elements in the matrix is : " << count_of_negatives;
	return 0;
}