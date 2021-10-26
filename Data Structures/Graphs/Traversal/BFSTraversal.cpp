/*BFS Traversal of Graph using Adjacency List 
Representation*/

#include<iostream>
using namespace std;

struct node
{
    node *next;
    int vertex;
};
class graph
{
    node *G[20];
    int visited[20];
    int n;
    public:
    void create();
    void insert(int,int);
    void BFS_List(int);
};
class queue
{
    int data[30];
    int r,f;
    public:
    queue()
    {
        r=f=-1;
    }
    int empty()
    {
        if(r==-1)
        return 1;
        return 0;
    }
    void insert(int x)
    {
        if(empty())
        r=f=0;
        else
        r=r+1;
        data[r]=x;
    }
    int Delete()
    {
        int x=data[f];
        if(r==f)
        r=f=-1;
        else
        f=f+1;
        return x;
    }
};
void graph::create()
{
    int i,vi,vj,e,n;
    cout<<"\nEnter no. of vertices:";
    cin>>n;
    for(i=1;i<=n;i++)
    G[i]=NULL;
    visited[i]=0;
    cout<<"\nEnter no. of edges:";
    cin>>e;
    for(i=1;i<=e;i++)
    {
        cout<<"\nEnter an edge:";
        cin>>vi>>vj;
        insert(vi,vj);
        insert(vj,vi);
    }
}
void graph::insert(int vi, int vj)
{
    node *p,*q;
    q=new node;
    q->vertex=vj;
    q->next=NULL;
    if(G[vi]==NULL)
    {G[vi]=q;}
    else 
    {
    p=G[vi];
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
}

void graph::BFS_List(int v)
{
    int i,v2;
    queue q;
    node *p;
    q.insert(v);
    cout<<"\n Visit"<<v;
    visited[v]=1;
    while(!q.empty())
    {
        v=q.Delete();
        for(p=G[v];p!=NULL;p=p->next)
        {
            v2=p->vertex;
            if(!visited[v2])
            {
                q.insert(v2);
                visited[v2]=1;
                cout<<"\nvisit"<<v2;
            }
        }
    }
}
int main()
{
    graph t;
    t.create();
    t.BFS_List(1);
}
