# Lowest Common Ancestor in Binary Tree
# Time Complexity : O(n) , Space Complexity : O(1)

"""
Binary trees are trees where any node can have only 0, 1 or 2 children, which are sorted in any order.
Lowest Common Ancestor (LCA) of two given nodes is the shared ancestor of n1 and n2 that is located farthest from the root
or the last common node that occurs on the paths from root node to those nodes.

Here, we first check if both numbers exist in tree or not, with exists_in_tree() function by recursively traversing the trees.
If yes then we find the LCA of both the elements with find_lca() function, which follows as :
    if LCA isnt found yet, but current node is one of the elements, then current node is the LCA
    else look for LCA in left and right subtree
        if both elements are found in different subtrees, make current node as LCA
        else if they are in same sub tree, return the LCA of that subtree

"""


class Node :
    """Class to define nodes of binary tree, with attributes data to store values, and left and right pointers"""
    def __init__(self, value) :
        self.data = value
        self.left = None
        self.right = None

def find_lca(node, n1, n2):    
    """Finds LCA of 2 numbers by recursively searching in left and right subtree
    input args : current node, the numbers whose lca is to be found, isFound list telling if the particular element is found
    returns : lca if found else None    
    Time complexity : O(n), Space complexity : O(1)
    """
    if node==None:
        return None

    # if one element is found in current node, we return it 
    # in normal case, both elements are found in different subtrees, called recursively, which is handeled later in this function
    # there may also be the case when one element is ancestor of another, which is handeled here, as this node is tha lca
    if node.data == n1:
        return node
    elif node.data == n2:
        return node

    # Recursive calls
    lca_left = find_lca(node.left, n1, n2)
    lca_right = find_lca(node.right, n1, n2)
    
    if lca_left and lca_right:      # if both are not none, that is 1 element is found in each subtree
        return node                 # that means, current node is the lca
    else:                           # both numbers in same sub tree
        return lca_left if lca_left!=None else lca_right    # return lca whichever is not none


def exists_in_tree(node, n):
    """This function finds if an element exists in a tree or not by recursively traversing the tree
        input : current node and the element to be found
        output : returns True if it exists, False if not
        Time complexity : O(n), Space complexity : O(1)
    """
    if node == None:
        return False
    if node.data == n:
        return True
    
    if exists_in_tree(node.left, n) or exists_in_tree(node.right, n):
        return True
    else:
        return False



def lowest_common_ancestor_binary_tree(root, n1, n2):
    """This function checks if both elements are present in binary tree or not, and depending upon that returns proper value
        input : root node of the tree, numbers whose lca is to be found
        output : returns calculated LCA, if both exist, else None
        Both Time and Space complexity are : O(1)        
    """
    if exists_in_tree(root,n1) and exists_in_tree(root,n2):     # if both the elements exist in the tree
        return find_lca(root, n1, n2)                           # then we calculate its LCA
    else :
        return None                 # otherwise we give answer None



def print_output(lca, n1, n2):
    """Prints LCA of two numbers with a proper message if it exists"""
    if lca == None:
        print("\nElement does not exist in tree.\n")
    else:
        print(f"\nlca({n1}, {n2}) = {lca.data}\n")


#============================= DRIVER CODE =============================
if __name__ == "__main__":

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    """
            1
           / \ 
          2   3
         / \  /\
        4  5 6  7
    """

      
    lca = lowest_common_ancestor_binary_tree(root, 4, 5)
    print_output(lca, 4, 5)
    lca = lowest_common_ancestor_binary_tree(root, 2, 5)
    print_output(lca, 2, 5)
    lca = lowest_common_ancestor_binary_tree(root, 4, 2)
    print_output(lca, 4, 2)
    

# OTHER EXAMPLES
    
    """lca = lowest_common_ancestor_binary_tree(root, 4, 7)
    print_output(lca, 4, 7)
    lca = lowest_common_ancestor_binary_tree(root, 2, 3)
    print_output(lca, 2, 3)
    lca = lowest_common_ancestor_binary_tree(root, 2, 1)
    print_output(lca, 2, 1)"""

    """lca = lowest_common_ancestor_binary_tree(root, 1, 8)
    print_output(lca, 1, 8)
    lca = lowest_common_ancestor_binary_tree(root, 1, 1)
    print_output(lca, 1, 1)
    lca = lowest_common_ancestor_binary_tree(root, 2, 6)
    print_output(lca, 2, 6)"""
    
    """lca = lowest_common_ancestor_binary_tree(root, 9, 8)
    print_output(lca, 9, 8)
    lca = lowest_common_ancestor_binary_tree(root, -1, 1)
    print_output(lca, -1, 1)
    lca = lowest_common_ancestor_binary_tree(root, -5, -6)
    print_output(lca, -5, -6)"""
