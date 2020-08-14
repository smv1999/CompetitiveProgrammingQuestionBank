#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int n, int k)
{
    int start = 0;
    int end = n-1;

    while(start<=end)
    {
        int mid = (start+end)/2;

        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k)
            start = mid + 1;
        else if(arr[mid]>k)
            end = mid - 1;
    }
    return 0;
}
//6 3
//5 5 7 9 15 2
int main()
{
    int n, k, happyCounter=0;
    scanf("%d %d", &n,&k);

    int arr[n];

    for(int arr_ind=0;arr_ind<n;arr_ind++)
        scanf("%d", &arr[arr_ind]);

    for(int arr_ind=0;arr_ind<n;arr_ind++)
    {
       for(int range=arr[arr_ind]-k;range<=arr[arr_ind]+k;range++)
       {
           if(binarySearch(arr, n, range))
           {
               happyCounter++;
               break;
           }
       }

    }

    printf("%d", happyCounter);
    return 0;
}
