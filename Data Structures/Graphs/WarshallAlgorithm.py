'''
A program for warshall algorithm.It is a shortest path algorithm which is used to find the 
distance from source node,which is the first node,to all the other nodes.
If there is no direct distance between two vertices then it is considered as -1
'''


def warshall(g,ver):
    dist = list(map(lambda i: list(map(lambda j: j, i)), g))
    for i in range(0,ver):
        for j in range(0,ver):
            dist[i][j] = g[i][j]
	#Finding the shortest distance if found
    for k in range(0,ver):
        for i in range(0,ver):
            for j in range(0,ver):
                if dist[i][k] + dist[k][j] < dist[i][j] and  dist[i][k]!=-1 and dist[k][j]!=-1:
                    dist[i][j] = dist[i][k] + dist[k][j]
	#Prnting the complete short distance matrix
    print("The distance matrix is\n")
    for i in range(0,ver):
        for j in range(0,ver):
            if dist[i][j]>=0:
                print(dist[i][j],end=" ")
            else:
                print(-1,end=" ")
        print("\n")
#Driver's code
def main():
    print("Enter number of vertices\n")
    ver=int(input())
    graph=[]
	#Creating the  graph
    print("Enter the graph\n")
    for i in range(ver):
        a =[]
        for j in range(ver):     
            a.append(int(input()))
        graph.append(a)
    warshall(graph,ver)
if __name__=="__main__":
	main()



'''
Time Complexity:O(ver^3)
Space Complexity:O(ver^2)
Input/Output:
Enter number of vertices 
4
Enter the graph
0
8
-1
1
-1
0
1
-1
4
-1
0
-1
-1
2
9
0
The distance matrix is
0 3 -1 1 
-1 0 1 -1 
4 -1 0 -1 
-1 2 3 0 
'''
