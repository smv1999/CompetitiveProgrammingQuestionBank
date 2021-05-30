/* Program to sort array using bubble sort */

#include<stdio.h>
#include<stdlib.h>
// function to sort array using bubble sort
void bubble_sort(int a[],int size)
{
    int round,i,swap=0;
         // run loop until round is less than size
    for(round=1;round<=size-1;round++)
    {
        // run inner loop until i is less than size-round
        for(i=0;i<size-round;i++)
         {
            if(a[i]>=a[i+1])
         {
        // swap a[i] and a[i+1]
        swap=a[i];
        a[i]=a[i+1];
        a[i+1]=swap;
         }
         }
    }
      // print the output
    printf("Bubble sort:  ");
    for(i=0;i<size;i++)
    printf("%d  ",a[i]);
}
// driver code
int main()
{
    int *arr,i,n;
    printf("Enter the size: ");
    // taking size
    scanf("%d",&n);
    // dynamically allocating array in arr
    arr=(int*)malloc(sizeof(int)*n);
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    // calling bubble sort function
        bubble_sort(arr,n);

return 0;

}
/*
Input: Enter the size: 10
Enter 10 numbers
10 9 8 7 6 5 4 3 2 1
Output:
Bubble sort:  1  2  3  4  5  6  7  8  9  10

Time complexity: O(N^2)

*/
