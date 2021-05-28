/*
Program to search data in array using Jump Search
Jump Search: It is a way to search data in array where it jump sqrt(n-1) and if data is less
than current then it started searching it linearly
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Function to search data linearly
int jump_search(int *arr,int n,int jump,int to_search)
{
    int start=0,end=jump;
    //until n(size) is greater than end run the loop
    while(end<n)
    {
        //if the data to search is greater than the end of arr then assign end to start and end+jump in end
        if(arr[end]<to_search)
        {
            start=end;
            end=end+jump;
        }
        // else means the data is less then or equal to the data to search
        else
        {
           //search linearly until end is greater or equal to start
            while(start<=end)
            {
                //if the data is found then return that data index else add 1 in start and repeat the loop
                if(arr[start]==to_search)
                    return start;
                    start++;
            }
        }
    }
    //if data not found then return -1 will tells that data didn't exist
return -1;
}
//driver code
int main()
{
    int n,*arr,jump,i,to_search,res;
    printf("Enter size: ");
    //taking the size of array
    scanf("%d",&n);
    //dynamically allocating memory and returning the base address and assign it to arr
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //find the number of jumps to take every time
    jump=(int)sqrt(n-1);
    printf("Enter the number to search: ");
    //taking the data to search
    scanf("%d",&to_search);
    //calling jump function
    res=jump_search(arr,n,jump,to_search);
    // if res is equal to -1 that means data didn't exist
    if(res==-1)
        printf("Data Not Found \n");
    else
        printf("Data Found at index: %d",res);
return 0;

}
/*
Case 1:
Input: Enter size: 10
       1,2,3,4,5,6,7,8,9,10
       Enter the data to search: 11
Output: Data not Found

Case 2:

Input: Enter size: 10
       1,2,3,4,5,6,7,8,9,10
       Enter the data to search: 7
Output: Data Found at index: 6

Time complexity: O(squareroot (n))

*/
