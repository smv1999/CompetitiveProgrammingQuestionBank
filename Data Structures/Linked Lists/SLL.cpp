/*
An SLL is a type of linked list in which each node consists of only two fields viz., data field and the address field.
The address field is a pointer containing the address of the next node in the list.
*/
#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
};
void printLinkedList(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // allocating three nodes
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next=NULL;

    // traversing the linkedlist
    printLinkedList(head);


    return 0;
}
