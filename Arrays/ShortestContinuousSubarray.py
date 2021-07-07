# Shortest Unsorted Continuous Subarray

"""
Find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return length of the shortest subarray.

Example 1: nums = [2,6,4,8,10,9,15]
o/p:- 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Example 2: nums = [1,2,3,4]
o/p:- 0
"""

def findUnsortedSubarray(nums):
        res=[]
        ans=[]
        final=[]
        for i in nums:
            res.append(i)
       
        res.sort()
        for i in range(0,len(nums)):
            if nums[i]!=res[i]:
                ans.append(i)
          
        if len(ans)==0:
            return 0
        else:
            for i in range(ans[0],ans[len(ans)-1]+1):
                final.append(nums[i])
            
            return len(final)

nums=[]
n=int(input("Enter the no. of elements: "))
print("Enter the elements of the array one by one: ")
for i in range(0,n):
	
	ele=int(input())
	nums.append(ele)

answer=findUnsortedSubarray(nums)
print("The length of the shortest subarray:",answer)