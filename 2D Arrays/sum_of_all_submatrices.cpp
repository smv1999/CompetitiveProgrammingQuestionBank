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

int sum_all_submatrices(vector <vector<int>> grid) {

	int m = grid.size() , n = grid[0].size();
	int sum = 0;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			for(int tl = i; tl < m; tl++) {
				for(int br = j; br < n; br++) {
					for(int r = i; r <= tl; r++) {
						for(int c = j; c <= br; c++) {
							sum += grid[r][c];
						}
					}
				}
			}
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