

def rearrange (arr , n ):
    j = 0 
    for i in range(0 , n)  :
        if(arr[i] < 0):
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp 
            j = j + 1
    print(arr)
    
#Driver code 
sequence = [1 , 3, - 6 , 9 , -3 , -1]
length = len(sequence)
print(sequence.sort)
rearrange(sequence , length)