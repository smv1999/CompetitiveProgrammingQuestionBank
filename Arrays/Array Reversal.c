//This is a Program to reverse an array
// i.e. Input: 1,2,3,4,5
// Output:5,4,3,2,1
#include <stdio.h>
#include <stdlib.h>
// added the useful header file
int main()
{
    // initialize the variable
    int num, *arr, i,swap=0;
     // taking array length from user
    scanf("%d", &num);
    //dynamically creating array to stop the waste of unnecessary memory
    arr = (int*) malloc(num * sizeof(int)); 
    for(i = 0; i < num; i++) {
        // taking input
        scanf("%d", arr + i); 
    }
    // This is the main logic to reverse an array
    // loop will run until i<num/2
for(i=0;i<num/2;i++) 
{ // swapping
 // putting value of arr[i] in swap variable
swap=*(arr+i); 
// putting value of arr[num-i-1] in arr[i]
*(arr+i)=*(arr+(num-1-i));
// putting swap variable value in arr[num-1-i]
*(arr+(num-1-i))=swap; 
// swapping completed
}
// printing the output
for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
// Time complexity = O(N/2)
