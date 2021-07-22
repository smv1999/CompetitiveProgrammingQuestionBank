'''
    IMPLEMENTATION OF BINARY SEARCH TREE (BST)
    Binary Search Tree is a special type of binary tree where:
    1. The value of all the nodes in the left sub-tree is less than or equal to the value of the root.
    2. The value of all the nodes in the right sub-tree is greater than value of the root.
    3. This rule will be recursively applied to all the left and right sub-trees of the root.
    This program contains the menu-based implementation of the basic operations on a BST:
    1. Insert Node into BST
    2. Search Node in BST
    3. Delete Node in BST
    4. Print BST (inorder way)
'''


class BSTNode:
    # A Node of the Binary Search Tree
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def insertNode(root, val):
    # Function to insert a node to a BST

    # if the given BST is empty
    if root is None:
        return BSTNode(val)

    # if the value to insert already exists in the tree
    if root.val == val:
        return root

    # if the value to insert should be inserted to the left subtree
    if val < root.val:
        root.left = insertNode(root.left, val)

    # if the value to insert should be inserted to the right subtree
    else:
        root.right = insertNode(root.right, val)

    return root


def searchNode(root, val):
    # Function to search a node in a BST

    # if the BST is empty or if the node doesn't exist
    if root is None:
        return False

    # if the value exists in the BST
    if root.val == val:
        return True

    # if the value might exist in the right subtree
    if val > root.val:
        return searchNode(root.right, val)

    # if the value might exist in the left subtree
    return searchNode(root.left, val)


def inorderSuccessor(node):
    # Function to find the inorder successor of a given node

    curr = node
    # Loop through the BST until a left most node is reached
    while curr.left is not None:
        curr = curr.left
    return curr


def deleteNode(root, val):
    # Function to delete a node in a BST

    # if the BST is empty
    if root is None:
        return root

    # if the node to delete might exist in the left subtree
    if root.val > val:
        root.left = deleteNode(root.left, val)

    # if the node to delete might exist in the right subtree
    elif root.val < val:
        root.right = deleteNode(root.right, val)

    # if the node is found
    else:

        # if the node has one child or no children
        if root.right is None:
            tempNode = root.left
            root = None
            return tempNode

        if root.left is None:
            tempNode = root.right
            root = None
            return tempNode

        # if the node has two children
        tempNode = inorderSuccessor(root.right)
        root.val = tempNode.val
        root.right = deleteNode(root.right, tempNode.val)

    return root


def inorder(root):
    # Function to print the nodes in the BST inorder

    # if the BST is not empty
    if root:
        # visit the left subtree (or leaf)
        inorder(root.left)
        # visit the parent
        print(root.val, end=' ')
        # visit the right subtree (or leaf)
        inorder(root.right)


# A menu based implementation
if __name__ == '__main__':
    bst = None
    op = 1
    while op != 5:
        print()
        print("1: Insert")
        print("2: Search")
        print("3: Delete")
        print("4: Print (Inorder)")
        print("5: Exit")
        print("Enter option: ", end="")

        op = int(input())

        if op == 1:
            print("Enter value to insert: ", end="")
            x = int(input())
            bst = insertNode(bst, x)
            print()

        elif op == 2:
            print("Enter element to search for: ", end="")
            x = int(input())
            if searchNode(bst, x):
                print("The element is present!")
            else:
                print("The element is not present")
            print()

        elif op == 3:
            print("Enter the value to delete: ", end="")
            x = int(input())
            bst = deleteNode(bst, x)
            print()

        elif op == 4:
            if bst:
                inorder(bst)
            else:
                print("Empty BST!")
            print()


'''
    Sample Input/Output:
    1: Insert
    2: Search
    3: Delete
    4: Print (Inorder)
    5: Exit
    Enter option: 1
    Enter value to insert: 5
    1: Insert
    2: Search
    3: Delete
    4: Print (Inorder)
    5: Exit
    Enter option: 2
    Enter element to search for: 5
    The element is present!
    1: Insert
    2: Search
    3: Delete
    4: Print (Inorder)
    5: Exit
    Enter option: 3
    Enter the value to delete: 5
    1: Insert
    2: Search
    3: Delete
    4: Print (Inorder)
    5: Exit
    Enter option: 4
    Empty BST!
    
    Time Complexity:
        Insert: O(n)
        Search: O(n)
        Delete: O(n)
        Print (Inorder): O(n)
    Space Complexity:
        Insert: O(n)
        Search: O(n)
        Delete: O(n)
        Print (Inorder): O(n)
'''