#include <iostream>

using namespace std;

void mergeArray(int arr[], int l, int m, int h){

    int n1 = m - l + 1 ; /// Getting the size of the first part, m = 3, l = 0 -> n1 = 4
    int n2 = h - m ;     /// Getting the size of the second part, m = 3, h = 7 -> n2 = 4

    int A[n1],B[n2]; // Initialize two arrays with n1 and n2

    // Copy the data to the first array
    for(int i = 0 ; i < n1 ; i++)
        A[i] = arr[l+i]; //start from 0

    //Copy the data to the second array
    for(int j = 0 ; j < n2 ; j++)
        B[j] = arr[m+1+j]; // start from 4

    int i =0,j=0,k=l; // i and index for the first array, j and index for the second array, k an index for the merged array


    //Copy the data in a sorted way to the two arrays
    while(i<n1 && j<n2){
        if(A[i] < B[j])
            arr[k++] = A[i++];
        else
            arr[k++] = B[j++];
    }

    //Copy the remaining data to the first array
    while(i<n1){
        arr[k++] = A[i++];
    }

    //Copy the remaining data to the second array
    while(j<n2){
        arr[k++] = B[j++];
    }
}

void mergeSort(int arr[],int l,int h){
    if(l>=h) // If the array contains only one element break
        return;
    int m = (l+h-1)/2; ///Getting the middle, l=0,h=7 -> m = 3
    mergeSort(arr,l,m); // MergeSort for the first part of array
    mergeSort(arr,m+1,h); // MergeSort for the second part of array
    mergeArray(arr,l,m,h); // Recursively merge the divided arrays
}

//Print the sorted array
void printSortedArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[] = {9,3,7,5,6,4,8,2}; // Unsorted Array
    int arr_size = sizeof(arr) / sizeof(arr[0]); //Getting array size
    mergeSort(arr,0,arr_size-1); // Send the array to mergeSort
    printSortedArray(arr,arr_size); // Print the sorted array
    return 0;
}
