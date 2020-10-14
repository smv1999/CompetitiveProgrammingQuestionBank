#include<bits/stdc++.h>

using namespace std;

class Node
{  public:
    int data;
    Node *prev;
    Node *next;
};
void addNode(Node **, int);
void printList(Node *);
void printReverseList(Node *);
void deleteMid(Node **head, int data_to_delete);

int main()
{
    Node *head;
    head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    printList(head);
    deleteMid(&head, 20);
    printList(head);
    printReverseList(head);
    return 0;
}
void addNode(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    if(*head == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        *head = new_node;
    }
    else{
        Node *temp;
        temp = *head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}
void printList(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void printReverseList(Node *head)
{
    Node *temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}
void deleteMid(Node **head, int data_to_delete)
{
    Node *temp = *head;
    while(temp->data != data_to_delete){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}


