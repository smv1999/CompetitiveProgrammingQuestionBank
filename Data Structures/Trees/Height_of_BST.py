'''
Aim: To form a Binary Search Tree of the integers entered and display its height.

'''

# initializing the tree
class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
        
class Solution:
    # function for inserting values according to BST rules
    def insert(self,root,data):
        if root == None:
            return Node(data)
        else:
            if data <= root.data:
                cur = self.insert(root.left,data)
                root.left = cur
            else:
                cur = self.insert(root.right,data)
                root.right = cur
        return root
  
    # calculating the height of the tree
    def getHeight(self,root):
        if root == None:
            return -1
        return 1 + max(self.getHeight(root.left), self.getHeight(root.right))
    
# getting the input for total number of integers to be entered
T = int(input())
# making an object of the class
myTree = Solution()
root = None

# inserting values
for i in range(T):
    data = int(input())
    root = myTree.insert(root,data) 
# geeting the height calculated    
height = myTree.getHeight(root)

# printing the result
print("Height of BST:",height)

'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(N)
     
Sample Input:
7
3
5
2
1
4
6
7
Sample Output:
Height of BST: 3

Explaination:
The BST looks something like this:
    
                3
            2       5
        1        4      6
                           7

So, the height is --> 3.

'''