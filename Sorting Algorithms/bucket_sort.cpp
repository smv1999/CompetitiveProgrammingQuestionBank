/*
Bucket sort is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Each bucket is then sorted individually, either using a different sorting algorithm,
or by recursively applying the bucket sorting algorithm.Bucket sort is mainly useful when input is uniformly distributed
over a range. Bucket sort can be implemented with comparisons and therefore can also be considered a comparison sort algorithm.
*/
#include<bits/stdc++.h>
using namespace std;

//to sort the individual bucket
void Insertion_Sort(float arr[10][10], int n, int idx) {
  for (int i = 0; i < n; i++) {
    int k = i;
    float temp = arr[idx][i];
    while (k - 1 >= 0 && arr[idx][k] < arr[idx][k - 1]) {
      arr[idx][k] = arr[idx][k - 1];
      k = k - 1;
    }

    arr[idx][k] = temp;
  }
}

void Bucket_Sort(float arr[20], int n) {
  // Declare a 2D array of float numbers
  float temp[10][10];
  //count array stores the length of elements in the respective buckets
  int count[10] = {
    0
  };
  for (int i = 0; i < n; i++) {
    int idx = arr[i] * 10;
    temp[idx][count[idx]] = arr[i];
    count[idx]++;
  }

  for (int i = 0; i < 10; i++) {
    if (count[i] > 0)
      Insertion_Sort(temp, count[i], i);
  }

  //to rewrite the values in array in sorted order
  int i = 0;
  for (int j = 0; j < 10 && i < n; j++) {
    if (count[j] > 0) {
      for (int k = 0; k < count[j]; k++) {
        arr[i] = temp[j][k];
        i++;
      }
    }
  }
}

int main() {
  // Declare a variable to store no. of elements
  int n;
  // Declare an array of float numbers
  float arr[20];
  cout << "Enter number of elements :\n";
  cin >> n;
  cout << "Enter the elements:\n";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "\n";
  Bucket_Sort(arr, n);
  cout << "\nSorted array is \n";
  //loop to print sorted array
  for (int i = 0; i < n; i++) {
    cout << "\t" << arr[i];
  }
  return 0;
}

/*
Input:
Enter the number of elements :
4
Enter the elements:
0.123 0.008 0.7 0.4
Output:
Sorted array is
0.008 0.123 0.4 0.7

Time Complexities:
O(n+k): average time complexity
O(n²): worst time complexity
Space Complexity: O(n+k)
*/