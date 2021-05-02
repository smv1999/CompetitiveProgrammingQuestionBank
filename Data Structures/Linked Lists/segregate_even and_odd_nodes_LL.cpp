/*
Given a link list of size N, modify the list such that all the even numbers appear before all the
odd numbers in the modified list.
The order of appearance of numbers within each segregation should be same as that in the original list.

Example 1:

Input: 
N = 7
Linked List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Example 2:

Input:
N = 4
Linked List = 1 -> 3 -> 5 -> 7

Output: 1 3 5 7

*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


/*
Method followed:
- Use to queues to store even and odd data containing nodes of the List.
- Traverse the LL and populates the queues
- Re-Traverse the Ll emptying the even queue first followed by odd one.
- return head 
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        queue<int> odd;
        queue<int> even;
        Node* curr = head;
        Node* curr2 = head;
        while(curr){
            if(curr->data%2==0){
                even.push(curr->data);
            }else{
                odd.push(curr->data);
            }
            curr=curr->next;
        }
        
        while(!even.empty()){
            curr2->data=even.front();
            curr2=curr2->next;
            even.pop();
        }
        while(!odd.empty()){
            curr2->data=odd.front();
            curr2=curr2->next;
            odd.pop();
        }
        return head;
    }
};



int main() {
    
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
