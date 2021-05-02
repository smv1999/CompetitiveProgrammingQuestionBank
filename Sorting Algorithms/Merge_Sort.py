def Merging(Test_list, low, mid, high):
    n1 = mid-low+1
    n2 = high-mid

    left = [0]*n1
    right = [0]*n2

    for i in range(0, n1):
        left[i] = Test_list[low+i]

    for j in range(0, n2):
        right[j] = Test_list[mid+1+j]

    i = 0
    j = 0
    k = low
    while i < n1 and j < n2:
        if left[i] < right[j]:
            Test_list[k] = left[i]
            i += 1
        else:
            Test_list[k] = right[j]
            j += 1
        k += 1

    while i < n1:
        Test_list[k] = left[i]
        i += 1
        k += 1

    while j < n2:
        Test_list[k] = right[j]
        j += 1
        k += 1


def Merge_Sorting(Test_list, low, high):
    if low < high:
        mid = (low+(high-1))//2
        Merge_Sorting(Test_list, low, mid)
        Merge_Sorting(Test_list, mid+1, high)
        Merging(Test_list, low, mid, high)


if __name__ == "__main__":
    Test_list = [12, 11, 13, 5, 6, 7]
    Merge_Sorting(Test_list, 0, len(Test_list)-1)
    for ele in range(len(Test_list)):
        print(Test_list[ele], end=" ")
    print("\n")
