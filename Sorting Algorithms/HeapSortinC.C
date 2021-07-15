#include<stdio.h>
#include<conio.h>
void heapify(int arr[],int n,int i)
{
	int max=i; //parent node index
	int left = 2*i +1; // left child node index
	int right =2*i+2; //right child node index
	int temp;
	if(left<n && arr[left]> arr[max]) //if left child node is greater than parent 
    {
	    max =left;
    }
	if(right<n && arr[right]> arr[max])
    {
	    max =right;
    }
		if(max != i)
		{
			temp = arr[i];  //swapping the max element to the root node
			arr[i]=arr[max];
			arr[max]=temp;
			heapify(arr,n,max); //every node element
	    }
}

	
void heapsort(int arr[],int n)
{
	int i,temp;

	for(i=n/2-1;i>=0;i--)
    {
	    heapify(arr,n,i);
    }
    //swap the elements and heapify again
	for(i=n-1;i>=0;i--)
	{
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapify(arr,i,0); //root node swap from 0th index
	}
}
int main()	
{
	int arr[100],n,i;
	printf("\n Enter the n of the elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
	    
		scanf("%d",&arr[i]);
	}
	    heapsort(arr,n);
	    printf("The Heap Sorted Array is:");
	    for(i=0;i<n;i++)
	    {    
	    	printf("\t %d",arr[i]);
        }    	
}