// Binary search is used to search a key element from multiple elements in an array.

class BinarySearch{
    public static void binarySearch(int arr[], int first, int last, int key){
        int mid = (first+last)/2;
        while (first <= last){
            
            if (arr[mid]<key){
                first = mid+1;
            }
            
            else if(arr[mid]==key){
                System.out.println("Element found at index: "+ mid);
                break;
            }
            
            else{
                last = mid-1;
            }
            
            mid = (first+last)/2;
        }
            
        if(first > last){
            System.out.println("Element not found");
        }
    }
        
        
    public static void main (String[] args) {
        int arr[] = {10,20,30,40,50};
        int key=40;
        int last = arr.length-1;
        binarySearch(arr, 0, last, key);
    }
    
}

// Time Complexity = O(logn)
// Space Complexity = O(1)
