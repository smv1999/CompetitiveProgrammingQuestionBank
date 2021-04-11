/*
Binary Search

input
5
1 2 3 4 5
3

output
2

For binary search algorithm to work, the array should be in a sorted order. This search algorithm returns
the index of the element that is found. If the element is not found it returns -1.

*/
#include<stdio.h>

int binarySearch(int a[],int n,int k)
{
  int first = 0;
  int last = n-1;
  while(first <= last)
  {
    int mid = (first + last)/2;
    if(a[mid]>k)
    last = mid -1;
    else if(a[mid]<k)
    first = mid + 1;
    else if(a[mid]==k)
      return mid;
  }
  return -1;
}
int main(int argc, char const *argv[])
{
    int n,k,pos;
    scanf("%d",&n);
    int a[n];;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    pos = binarySearch(a,n,k);
    if(pos == -1)
      printf("Element is not found!");
    else
      printf("Element %d is found at %d",k,pos);
    return 0;
}
