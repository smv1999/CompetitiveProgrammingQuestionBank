'''
WATER JUG PROBLEM USING BFS AND DFS

Given Problem: You are given a 'm' liter jug and a 'n' liter jug where 
'0<m<n'. Both the jugs are initially empty. The jugs don't have markings 
to allow measuring smaller quantities. You have to use the jugs to measure 
'd' liters of water where 'd<n'. Determine the minimum no of operations to 
be performed to obtain 'd' liters of water in one of jug.

The aim is to solve this problem using BFS or DFS as per user's choice.

'''
import collections

# This method return a key value for a given node. 
# Node is a list of two integers representing current state of the jugs
def get_index(node):
    return pow(7, node[0]) * pow(5, node[1])

#This method accepts an input for asking the choice for type of searching required i.e. BFS or DFS.
#Method return True for BFS, False otherwise
def get_search_type():
    s = input("Enter 'b' for BFS, 'd' for DFS: ")
    s = s.lower()
    
    while s!='b' and s!='d':
        s = input("The input is not valid! Enter 'b' for BFS, 'd' for DFS: ")
        s = s[0].lower()  
    return s=='b'

#This method accept volumes of the jugs as an input from the user.
#Returns a list of two integers representing volumes of the jugs.
def get_jugs():
    print("Receiving the volume of the jugs...")
    jugs = []
    
    temp = int(input("Enter first jug volume (>1): "))
    while temp < 1:
        temp = int(input("Enter a valid amount (>1): "))     
    jugs.append(temp)
    
    temp = int(input("Enter second jug volume (>1): "))
    while temp < 1:
        temp = int(input("Enter a valid amount (>1): "))     
    
    jugs.append(temp)
    
    return jugs

#This method accepts the desired amount of water as an input from the user whereas 
#the parameter jugs is a list of two integers representing volumes of the jugs
#Returns the desired amount of water as goal
def get_goal(jugs):
    
    print("Receiving the desired amount of the water...")

    max_amount = max(jugs)
    s = "Enter the desired amount of water (1 - {0}): ".format(max_amount)
    goal_amount = int(input(s))
    while goal_amount not in range(1, max_amount+1):
        goal_amount = int(input("Enter a valid amount (1 - {0}): ".format(max_amount)))
    
    return goal_amount

#This method checks whether the given path matches the goal node.
#The path parameter is a list of nodes representing the path to be checked
#The goal_amount parameter is an integer representing the desired amount of water
def is_goal(path, goal_amount):
    
    print("Checking if the goal is achieved...")
    
    return path[-1][0] == goal_amount

#This method validates whether the given node is already visited.
#The parameter node is a list of two integers representing current state of the jugs
#The parameter check_dict is a dictionary storing visited nodes
def been_there(node, check_dict):
    
    print("Checking if {0} is visited before...".format(node))

    return check_dict.get(get_index(node))

#This method returns the list of all possible transitions
#The parameter jugs is a list of two integers representing volumes of the jugs
#The parameter path is a list of nodes represeting the current path
#The parameter check_dict is a dictionary storing visited nodes
def next_transitions(jugs, path, check_dict):
    
    print("Finding next transitions and checking for the loops...")
    
    result = []
    next_nodes = []
    node = []
    
    a_max = jugs[0]
    b_max = jugs[1]
    
    a = path[-1][0]  
    b = path[-1][1]

    #Operation Used in Water Jug problem
    # 1. fill in the first jug
    node.append(a_max)
    node.append(b)
    if not been_there(node, check_dict):
        next_nodes.append(node)
    node = []

    # 2. fill in the second jug
    node.append(a)
    node.append(b_max)
    if not been_there(node, check_dict):
        next_nodes.append(node)
    node = []

    # 3. second jug to first jug
    node.append(min(a_max, a + b))
    node.append(b - (node[0] - a))  # b - ( a' - a)
    if not been_there(node, check_dict):
        next_nodes.append(node)
    node = []

    # 4. first jug to second jug
    node.append(min(a+b, b_max))
    node.insert(0, a - (node[0] - b))
    if not been_there(node, check_dict):
        next_nodes.append(node)
    node = []

    # 5. empty first jug
    node.append(0)
    node.append(b)
    if not been_there(node, check_dict):
        next_nodes.append(node)
    node = []

    # 6. empty second jug
    node.append(a)
    node.append(0)
    if not been_there(node, check_dict):
        next_nodes.append(node)

    # create a list of next paths
    for i in range(0, len(next_nodes)):
        temp = list(path)
        temp.append(next_nodes[i])
        result.append(temp)

    if len(next_nodes) == 0:
        print("No more unvisited nodes...\nBacktracking...")
    else:
        print("Possible transitions: ")
        for nnode in next_nodes:
            print(nnode)
    return result

# This method returns a string explaining the transition from old state/node to new state/node
# The parameter old is a list representing old state/node
# The parameter new is a list representing new state/node
# The parameter jugs is a list of two integers representing volumes of the jugs
     
def transition(old, new, jugs):
    
    #Get the amount of water from old state/node for first Jug
    a = old[0]
    #Get the amount of water from old state/node for second Jug
    b = old[1]
    #Get the amount of water from new state/node for first Jug
    a_prime = new[0]
    #Get the amount of water from new state/node for second Jug
    b_prime = new[1]
    #Get the amount of water from jugs representing volume for first Jug
    a_max = jugs[0]
    #Get the amount of water from jugs representing volume for second Jug
    b_max = jugs[1]

    if a > a_prime:
        if b == b_prime:
            return "Clear {0}-liter jug:\t\t\t".format(a_max)
        else:
            return "Pour {0}-liter jug into {1}-liter jug:\t".format(a_max, b_max)
    else:
        if b > b_prime:
            if a == a_prime:
                return "Clear {0}-liter jug:\t\t\t".format(b_max)
            else:
                return "Pour {0}-liter jug into {1}-liter jug:\t".format(b_max, a_max)
        else:
            if a == a_prime:
                return "Fill {0}-liter jug:\t\t\t".format(b_max)
            else:
                return "Fill {0}-liter jug:\t\t\t".format(a_max)
            
#This method prints the goal path
#The path is a list of nodes representing the goal path
#The jugs is a list of two integers representing volumes of the jugs
     
def print_path(path, jugs):
    
    print("Starting from:\t\t\t\t", path[0])
    for i in  range(0, len(path) - 1):
        print(i+1,":", transition(path[i], path[i+1], jugs), path[i+1])

#This method searches for a path between starting node and goal node
# The parameter starting_node is a list of list of two integers representing initial state of the jugs
#The parameter jugs a list of two integers representing volumes of the jugs
#The parameter goal_amount is an integer represting the desired amount
#The parameter check_dict is  a dictionary storing visited nodes
#The parameter is_breadth is implements BFS, if True; DFS otherwise
def search(starting_node, jugs, goal_amount, check_dict, is_breadth):
    
    if is_breadth:
        print("Implementing BFS...")
    else:
        print("Implementing DFS...")

    goal = []
    accomplished = False
    
    q = collections.deque()
    q.appendleft(starting_node)
    
    while len(q) != 0:
        path = q.popleft()
        check_dict[get_index(path[-1])] = True
        if len(path) >= 2:
            print(transition(path[-2], path[-1], jugs), path[-1])
        if is_goal(path, goal_amount):
            accomplished = True
            goal = path
            break

        next_moves = next_transitions(jugs, path, check_dict)
        for i in next_moves:
            if is_breadth:
                q.append(i)
            else:
                q.appendleft(i)

    if accomplished:
        print("The goal is achieved\nPrinting the sequence of the moves...\n")
        print_path(goal, jugs)
    else:
        print("Problem cannot be solved.")

if __name__ == '__main__':
    starting_node = [[0, 0]]
    jugs = get_jugs()
    goal_amount = get_goal(jugs)
    check_dict = {}
    is_breadth = get_search_type()
    search(starting_node, jugs, goal_amount, check_dict, is_breadth)  

'''
Sample woking:

Receiving the volume of the jugs...

Enter first jug volume (>1): 3

Enter second jug volume (>1): 4
Receiving the desired amount of the water...

Enter the desired amount of water (1 - 4): 2

Enter 'b' for BFS, 'd' for DFS: b
Implementing BFS...
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 0] is visited before...
Checking if [0, 4] is visited before...
Checking if [0, 0] is visited before...
Checking if [0, 0] is visited before...
Checking if [0, 0] is visited before...
Checking if [0, 0] is visited before...
Possible transitions: 
[3, 0]
[0, 4]
Fill 3-liter jug:			 [3, 0]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 0] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 0] is visited before...
Checking if [0, 3] is visited before...
Checking if [0, 0] is visited before...
Checking if [3, 0] is visited before...
Possible transitions: 
[3, 4]
[0, 3]
Fill 4-liter jug:			 [0, 4]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 4] is visited before...
Checking if [0, 4] is visited before...
Checking if [3, 1] is visited before...
Checking if [0, 4] is visited before...
Checking if [0, 4] is visited before...
Checking if [0, 0] is visited before...
Possible transitions: 
[3, 4]
[3, 1]
Fill 4-liter jug:			 [3, 4]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 4] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 4] is visited before...
Checking if [0, 4] is visited before...
Checking if [3, 0] is visited before...
No more unvisited nodes...
Backtracking...
Pour 3-liter jug into 4-liter jug:	 [0, 3]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 3] is visited before...
Checking if [0, 4] is visited before...
Checking if [3, 0] is visited before...
Checking if [0, 3] is visited before...
Checking if [0, 3] is visited before...
Checking if [0, 0] is visited before...
Possible transitions: 
[3, 3]
Fill 3-liter jug:			 [3, 4]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 4] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 4] is visited before...
Checking if [0, 4] is visited before...
Checking if [3, 0] is visited before...
No more unvisited nodes...
Backtracking...
Pour 4-liter jug into 3-liter jug:	 [3, 1]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 1] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 1] is visited before...
Checking if [0, 4] is visited before...
Checking if [0, 1] is visited before...
Checking if [3, 0] is visited before...
Possible transitions: 
[0, 1]
Fill 3-liter jug:			 [3, 3]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 3] is visited before...
Checking if [3, 4] is visited before...
Checking if [3, 3] is visited before...
Checking if [2, 4] is visited before...
Checking if [0, 3] is visited before...
Checking if [3, 0] is visited before...
Possible transitions: 
[2, 4]
Clear 3-liter jug:			 [0, 1]
Checking if the goal is achieved...
Finding next transitions and checking for the loops...
Checking if [3, 1] is visited before...
Checking if [0, 4] is visited before...
Checking if [1, 0] is visited before...
Checking if [0, 1] is visited before...
Checking if [0, 1] is visited before...
Checking if [0, 0] is visited before...
Possible transitions: 
[1, 0]
Pour 3-liter jug into 4-liter jug:	 [2, 4]
Checking if the goal is achieved...
The goal is achieved
Printing the sequence of the moves...

Starting from:				             [0, 0]
1 : Fill 3-liter jug:			         [3, 0]
2 : Pour 3-liter jug into 4-liter jug:	 [0, 3]
3 : Fill 3-liter jug:			         [3, 3]
4 : Pour 3-liter jug into 4-liter jug:	 [2, 4]

'''          