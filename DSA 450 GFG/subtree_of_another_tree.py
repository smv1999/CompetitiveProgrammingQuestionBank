
# https://leetcode.com/problems/subtree-of-another-tree/submissions/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
  
    def sameTree(self , root , subRoot):
      if(root == None or subRoot == None):
        return root == None and subRoot == None
      elif(root.val == subRoot.val):
        return self.sameTree(root.right , subRoot.right) and self.sameTree(root.left , subRoot.left)
      else:
        return False
      
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        if(root == None):
          return False
        elif(self.sameTree(root , subRoot)):
          return True
        else:
          return self.isSubtree(root.right , subRoot) or self.isSubtree(root.left , subRoot)

