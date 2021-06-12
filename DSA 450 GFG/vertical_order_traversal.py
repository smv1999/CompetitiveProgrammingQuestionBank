# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root):
      
        def _traverse(node, row, col, cache):
          
            if not node:
                return
            _traverse(node.left, row + 1, col - 1, cache)
            cache[col].append((row, node.val))
            _traverse(node.right, row + 1, col + 1, cache)
        
        cache = defaultdict(list)
        _traverse(root, 0, 0, cache)
        ans = []
        for key in sorted(cache):
            ans.append(x[1] for x in sorted(cache[key]))
        return ans 