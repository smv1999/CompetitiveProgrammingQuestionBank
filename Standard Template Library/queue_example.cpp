/*
Queue example using Standard Template Library

1. Simple Queue
In queue, insertion takes place at the rear of the queue and the
deletion of the element takes place at the front of the queue.

2.Priority Queue
In this type of queue, the elements are pushed in a particular order such as ascending 
or descending.

*/
#include<iostream>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,e;
    queue <int> q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        q.push(e);
    }
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    // priority queue
    priority_queue <int>pq;
    pq.push(10);
    pq.push(200);
    pq.push(30);
    cout<<pq.top()<<endl; //displays the max value
    pq.pop(); //200 is popped
    cout<<pq.top()<<endl; //30
    return 0;
}
