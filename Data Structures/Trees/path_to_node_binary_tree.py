"""
Binary tree do not store data in sorted manner, so to find an element we cant decide left or right subtree, we need to traverse whole tree,
also as we do not know if the element is in left or right subtree, we cant store values on our way from root to node,
we need to store only once it has been found. 

eg :    1 
       / \ 
      2   3
     / \ 
    4   5

path to 5 : 1 -> 2 -> 5

We are using recursive approach to traverse the tree and find the element and store the path on our way back.
Time complexity: O(n) in worst case, where n is the number of nodes in the binary tree.

"""

class Node :
    """Class to define nodes of the tree with data, left ptr, and right ptr as attributes"""
    def __init__(self, value):
        self.data = value 
        self.left = None
        self.right = None

def getPath (node, n, path):
    """The function returns the path from root node as a list, along with a bool ans if the node exists in tree or not
        input : current root node of subtree, element to be found, path storing list
        returns : ans boolean - True if it is in the tree and False if it doesn't exist
                  path - list of nodes that occur on the path from node to the root
    """
    if node == None:        
        return False, path
    
    if node.data == n:      # if the element has been found, we return true and also add the element to the path
        path.append(node.data)
        return True, path

    left, lpath = getPath(node.left, n, path)       # element not yet found so look for it in left subtree
    right, rpath = getPath(node.right, n, path)     # element not yet found so look for it in right subtree

    if left == True:                # element is in left subtree, so return true and add all the elements on our way back
        path.append(node.data)
        return True, lpath
    elif right == True:             # element is in right subtree, so return true and add all the elements on our way back
        path.append(node.data)
        return True, rpath
    
    if not (left and right):        # element is in neither sub trees, so it does not exist in tree. Return false and an empty list
        return False, []
    




# ========================= DRIVER CODE ======================= 

if __name__ == "__main__":
    
    # creating the tree
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.left.left.left = Node(8)
         
    n = 8
    path = []
    ans, path = getPath(root, n, path)

    if ans:
        print(f"Path to {n} : ", path[::-1])        # printing the path in reverse order, as the the returned value contains path from node to root
    else:
        print(f"{n} does not exist in tree")        # printing a message if the element is not in the tree