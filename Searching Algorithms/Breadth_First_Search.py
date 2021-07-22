'''
Aim: To implement breadth first search.

''' 

#a key-value pair represent a vertex and all it's outward edges.
adjacent = {}
#stores the list of vertex.
Vertex = []
# a key-value pair represents a vertex and its level.
# level of the root node is zero.
level = {}
# a key-value pair represents a vertex and its parent.
parent = {}

def initalizeVertex():
    n = int(input('Enter the no. of vertices:\n'))
    print("\nEnter the vertices:")
    for i in range(n):
        vertex = input()
        Vertex.append(vertex)
        adjacent[vertex] = []

def initalizeUndirectedEdges():
    n = int(input("Enter the no. of edges:\n"))
    print("Enter the space seperated edges:")
    for i in range(n):
        a,b = input().split()
        adjacent[a].append(b)
        adjacent[b].append(a)

def initalizeDirectedEdges():
    n = int(input("Enter the no. of edges:\n"))
    print("\nEnter the space seperated edges:")
    for i in range(n):
        a,b = input().split()
        adjacent[a].append(b)    

def showVertex():
    print('The vertices are: ')
    print(Vertex)
    print('\n')

def showEdges():
    print('The dictionary of edges are: ')
    print(adjacent)
    print('\n')

def bfs():
    frontier = []
    neighbour = []
    start = input('Enter the first node:\n')    
    level[start] = 0
    parent[start] = None
    level_no = 1
    frontier.append(start)

    while len(frontier):
        neighbour = []
        for u in frontier:
            for v in adjacent[u]:
                if v not in level.keys():
                    level[v] = level_no
                    parent[v] = u
                    neighbour.append(v)
        frontier = neighbour.copy()
        level_no +=1    

# program starts here.

initalizeVertex()
initalizeUndirectedEdges()  
#showVertex()
#showEdges()
print('\nImplementing BFS!\n')
bfs()
print(level)

'''

Sample Input:

Enter the no. of vertices:
3

Enter the vertices:

1

2

3

Enter the no. of edges:
2

Enter the space seperated edges:

2 3

1 3

Implementing BFS!

Enter the first node.
1

Sample Output:
    
{'1': 0, '3': 1, '2': 2}

COMPLEXITY:
    
     Time Complexity: O(V+E)
                      V is the number of vertices and E is the number of edges
     Space Complexity: O(V)
                       V is the number of vertices

'''  