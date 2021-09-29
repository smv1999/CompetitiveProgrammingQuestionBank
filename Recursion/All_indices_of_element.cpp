// CPP program to find all indices of a number
#include <bits/stdc++.h>
using namespace std;
// A recursive function to find all indices of a number in array.

int allIndexes(int input[], int size,
  int x, int output[])
{

    // If size of array is 0 then return 0

    if (size == 0) {
        return 0;
    }
 
    // recursion

    int smallAns = allIndexes(input + 1,size - 1, x, output);
 

    // If the element at first index is equal to x then add 1 to the array values and shift them right by 1 step

    if (input[0] == x) {
        for (int i = smallAns - 1; i >= 0; i--) {
            output[i + 1] = output[i] + 1;
        }
        // Put the start index in front

        // of the array

        output[0] = 0;

        smallAns++;

    }

    else {

        // If the element at index 0 is not equal to x then add 1 to the array values and no need to shift array.
      for (int i = smallAns - 1; i >= 0; i--) {

            output[i] = output[i] + 1;
        }
    }
    return smallAns;
}
 
// Function to find all indices of a number

void AllIndexes(int input[], int n, int x)
{

    int output[n];

    int size = allIndexes(input, n, x, output);

    for (int i = 0; i < size; i++) {

        cout << output[i] << " ";

    }
}
 
// Driver Code

int main()
{
    int n,arr[1000],x;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    cin>>x;

     

    // Function call

    AllIndexes(arr, n, x);

     

    return 0;
}