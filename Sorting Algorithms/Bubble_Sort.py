def Bubble_Sorting(Test_list):
    for i in range(len(Test_list)-1):
        for j in range(len(Test_list)-i-1):
            if Test_list[j] > Test_list[j+1]:
                Test_list[j], Test_list[j+1] = Test_list[j+1], Test_list[j]
    return Test_list


Test_list = [64, 34, 25, 12, 22, 11, 90]
print(Bubble_Sorting(Test_list))
