//This is a Program to reverse an array
// i.e. Input: 1,2,3,4,5
// Output:5,4,3,2,1
#include <stdio.h>
#include <stdlib.h>
// added the useful header file
int main()
{
    int num, *arr, i,swap=0; // initialize the variable
    scanf("%d", &num); // taking array length from user
    arr = (int*) malloc(num * sizeof(int)); //dynamically creating array to stop the waste of unnecessary memory
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i); // taking input
    }
    // This is the main logic to reverse an array
for(i=0;i<num/2;i++) // loop will run until i<num/2
{ // swapping
swap=*(arr+i); // putting value of arr[i] in swap variable
*(arr+i)=*(arr+(num-1-i)); // putting value of arr[num-i-1] in arr[i]
*(arr+(num-1-i))=swap; // putting swap variable value in arr[num-1-i]
// swapping completed
}
// printing the output
for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
// Time complexity = O(N/2)
