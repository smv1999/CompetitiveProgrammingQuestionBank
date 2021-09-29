'''
8 PUZZLE PROBLEM SOLVING USING BREADTH FIRST SEARCH

An instance of the n-puzzle game consists of a board holding n^{2}-1 
distinct movable tiles, plus an empty space. The tiles are numbers from 
the set 1,..,n^{2}-1. For any such board, the empty space may be legally 
swapped with any tile horizontally or vertically adjacent to it. In this 
assignment, the blank space is going to be represented with the number 0. 
Given an initial state of the board, the combinatorial search problem is 
to find a sequence of moves that transitions this state to the goal state; 
that is, the configuration with all tiles arranged in ascending order 
0,1,..,n^{2}-1.

So, this is the goal state that we want to reach:
[1, 2, 3]
[8, 0, 4]
[7, 6, 5] 

The search space is the set of all possible states reachable from the 
initial state. The blank space may be swapped with a component in one of 
the four directions {‘Up’, ‘Down’, ‘Left’, ‘Right’}, one move at a time.

Algorithm Review:
The search begins by visiting the root node of the search tree, given by 
the initial state. Among other book-keeping details, three major things 
happen in sequence in order to visit a node:
-First, we remove a node from the frontier set.
-Second, we check the state against the goal state to determine if a 
 solution has been found.
-Finally, if the result of the check is negative, we then expand the node. 
 To expand a given node, we generate successor nodes adjacent to the current 
 node, and add them to the frontier set. Note that if these successor nodes 
 are already in the frontier, or have already been visited, then they should 
 not be added to the frontier again.

'''

# importing the necessary libraries
from time import time
from queue import Queue

# creating a class Puzzle
class Puzzle:
    # setting the goal state of 8-puzzle 
    goal_state=[1,2,3,8,0,4,7,6,5]
    num_of_instances=0
    # constructor to initialize the class members
    def __init__(self,state,parent,action):
        self.parent=parent
        self.state=state
        self.action=action
        
        # incrementing the number of instance by 1
        Puzzle.num_of_instances+= 1
   
    # function used to display a state of 8-puzzle
    def __str__(self):
        return str(self.state[0:3])+'\n'+str(self.state[3:6])+'\n'+str(self.state[6:9])

    # method to compare the current state with the goal state
    def goal_test(self):
        # including a condition to compare the current state with the goal state
        if Puzzle.goal_state == self.state:
            return True
        else:
            return False
    
    # static method to find the legal action based on the current board position
    @staticmethod
    def find_legal_actions(i,j):
        legal_action = ['U', 'D', 'L', 'R']
        if i == 0:  
            # if row is 0 in board then up is disabled
            legal_action.remove('U')
        elif i == 2:  
            # if row is 2 in board then down is disabled
            legal_action.remove('D')
        if j == 0: 
            # if column is 0 in board then left is disabled
            legal_action.remove('L')
        elif j == 2:
            # if column is 2 in board then right is disabled
            legal_action.remove('R')
        return legal_action

    # method to generate the child of the current state of the board
    def generate_child(self):
        # creating an empty list
        children=[]
        x = self.state.index(0)
        i = int(x / 3)
        j = int(x % 3)
        # calling the method to find the legal actions based on i and j values
        legal_actions = self.find_legal_actions(i, j)

        # iterating over all legal actions 
        for action in legal_actions:
            new_state = self.state.copy()
            # if the legal action is UP
            if action is 'U':
                # swapping between current index of 0 with its up element on the board
                new_state[x], new_state[x-3] = new_state[x-3], new_state[x]
            elif action is 'D':
                # swapping between current index of 0 with its down element on the board
                new_state[x], new_state[x+3] = new_state[x+3], new_state[x]
            elif action is 'L':
                # swapping between the current index of 0 with its left element on the board
                new_state[x], new_state[x-1] = new_state[x-1], new_state[x]
            elif action is 'R':
                # swapping between the current index of 0 with its right element on the board
                new_state[x], new_state[x+1] = new_state[x+1], new_state[x]
            children.append(Puzzle(new_state,self,action))
        # returning the children
        return children
    # method to find the solution
    def find_solution(self):
        solution = []
        all_states = []
        solution.append(self.action)
        all_states.append(self)
        path = self
        while path.parent != None:
            path = path.parent
            solution.append(path.action)
            all_states.append(path)
        solution = solution[:-1]
        solution.reverse()
        all_states.reverse()
        
        print("\nAll states: ")
        for i in all_states:
          print(i, "\n")
        return solution
    
# method for breadth first search
# passing the initial_state as parameter to the breadth_first_search method 
def breadth_first_search(initial_state):
    start_node = Puzzle(initial_state, None, None)
    print("Initial state:")
    print(start_node)
    if start_node.goal_test():
        return start_node.find_solution()
    q = Queue()
    # putting start_node into the Queue
    q.put(start_node)
    # creating an empty list of explored nodes
    explored=[]
    # iterating the queue until empty, using the empty() method of Queue
    while not(q.empty()):
        # getting the current node of a queue, using the get() method of Queue
        node=q.get()
        # append the state of node in the explored list as node.state
        explored.append(node.state)
        # calling the generate_child method to generate the child nodes of current node
        children = node.generate_child()
        # iterating over each child node in children
        for child in children:
            if child.state not in explored:
                if child.goal_test():
                    return child.find_solution()
                q.put(child)
    return

# start executing the 8-puzzle with setting up the initial state
# here we have considered 3 initial state intitalized using state variable
state=[1, 3, 4,
        8, 6, 2,
        7, 0, 5]
# initializing the num_of_instances to zero
Puzzle.num_of_instances = 0
# setting t0 to current time
t0 = time()
bfs = breadth_first_search(state)
# getting the time t1 after executing the breadth_first_search method
t1 = time() - t0
print('BFS:', bfs)
print('space:',Puzzle.num_of_instances)
print('time:',t1)
print()
print('------------------------------------------')  

'''
Sample working:
    
Initial state:
[1, 3, 4]
[8, 6, 2]
[7, 0, 5]

All states: 
[1, 3, 4]
[8, 6, 2]
[7, 0, 5] 

[1, 3, 4]
[8, 0, 2]
[7, 6, 5] 

[1, 3, 4]
[8, 2, 0]
[7, 6, 5] 

[1, 3, 0]
[8, 2, 4]
[7, 6, 5] 

[1, 0, 3]
[8, 2, 4]
[7, 6, 5] 

[1, 2, 3]
[8, 0, 4]
[7, 6, 5] 

BFS: ['U', 'R', 'U', 'L', 'D']
space: 66
time: 0.0

Initial state:
[2, 8, 1]
[0, 4, 3]
[7, 6, 5]

All states: 
[2, 8, 1]
[0, 4, 3]
[7, 6, 5] 

[0, 8, 1]
[2, 4, 3]
[7, 6, 5] 

[8, 0, 1]
[2, 4, 3]
[7, 6, 5] 

[8, 1, 0]
[2, 4, 3]
[7, 6, 5] 

[8, 1, 3]
[2, 4, 0]
[7, 6, 5] 

[8, 1, 3]
[2, 0, 4]
[7, 6, 5] 

[8, 1, 3]
[0, 2, 4]
[7, 6, 5] 

[0, 1, 3]
[8, 2, 4]
[7, 6, 5] 

[1, 0, 3]
[8, 2, 4]
[7, 6, 5] 

[1, 2, 3]
[8, 0, 4]
[7, 6, 5] 

BFS: ['U', 'R', 'R', 'D', 'L', 'L', 'U', 'R', 'D']
space: 591
time: 0.0030422210693359375

Initial state:
[2, 8, 1]
[4, 6, 3]
[0, 7, 5]

All states: 
[2, 8, 1]
[4, 6, 3]
[0, 7, 5] 

[2, 8, 1]
[4, 6, 3]
[7, 0, 5] 

[2, 8, 1]
[4, 0, 3]
[7, 6, 5] 

[2, 8, 1]
[0, 4, 3]
[7, 6, 5] 

[0, 8, 1]
[2, 4, 3]
[7, 6, 5] 

[8, 0, 1]
[2, 4, 3]
[7, 6, 5] 

[8, 1, 0]
[2, 4, 3]
[7, 6, 5] 

[8, 1, 3]
[2, 4, 0]
[7, 6, 5] 

[8, 1, 3]
[2, 0, 4]
[7, 6, 5] 

[8, 1, 3]
[0, 2, 4]
[7, 6, 5] 

[0, 1, 3]
[8, 2, 4]
[7, 6, 5] 

[1, 0, 3]
[8, 2, 4]
[7, 6, 5] 

[1, 2, 3]
[8, 0, 4]
[7, 6, 5] 

BFS: ['R', 'U', 'L', 'U', 'R', 'R', 'D', 'L', 'L', 'U', 'R', 'D']
space: 2956
time: 0.03542494773864746

------------------------------------------

'''
