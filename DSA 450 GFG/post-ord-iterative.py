
# https://leetcode.com/problems/binary-tree-postorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
      
      if root == None:
        return
      
      stack = deque()
      stack.append(root)

      # create another stack to store postorder traversal
      out = deque()

      # loop till stack is empty
      while stack:

          # pop a node from the stack and push the data into the output stack
          curr = stack.pop()
          out.append(curr.val)

          # push the left and right child of the popped node into the stack
          if curr.left:
              stack.append(curr.left)

          if curr.right:
              stack.append(curr.right)
              
      out.reverse()
      
      return out