// Problem - Print the sum of all submatrices of the given matrix

// Sample Input - 1
// 		3 3
// 		1 1 1
// 		1 1 1
// 		1 1 1

// Sample Output - 1
// 		100

// Sample Input - 2
// 		3 2
// 		1 10 8
// 	   -1 5  0

// Sample Output - 2
// 		152

#include <iostream>
#include <vector>

using namespace std;


int sum_of_all_submatrices(vector <vector <int>> grid) {

	// Contribution of an element to the sum is defined as at index (i , j) of matrix with order n * m:
	// 		value * (i + 1) * (j + 1) * (n - i) * (m - j)

	// Time Complexity: O(n ^ 2)
	// Auxiliary Space Complexity: O(1)


	int n = grid.size();
	int m = grid[0].size();
	int sum = 0;


	// Traversing the matrix
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {

			// Calculating the contribution of an element to the sum and adding it to the sum
			sum += grid[i][j] * (i + 1) * (j + 1) * (n - i) * (m - j);
		}
	}

	return sum;

}

int main() {

	int m , n;
	cout << "Enter the no. of rows and columns : " << endl;
	cin >> m >> n;

	vector <vector <int>> grid(m , vector<int> (n));
	cout << "Enter the elements of the matrix : " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	int sum = sum_all_submatrices(grid);

	cout << "The sum of all submatrices of the given matrix is : " << sum << endl;

	return 0;
}
