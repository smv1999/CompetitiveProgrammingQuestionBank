def partition(Test_list, low, high):
    i = low-1
    pivot = Test_list[high]
    for j in range(low, high):
        if Test_list[j] < pivot:
            i += 1
            Test_list[i], Test_list[j] = Test_list[j], Test_list[i]
    Test_list[i+1], Test_list[high] = Test_list[high], Test_list[i+1]
    return (i+1)


def Quick_Sorting(Test_list, low, high):
    if len(Test_list) == 1:
        return Test_list
    if low < high:
        Part = partition(Test_list, low, high)
        Quick_Sorting(Test_list, low, Part-1)
        Quick_Sorting(Test_list, Part+1, high)

Test_list = [11, 35, 12, 36, 10, 6, 25]
Quick_Sorting(Test_list, 0, len(Test_list)-1)
print(Test_list)