/* Program to search data in given array using ternary search */

#include <stdio.h>
#include <stdlib.h>

// Function to search data in a given array
int Ternary_search(int *arr,int l,int r,int to_search)
{
    //split current array into 3 part
    int Mid1=l+(r-l)/3,Mid2=r-(r-l)/3;
    // data not found condition
    if(l>r)
        return -1;
    // if data found in Mid1 index then return index number
    else if(arr[Mid1]==to_search)
        return Mid1;
    // if data found in Mid2 index then return the index number
    else if(arr[Mid2]==to_search)
        return Mid2;
    //else if data not found at index Mid1 and Mid2 then search in middle part of array
    else if(arr[Mid1]<to_search&&arr[Mid2]>to_search)
    {
      Mid1=Mid1+1;
      Mid2=Mid2-1;
    }
    // if data is less than Mid index data then search in before index number of current
    else if(arr[Mid1]>to_search)
        {
            Mid2=Mid1-1;
            Mid1=l;
        }
    // if data is less than Mid index data then search in after index number of current
    else if(arr[Mid2]<to_search)
    {
        Mid1=Mid2+1;
        Mid2=r;
    }
    // recursive calling the function
    return Ternary_search(arr,Mid1,Mid2,to_search);
}
// driver code
int main()
{
    int n,*arr,i,to_search,res;
    printf("Enter size: ");
    // taking input
    scanf("%d",&n);
    // dynamically allocating array
    arr=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number to search: ");
    // taking data to search
    scanf("%d",&to_search);
    // calling function to search index of given number and assign it in res
    res=Ternary_search(arr,0,n,to_search);
    // if res contain -1 that means data not found
    if(res==-1)
        printf("Data Not Found");
    else
        printf("Data found at index no: %d",res);

return 0;

}
/*
Input: Enter size: 5
       1,2,3,4,5
       Enter the number to search: 2
Output: Data found at index  no: 1

Time complexity: O(log3 n)
Space complexity: O(1)

*/
