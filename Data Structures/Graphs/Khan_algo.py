'''
to find whether a graph has a cycle or not
if not then print the topological sorting for them
'''
from collections import defaultdict


class solution:

    def __init__(self, vrt):
        self.vrt = vrt
        self.graph = defaultdict(list)

    def edges(self, u, v):
        global vertex,indegree
        self.graph[u].append(v)
        if u not in indegree.keys():
            indegree[u]=0
        if v not in indegree.keys():
            indegree[v]=1

        else:
            indegree[v]+=1
        vertex.add(u)
        vertex.add(v)

    def topological(self):
        global vertex,indegree
        q=[]
        count=0
        for i in vertex:
            if indegree[i]==0:
                q.append(i)

        result=[]

        while q:

            current=q.pop(0)
            count+=1
            result.append(current)



            for i in self.graph[current]:
                indegree[i]-=1
                if indegree[i]==0:
                    q.append(i)

        if count!=len(vertex):
            print("there is no topolical string ")
        else:
            print(result)



        return





indegree=defaultdict()
vertex=set()

g =solution(6)
g.edges(5, 2);
g.edges(5, 0);
g.edges(4, 0);
g.edges(4, 1);
g.edges(2, 3);
g.edges(3, 1)
print(indegree)
print(vertex)

g.topological()
