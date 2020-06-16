/*
Print all the jumping numbers smaller than or equal to x

For eg:
x = 15

Output: 0 1 2 3 4 5 6 7 8 9 10 12

Note: A number is called as a jumping number if all adjacent digits in it differ by 1. The difference between '9' and '0'
is not considered as 1.
*/

#include<iostream>
#include<queue>

using namespace std;

void bfs(int x, int num) 
{ 
    queue<int> q; 
    q.push(num); 
  
    while (!q.empty()) { 
        num = q.front(); 
        q.pop(); 
  
        if (num <= x) { 
            cout << num << " "; 
            int last_dig = num % 10; 
  
            if (last_dig == 0) 
                q.push((num * 10) + (last_dig + 1)); 
  
            else if (last_dig == 9) 
                q.push((num * 10) + (last_dig - 1)); 

            else { 
                q.push((num * 10) + (last_dig - 1)); 
                q.push((num * 10) + (last_dig + 1)); 
            } 
        } 
    } 
} 
 
int main() 
{ 
    int x; 
    cin>>x;
    cout << 0 << " "; 
    for (int i = 1; i <= 9 && i <= x; i++) 
        bfs(x, i);
    return 0; 
} 