// Problem - Print the matrix in the wave form

// Sample Input - 1
// 		3 4
//		1  2  3  4 
// 		5  6  7  8
// 		9  10 11 12
// 		13 14 15 16

// Sample Output - 1
// 		1 5 9 13 14 10 6 2 3 7 11 15 16 12 8 4


#include <iostream>
#include <vector>

using namespace std;

void wave_print(vector <vector <int>> matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {

			// When row is odd, print the column from bottom to top
			if(i & 1)
				cout << matrix[n - j - 1][i] << " ";

			// When row is even, print the column from top to bottom
			else
				cout << matrix[j][i] << " ";
		}
	}

}

int main() {

	int n , m;
	cout << "Enter the no. of rows and columns : " << endl;
	cin >> n >> m;

	vector <vector <int>> matrix(n , vector <int> (m));
	cout << "Enter the elements of the matrix : " << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			cin >> matrix[i][j];
	}

	wave_print(matrix);

	return 0;
}