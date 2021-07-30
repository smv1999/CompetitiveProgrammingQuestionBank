# Class to build a tree node
class TreeNode:
    # Constructor to create tree node
    def __init__(self, data):
        self.data = data
        self.children = []
        self.parent = None
        
    # Function to add a add in individual node
    def add_child(self, child):
        child.parent = self
        self.children.append(child)
    
    # Function to get a level of the selected node
    def getlevel(self):
        level = 0
        p = self.parent
        while p:
            level += 1
            p = p.parent
        return level
    
    # Print the contructed tree
    def printt(self):
        prefix = (" " * 4 * self.getlevel()) + ("|--" if self.parent else "")
        print(prefix + self.data)
        if self.children:
            for child in self.children:
                child.printt()


# Funcation to build a tree
def build_tree():
    # Taking input dynamically
    print("Do the following given in eg bracket")
    print("\n")
    root = input('Enter a root node element (eg: Food): ')
    root = TreeNode(root)

    print("\n")
    it = input('Enter the value for First child of root node(eg: Italian): ')
    italy = TreeNode(it)
    root.add_child(italy)

    ch = input('Enter the value for Second child of root node(eg: Chinese): ')
    chinese = TreeNode(ch)
    root.add_child(chinese)

    me = input('Enter the value for Third child of root node(eg: Mexican): ')
    mexican = TreeNode(me)
    root.add_child(mexican)

    print("\n")
    pi = input('Enter the value for First child of Italian node(eg: Pizza): ')
    italy.add_child(TreeNode(pi))
    la = input('Enter the value for Second child of Italian node(eg: Lasagna): ')
    italy.add_child(TreeNode(la))
    pis = input(
        'Enter the value for Third child of Italian node(eg: Pistacho): ')
    italy.add_child(TreeNode(pis))

    print("\n")
    no = input('Enter the value for First child of Chineese node(eg: Noodles): ')
    chinese.add_child(TreeNode(no))
    ric = input(
        'Enter the value for Second child of Chineese node(eg: Riceballs): ')
    chinese.add_child(TreeNode(ric))
    fr = input(
        'Enter the value for Third child of Chineese node(eg: Fried Rice): ')
    chinese.add_child(TreeNode(fr))

    print("\n")
    tc = input('Enter the value for First child of Mexican node(eg: Tacos): ')
    mexican.add_child(TreeNode(tc))
    gr = input('Enter the value for Second child of Mexican node(eg: Gyro): ')
    mexican.add_child(TreeNode(gr))
    shw = input(
        'Enter the value for Third child of Mexican node(eg: Shawarma): ')
    mexican.add_child(TreeNode(shw))
    print('\n')
    print("\n")

    return root

    # Static Input sample code
    '''
    def buildtree():
    root = TreeNode('Electronics')

    laptop = TreeNode('Laptop')
    laptop.add_child(TreeNode('Dell'))
    laptop.add_child(TreeNode('Apple'))
    laptop.add_child(TreeNode('Microsoft'))

    mobile = TreeNode('Mobile')
    mobile.add_child(TreeNode('Mi'))
    mobile.add_child(TreeNode('One plus'))
    mobile.add_child(TreeNode('Vivo'))

    tv = TreeNode('TV')
    tv.add_child(TreeNode('Samsung'))
    tv.add_child(TreeNode('LG'))

    root.add_child(laptop)
    root.add_child(mobile)
    root.add_child(tv)

    return root
    '''


if __name__ == "__main__":
    root = build_tree()
    root.printt()
