#include <bits/stdc++.h>
using namespace std;
int vertices;
#define INF INT_MAX
template <class T>
//----------structure for a node of linked list------------//
struct node
{
    T val;
    node<T> *next;
};
template <class T>
//------------------custom linked list---------------------//
class List
{
public:
    node<T> *head;
    //-------------constructor to initialize list------------------//
    List()
    {
        head = NULL;
    }
    //---------to insert from front and use list as a stack----------//
    void insertFront(T val)
    {
        node<T> *temp = new node<T>;
        temp->val = val;
        temp->next = NULL;
        temp->next = head;
        head = temp;
    }
    //-----to insert in sorted order to use list as priority queue----//
    void insertSorted(T val)
    {
        node<T> *temp = new node<T>();
        if (!head or head->val >= val)
        {
            temp->val = val;
            temp->next = head;
            head = temp;
            return;
        }
        temp = head;
        while (temp->next and temp->next->val < val)
        {
            temp = temp->next;
        }
        node<T> *insertPtr = new node<T>();
        insertPtr->val = val;
        insertPtr->next = temp->next;
        temp->next = insertPtr;
    }
    //--------deleting(shifting) head of the list------------//
    void deleteHead()
    {
        head = head->next;
    }
    //--------to get the pointer to head of the list-----------//
    node<T> *Head()
    {
        return head;
    }
    //-------------to check if the list is empty---------------//
    bool isEmpty()
    {
        return head == NULL;
    }
    //-------------to check if a value exists in the list------------//
    bool Find(T val)
    {
        node<T> *temp = head;
        for (; temp; temp = temp->next)
        {
            if (temp->val == val)
                return true;
        }
        return false;
    }
    //--------------to get the size of the list------------------//
    int Size()
    {
        int length = 0;
        node<T> *temp = head;
        for (; temp; temp = temp->next)
        {
            length++;
        }
        return length;
    }
};
template <typename F, typename S>
//--------structure to define one node of the adjacency list---------------//
struct adj
{
    F dest;
    S weight;
};
template <class T>
//----------------------graph data structure---------------------------//
class graph
{
    T val;
    int numOfVertices;
    List<adj<int, int>> *adjLists;
    bool *visited;

public:
    //------------constructor to initialize graph----------------//
    graph()
    {
        numOfVertices = vertices;
        adjLists = new List<adj<int, int>>[vertices];
        visited = new bool[vertices];
    }
    //------------to add edge in adjacency list of corresponding nodes-----------//
    void addEdge(int src, int dest, int weight)
    {
        adjLists[src].insertFront({dest, weight});
    }
   
    //-----------function to implement dijkstra's algorithm--------------//
    //----to find shortest path form one nodes to all reachable nodes----//
    void dijkstra(T start)
    {
        cout << "DIJKSTRA'S Algorithm\n";
        int dist[vertices];
        for (int i = 0; i < vertices; i++)
        {
            dist[i] = INF;
        }
        dist[start] = 0;
        List<int> pQueue;
        pQueue.insertSorted(start);
        while (!pQueue.isEmpty())
        {
            auto minn = (pQueue.Head())->val;
            pQueue.deleteHead();
            List<adj<int, int>> adjList = adjLists[minn];
            auto it = adjList.Head();
            for (; it; it = it->next)
            {
                if (dist[(it->val).dest] > dist[minn] + (it->val).weight)
                {
                    dist[(it->val).dest] = dist[minn] + (it->val).weight;
                    pQueue.insertSorted((it->val).dest);
                }
            }
        }
        cout << "Minimum path from " << start << " to nodes: \n";
        for (int i = 0; i < vertices; i++)
        {
            if (i != start)
                cout << start << " to " << i << ", Cost: " << dist[i] << endl;
        }
        cout << "\n";
    }
    //------to create diff list(to be used in prim's MST algorithm)-------//
    List<int> difference(List<int> first, List<int> second)
    {
        auto it = first.Head();
        List<int> result;
        for (; it; it = it->next)
        {
            if (!second.Find(it->val))
                result.insertFront(it->val);
        }
        return result;
    }
    //-------------function to compare 2 linked lists-------------------//
    //-------------returns true if both lists are equal---------------//
    bool compare(List<int> first, List<int> second)
    {
        if (first.Size() != second.Size())
            return false;
        auto it = first.Head();
        for (; it; it = it->next)
        {
            if (!second.Find(it->val))
                return false;
        }
        return true;
    }
};


int main()
{
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    int n = vertices;
    int start;
    bool isUndirected = false;
    char choice;
    cout << "Is graph undirected(y / n)? ";
    cin >> choice;
    if (choice == 'y')
        isUndirected = true;
    graph<int> g;
    cout << "\n\n--------------Make the graph--------------\n\n";
    while (edges--)
    {
        int src, dest, weight;
        cout << "Enter source: ";
        cin >> src;
        cout << "Enter the destination: ";
        cin >> dest;
        cout << "Enter the weight of the edge connecting them: ";
        cin >> weight;
        g.addEdge(src, dest, weight);
        if (isUndirected)
            g.addEdge(dest, src, weight);
        cout << "\n";
    }
    cout << "Enter the source node for the algorithm: ";
    cin >> start;
    g.dijkstra(start);
    return 0;
}