#include <bits/stdc++.h>

/*
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example:
Input: LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
*/

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}


void displayList(Node *head)
{
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}

// main function for reversing the doubly linked list

/*
Approch:
Simply just keep track of the previous node
and the next node. 

Almost similar to the singly linked list you have an extra pointer
as prev to take care of 
*/
Node* reverseDLL(Node * head)
{
    Node* temp = NULL;
    Node* curr = head;
    while(curr){
        temp = curr->prev;
        curr->prev=curr->next;
        curr->next = temp;
        curr=curr->prev;
    }
    
    if(temp){
        head= temp->prev;
    }
    
    return head;
}



int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    head=reverseDLL(head);
	    
	    
	    displayList(head);
	    
	    cout<<endl;
	}
	return 0;
}

