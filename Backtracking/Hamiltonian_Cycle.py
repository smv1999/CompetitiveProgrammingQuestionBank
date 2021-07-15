'''
Hamiltonian Path: a Hamiltonian path (or traceable path) is a path
    in an undirected or directed graph that visits each vertex exactly
    once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian
    path that is a cycle.
Aim: To determine the existance of a Hamiltonian Cycle in the provided
        undirected graph and return the path if such path exist.
        The nodes are numbered from 1 to N.

'''

from collections import defaultdict


def Move_next_node(n, graph, pos, ans):
    # Base Case: If all the node is visited:
    if pos == n:

        # Check wether the last node and the first node are
        # connected in order to form a Cycle
        if ans[0] in graph[ans[-1]]:
            return ans + [ans[0]]

        return False

    current = ans[-1]

    # Check for each of the adjoining vertices
    for i in graph[current]:

        # Check wether the node is already visited or not
        if i not in ans:
            ans += [i]
            temp = Move_next_node(n, graph, pos + 1, ans)
            if temp:
                return temp

            ans.pop()

    return False


def Hamiltonial_Cycle(n, graph):
    # To keep a track of already visited node and the answer
    # We will start exploring the graph from Vertex 1
    answer = [1]

    # Start Exploring adjoining node/vertex
    return Move_next_node(n, graph, 1, answer)


# ------------------------DRIVER CODE ------------------------
if __name__ == "__main__":
    n, m = map(int, input("Enter the number of vertex and edges: ").split())
    print("Enter the edges: ")
    graph = defaultdict(list)
    for i in range(m):
        a, b = map(int, input().split())
        graph[a] += [b]
        graph[b] += [a]
    ans = Hamiltonial_Cycle(n, graph)
    if not ans:
        print("Hamiltonian Cycle is not possible in the Given graph")
    else:
        print("Hamiltonian Cycle is possible in the graph")
        print("The path is : ", *ans)

'''

Sample Working:
    
     5----1------2
    /\     \    /
   /  \     \  /
  /    \     \/
 3------6-----4
Enter the number of vertex and edges: 6 8
Enter the edges
5 1
1 2
1 4
5 6
6 4
4 2
3 6
5 3
Hamiltonian Cycle is possible in the graph
The path is :  1 5 3 6 4 2 1
     5----1------2
     \     \
      \     \
       \     \
 3------6-----4
Enter the number of vertex and edges: 6 6
Enter the edges:
5 1
3 6
6 4
1 2
5 6
1 4
Hamiltonian Cycle is not possible in the Given graph

COMPLEXITY:
    
     Time Complexity ->  O(2^N)
     Space Complexity -> O(N)
     
'''