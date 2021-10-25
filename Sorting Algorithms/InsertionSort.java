import java.util.Scanner;

public class InsertionSort
{
    static void insertionSort(int arr[], int n)
    {
        int i,j,temp;
        for(i=0;i<n;i++)
        {
            temp = arr[i];
            j = i-1;
            while(j >=0 && arr[j] > temp)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }
    public static void main(String[] args)
    {
        int size,i;
        System.out.println("Enter the size of the array : ");
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("\nEnter "+size+" elements : ");
        for(i=0;i<size;i++)
        {
           arr[i] = sc.nextInt();
        }
        System.out.println("\nBefore sorting : ");
        for(i=0;i<size;i++)
        {
            System.out.print(arr[i]+" ");
        }
        insertionSort(arr,size);
        System.out.println("\nAfter sorting : ");
        for(i=0;i<size;i++)
        {
            System.out.print(arr[i]+" ");
        }

    }
}




