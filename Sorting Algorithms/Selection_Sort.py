def Selection_Sorting(Test_list):
    for i in range(len(Test_list)):
        min = i
        for j in range(i+1, len(Test_list)):
            if Test_list[min] > Test_list[j]:
                min = j
        Test_list[i], Test_list[min] = Test_list[min], Test_list[i]
    return Test_list

Test_list = [64, 25, 12, 22, 11]
print(Selection_Sorting(Test_list))