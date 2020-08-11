#include<iostream>

using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

void insertAtFront(Node **, int);
void insertAfter(Node **,int, int);
void insertAtEnd(Node **, int);
void printLinkedList(Node *);

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    insertAtFront(&head, 4); // adding 4 at the head of the linkedlist
    insertAtEnd(&head,5); // adding 5 at the end of the linkedlist
    insertAfter(&head,3,6);
    printLinkedList(head); // 4 1 2 3 6 5

    return 0;
}
void insertAtFront(Node **head_ref, int new_data)
{
    Node *new_node = new Node(); // creating a new node

    new_node->data = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;

}
void insertAtEnd(Node **head_ref,int new_data)
{
    Node *new_node = new Node();
    Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next=NULL;

    if(*head_ref==NULL) // if LL empty
    {
        *head_ref = new_node;
        return;
    }
    while(last->next!=NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void insertAfter(Node **head_ref, int after, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    Node *mid = *head_ref;
    while(after != mid->data)
    {
        mid = mid->next;
    }
    new_node->next = mid->next;
    mid->next = new_node;
}
void printLinkedList(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}
