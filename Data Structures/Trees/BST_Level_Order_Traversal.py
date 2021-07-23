'''
Aim: To perform level-order traversal on a BST.

'''

# initializing the tree
class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
        
class Solution:
    # inserting node
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root
    # performing level order traversal
    # the values will be printed according to the level they are in
    def levelOrder(self,root):
        if root is None:
            return 
        q = []
        q.append(root)
        while len(q) !=0:
            p = q.pop(0)
            print(p.data, end=' ')
            if p.left is not None:
                q.append(p.left)
            if p.right is not None:
                q.append(p.right)
        return q
    
# getting the input    
T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
# printing the result
myTree.levelOrder(root)

'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(N)
     
Sample Input:
6
3
5
4
7
2
1
Sample Output:
3 2 5 1 4 7

Explaination:
The BST looks something like this:
    
                3                    Level 0
            2       5                Level 1
        1        4      7            Level 2
 
So, starting from level 0 and going to level 2, traversal will look like: 3, 2 5, 1 4 7.

'''