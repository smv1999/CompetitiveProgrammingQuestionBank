// Problem - Print the sum of all submatrices of the given matrix for Q queries.
//           The coordinates (start and end index) of the submatrix is given as queries
//           the problem is to find the sum of those submatrices for given queries.

// Sample Input - 1
// 		3 3
// 		1 1 1
// 		1 1 1
// 		1 1 1
// 		2 
// 		2 2
//      2 2
//      0 0
//      1 1

// Sample Output - 1
// 		1
// 		4

// Sample Input - 2
// 		3 2
// 		1 10 8
// 	   -1 5  0
// 		2
// 		0 0
// 		1 2
// 		1 1
// 		1 2

// Sample Output - 2
// 		23
// 		5

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> build_prefix_sum(vector <vector <int>> grid) {

	int n = grid.size() , m = grid[0].size();
	vector <vector <int>> prefix_sum(n , vector <int> (m));

	// Calculating the prefix sum of rows
	for(int i = 0; i < n; i++) {
 		for(int j = 0; j < m; j++) {
 			if(j == 0)
 				prefix_sum[i][j] = grid[i][j];
 			else
 				prefix_sum[i][j] = prefix_sum[i][j - 1] + grid[i][j];
 		}
 	}

 	// Calculating the prefix sum of columns
 	for(int i = 0; i < n; i++) {
 		for(int j = 0; j < m; j++) {
 			if(i != 0)
 				prefix_sum[i][j] += prefix_sum[i - 1][j];
 		}
 	}

 	return prefix_sum;

}

int submatrix_sum(vector <vector <int>> prefix , int tl1 , int tl2 , int br1 , int br2) {

	int n = prefix.size() , m = prefix[0].size();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << prefix[i][j] << " ";
		cout << endl; 
	}

	int sum = 0;
 	sum += (prefix[br1][br2]);

	if(tl1 > 0 && tl2 > 0)
		sum = sum - (prefix[br1][tl2 - 1] + prefix[tl1 - 1][br2]) + prefix[tl1 - 1][tl2 - 1];
	else if(tl1 > 0)
		sum = sum - prefix[tl1 - 1][br2];
	else
		sum = sum - prefix[br1][tl2 - 1];

	return sum;

}

int main() {

	int n , m;
	cin >> n >> m;

	vector <vector <int>> grid(n , vector <int> (m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cin >> grid[i][j];
	}

	int q;
	cin >> q;

	vector <vector <int>> prefix_sum = build_prefix_sum(grid);


	for(int i = 0; i < q; i++) {

		int tl1 , tl2 , br1 , br2;
		cin >> tl1 >> tl2;
		cin >> br1 >> br2;

		int sum = submatrix_sum(prefix_sum , tl1 , tl2 , br1 , br2);

		cout << sum << endl;

	}

	return 0;
}
