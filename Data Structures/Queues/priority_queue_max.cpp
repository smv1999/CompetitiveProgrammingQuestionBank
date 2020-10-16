#include <queue>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(90);
    pq.push(20);
    pq.push(40);
    pq.push(10);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

}