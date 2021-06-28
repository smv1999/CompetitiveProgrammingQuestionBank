# Link for the problem : https://leetcode.com/problems/binary-tree-preorder-traversal/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def preorderTraversal(self, root):
        stack = deque()
        op = []
        
        if(root == None):
          return
        
        stack.append(root)
        
        while stack:
          
          curr = stack.pop()
          op.append(curr.val)
          
            
          if(curr.right):
            stack.append(curr.right)
            
          if(curr.left):
            stack.append(curr.left)
            
        return op
          