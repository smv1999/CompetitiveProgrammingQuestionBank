# Python program to print right view of Binary Tree
 
# A binary tree node
class Node:
    # A constructor to create a new Binary tree Node
    def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

#Function to print right view of Binary Tree
def rightSideView(root):
    ans=[]
    # Base Case
    if not root:
        return ans
    else:
        l = []
        l.append(root)
        while l:
            for i in range(len(l)):
                node = l.pop(0)
                if node.left != None:
                    l.append(node.left)
                if node.right != None:
                    l.append(node.right)
            ans.append(node.val)
        return ans

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(None)
root.left.right = Node(5)
root.right.left = Node(None)
root.right.right = Node(4)

print(rightSideView(root))



