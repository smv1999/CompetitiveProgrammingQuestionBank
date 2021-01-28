#include <iostream>
#include<algorithm>
using namespace std;

void countingSort(int arr[],int n,int pos){
    int countArr[10];
    int sortedArr[n];
    for(int i = 0 ; i < 10 ; i++)
        countArr[i] = 0;
    for(int i = 0 ; i < n ; i++)
        countArr[(arr[i]/pos)%10]++;
    for(int i = 1 ; i < n ; i++)
        countArr[i] = countArr[i] + countArr[i-1];
    for(int i = n - 1 ; i >= 0 ; i--)
        sortedArr[--countArr[(arr[i]/pos)%10]] = arr[i];
    for(int i = 0 ; i < n ; i++)
        arr[i] = sortedArr[i];
}

void radixSort(int arr[],int n){

    int maxElement = *max_element(arr, arr + n);
    for(int pos = 1 ; maxElement/pos > 0 ; pos*=10){
        countingSort(arr,n,pos);
    }

}

//Print the sorted array
void printSortedArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[] = {432,8,530,90,88,231,11,45,677,199}; // Unsorted Array
    int arr_size = sizeof(arr) / sizeof(arr[0]); //Getting array size
    radixSort(arr,arr_size); // Send the array to radixSort
    printSortedArray(arr,arr_size); // Print the sorted array
    return 0;
}