#include<queue>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(90);
    pq.push(20);
    pq.push(40);
    pq.push(10);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
