class Node :
    """Class to define tree nodes, 
        this has a value attribute to store the value, and 
        left and right attributes to point to the left and right child respectively"""
    def __init__(self, value):
        self.value = value
        self.right = None
        self.left = None
    
def expression_tree_evaluation (node):
    """A recursive function which evaluates the expression subtree passed to it
        and returns the evaluated value"""
    if node == None:    # Node doesn't exist
        return 0
    if node.left == None and node.right == None:    # leaf node containing an operand
        return node.value
    
    # node is an operator
    left_child = expression_tree_evaluation(node.left)
    right_child = expression_tree_evaluation (node.right)

    return eval(str(left_child)+node.value+str(right_child))


# DRIVER CODE

if __name__ == '__main__':
    # Expression in the example : (5*4)+(100-2)
    root = Node('+')
    root.left = Node('*')
    root.left.left = Node('5')
    root.left.right = Node('4')
    root.right = Node('-')
    root.right.left = Node('100')
    root.right.right = Node('20')
    print (expression_tree_evaluation(root))
