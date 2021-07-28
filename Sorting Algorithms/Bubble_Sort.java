/*
Bubble Sort is the simplest sorting algorithm
that works by repeatedly swapping the adjacent
elements if they are in wrong order.


*/
public class BubbleSortExample {  
    static void bubbleSort(int[] arr) {  
        // finding array size. 
        int n = arr.length;  
        int temp = 0;  
        //each iteration place max element of 1 to n-i index at index n-i
         for(int i=0; i < n; i++){  
                 for(int j=1; j < (n-i); j++){  
                          if(arr[j-1] > arr[j]){  
                                 //swap elements  
                                 temp = arr[j-1];  
                                 arr[j-1] = arr[j];  
                                 arr[j] = temp;  
                         }   
                 }  
         }  
  
    }  
    public static void main(String[] args) {  
                int arr[] ={3,60,35,2,45,320,5};  
                 
                System.out.println("Array Before Bubble Sort");  
                for(int i=0; i < arr.length; i++){  
                        System.out.print(arr[i] + " ");  
                }  
                System.out.println();  
                  
                bubbleSort(arr);//sorting array elements using bubble sort  
                 
                System.out.println("Array After Bubble Sort");  
                for(int i=0; i < arr.length; i++){  
                        System.out.print(arr[i] + " ");  
                }  
   
        }  
}  

/* 
Bubble Sort always runs O(n^2) time even if the array is sorted. 
It can be optimized by stopping the algorithm if inner loop didn’t cause any swap. 
*/
