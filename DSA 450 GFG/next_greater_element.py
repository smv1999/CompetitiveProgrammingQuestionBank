#https://leetcode.com/problems/next-greater-element-i/submissions/

# Approach : 

# We need to find the next greater element than the current element which is in the right side of the array

# Since Nums1 is a subset of Nums2 , we will be finding the next greater element in Nums2 and keep storing it in a Hashmap 
# And return only those values which are are present in Nums1 

# since we need the immediate next element greater than the current element 
# Create a stack to store an element from the nums , compare the top of the stack with the elements from nums2
# IF the element from nums is greater than the top of the stack , then store this pair in a hashmap 
# If the element from the nums is lesser than the top of the stack or if the stack is empty , append the element in the stack 
# After the nums2 is iterated , check if there is any element remaining in the stack 
# If there is any element remaining , it means that , these elements dont have any other element greater than it (to the right side of the array)
# So append these elements to the hashmap as keys with values -1

# Lastly , return the list of elements from the hashmap which are present in nums1 i.e the required output


class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        stack = []
        d = {}
        
        for num in nums2 :
          while stack and stack[-1] < num:
            top = stack.pop()
            d[top] = num
          
          if not stack or stack[-1] > num:
            stack.append(num)
            
        while(stack):
          rest = stack.pop()
          d[rest] = -1
        
        return [d[i] for i in nums1]
    
    
# Time Complexity: O(N) 
# Auxiliary Space: O(N)