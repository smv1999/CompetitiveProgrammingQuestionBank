# Python program to convert sorted array into Binary Search Tree
# Definition for a binary tree node.
class TreeNode(object):

    def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution(object):

    def recursive(self, nums):
        def rec(nums, start, end):
            if start <= end:
                mid = (start + end) // 2                    # calculating root node
                node = TreeNode(nums[mid])
                node.left = rec(nums, start, mid - 1)       # recursive call to function recursive
                node.right = rec(nums, mid + 1, end)
                return node
            return rec(nums, 0, len(nums) - 1)

sol = Solution()        # Creation of object
nums = [-10,-3,0,5,9]
sol.recursive(nums)