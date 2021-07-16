#function to implement the shell sort
def shellsort(arr,n):

    #calculate gap which is half of the length
    gap=n//2

    # Do a gapped insertion sort for this gap size.
    # The first gap elements a[0..gap-1] are already in gapped 
    # order keep adding one more element until the entire array
    # is gap sorted
    while(gap>0):

        #Loop iterating from gap to n-1
        for i in range(gap,n):
            temp=arr[i]  #value in arr[i] is assigned to temporary variable
            j=i   

            while j>=gap and arr[j-gap]>temp:
                arr[j]=arr[j-gap]  #value of arr[j-gap] is assigned to arr[j]
                j=j-gap   
            arr[j]=temp    #After loop terminates temporary value is assigned to arr[j]
        gap=gap//2      



n=int(input("Enter the no of elements:"))
arr=list(map(int,input("Enter the elements:").split()))
print("Before Shell Sort")
print(arr)
shellsort(arr,n)
print("After Shell Sort")
print(arr)