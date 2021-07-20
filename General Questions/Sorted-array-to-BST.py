# Python program to convert sorted array into Binary Search Tree
# Definition for a binary tree node.
class Node:
    def __init__(self, d):
        self.data = d
        self.left = None
        self.right = None

def sortedArrayToBST(nums):
    if not nums:
        return None

    mid = (len(nums)) // 2

    root = Node(nums[mid])  # make the middle element the root

    root.left = sortedArrayToBST(nums[:mid])  # all values < nums[mid]

    root.right = sortedArrayToBST(nums[mid + 1:])  # all values > nums[mid]
    return root

def preOrder(node):  # function to print the tree
    if not node:
        return None

    print(node.data)
    preOrder(node.left)
    preOrder(node.right)

# driver program
nums = [5,6,7,8,9,10,11]
root = sortedArrayToBST(nums)
print("PreOrder Traversal of constructed BST ")
preOrder(root)
