"""
Binary trees are a type of data tree data structure in which a node can only have 0,1 or 2 children only.
Linked list is a type of linear data structure in which one object/node along with data, also contains the address of next object/node.
Doubly linked list is a type of linked list in which a node points to both the element before it, and after it.

A binary tree can be converted to a doubly linked list based on in order traversal, where left and right pointers point to prev and next element Eg :-

     10 
    /  \
   12   15
   /\    /
 25 30  36

can be converted to the doubly linked list

25 <-> 12 <-> 30 <-> 10 <-> 36 <-> 15

We have used an iterative approach here, keeping the track of head and tail of the doubly linked list,
recursively solving left subtree, then redirecting the pointers to connect the last element and the current element,
and finally recursively solving the right subtree

"""




class Node :
    """Class, to define node of the binary tree and dll, has data, left, and right as attributes"""
    def  __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

def binary_tree_to_dll(node, head, tail):
    """This function converts a binary tree to a doubly linked list with recursive approach
       input: tree root or node, head and tail pointer of DLL
       returns : the head and tail of the the linked lists 
    """

    if node == None :
        return head, tail
    
    head, tail = binary_tree_to_dll(node.left, head, tail)  # converting the left subtree

    # updating the tail of the list to point towards current node
    if head == None:
        head = node
    else :
        tail.right = node
        node.left = tail
    tail = node         # shifting the tail to the latest node

    head, tail = binary_tree_to_dll(node.right, head, tail)  # converting the right subtree

    return head, tail

def print_list (head):
    """ iterates over the linked list prints the data elements
        input : head of the linked list
        prints the elements, does not return anything
    """
    while head != None:
        print(head.data, end = " ")
        head = head.right


# DRIVER CODE

if __name__ == "__main__":
    
    root = Node(10)
    root.left = Node(12)
    root.right = Node(15)
    root.left.left = Node(25)
    root.left.right = Node(30)
    root.right.left = Node(36)
       

    head, tail = None, None
    head, tail = binary_tree_to_dll(root, head, tail)
    print("\nEquivaltent doubly linked list : ", end="")
    print_list (head)
    print("\n")



    # Extra examples for testing
    """
    root = Node(-5)
    root.left = Node(10)
    root.right = Node(2) 

    # ans : 10 -5 2
    """

    """
    root = Node(3)
    root.left = Node(5)
    root.right = Node (7)
    root.left.left = Node(9)
    root.left.right = Node(11)
    root.right.left = Node(13)
    root.right.right = Node(15)
    root.left.left.left = Node(17)

    # ans : 17 9 5 11 3 13 7 15
    """