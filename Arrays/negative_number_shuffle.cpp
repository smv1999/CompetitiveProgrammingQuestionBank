//This program will move all negative elements of an array of integers to the end of the array without changing the order of positive element and negative element

#include <iostream>
using namespace std;

void segregateElements(int nums[], int n)
{
    // Array to store result
    int result[n];

    int j = 0; // index of result
    for (int i = 0; i < n ; i++)
        if (nums[i] >= 0 )
            result[j++] = nums[i];
    if (j == n || j == 0)
        return;
 
    for (int i = 0 ; i < n ; i++)
        if (nums[i] < 0)
            result[j++] = nums[i];
 
    // Copy contents to nums[]
    memcpy(nums, result, sizeof(result));
} 
 
int main()
{
    int nums[] = {1, 3, -7, 2, -13, 19, -20}; 
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Original array: ";
    for (int i=0; i < n; i++) 
    cout << nums[i] <<" ";
     segregateElements(nums, n);
 
    printf("\nArray elements after rearrange: ");
      for (int i=0; i < n; i++) 
      cout << nums[i] <<" ";
        return 0;
      
}
