'''
From all the positive integers entered in a list, the aim of the program is 
to subtract any two integers such that the result/output is the maximum 
possible difference.

'''

# class to compute the difference
class Difference:
    def __init__(self, a):
        # getting all elements from the entered list
        self.__elements = a     
    def computeDifference(self):
        # maximum difference would be the difference between the largest and the smallest integer 
        Difference.maximumDifference = max(self.__elements)-min(self.__elements)
        return Difference.maximumDifference
# end of Difference class

# getting the input 
_ = input()
a = [int(e) for e in input().split(' ')]

# creating an object of the class
d = Difference(a)
# calling function 'computeDifference' to compute the difference
d.computeDifference()

# printing the result
print(d.maximumDifference)

'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(1)
     
Sample Input:
3
1 2 5

Sample Output:
4

Explanation:
Integer with max value--> 5
Integer with min value--> 1
Hence, maximum difference--> 5-1 = 4
    
'''