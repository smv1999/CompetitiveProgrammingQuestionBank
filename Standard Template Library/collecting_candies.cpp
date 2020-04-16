/*
Collecting Candies

To find the minimum number of seconds that will be taken to collect the 
candies and place them inside a single box. Where the number of seconds is equivalent
to the number of candies in each individual box.


*/
#include<iostream>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
    priority_queue <int, deque<int>, greater<int> > pq;
    int n,i,min1,min2,sum,sec,e;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        pq.push(e);
    }
    min1=min2=sum=sec=0;
    while(pq.size()>1)
    {
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        pq.pop();
        sum = min1 + min2;
        pq.push(sum);
        sec = sec + sum;
    }
    pq.pop();
    cout<<sec<<endl;
    return 0;
}
