//  Problem Statement: 
//
//  Given an linked list and we have to add a node at the beginning of linked list. 
//  The new node will be added at the beginning of a linked list.
//
//  Example: 
//  Suppose we have an linked list : 50 -> 60
//  Now insert(10)
//  After insertion : 10 -> 50 -> 60

// Solution: 
// step 1. Create a new node for the value that has to be inserted and assign value to it.
// step 2. now point the pointer of new node to the head of singly linked list. 
// step 3: make the new node as our head. 

// as we are doing constant operation 
// Time complexity  --> O( 1 )
// Space complexity --> O(1)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int x){
        data=x;
        next=NULL;
    }
};

node *insertBegin(node *head, int x)
{
    node *temp = new node(x);             // create a new node as temp for the value
    temp->next=head;                      // making temp next as our head
    return temp;                          // finally return
}

void display(node *head){

    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    node *head = new node(50);
    head->next = new node(60);
    cout<<"Linked list before inserting: ";
    display(head);
    cout<<endl;
    head = insertBegin(head, 10);
    cout<<"Linked list after inserting at the beginning: ";
    display(head);


}