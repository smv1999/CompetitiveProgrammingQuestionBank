/*
Given the Sorted Linked list head which contain duplicates, the task is
to delete all the duplicate and make linked list such that every element
appear just one time.
Example:
Original Linked list : 1 1 2 2 3
Answer : 1 2 3
*/

#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
    public:
    int data;
    Node *next;
};

// Utility function to create a new Node
void push(Node **head, int n_data)
{
    Node *newdata = new Node();
    newdata->data = n_data;
    newdata->next = (*head);
    (*head) = newdata;
}

// Function to print nodes in a given linked list. 
void printlinkedlist(Node *temp)
{
    while (temp != NULL)
    {
        cout << "->" << temp->data;
        temp = temp->next;
    }
}

// Function to delete duplicate nodes
Node *delete_duplicates(Node *head)
{
    //initalize current to head
    Node *curr = head;
    // when curr and curr->next is not NULL
    // enter the loop
    while (curr && curr->next)
    {
        // if the adjacent nodes are found to be equal
        if (curr->next->data == curr->data)
        {
            // then point the curr->next to one step ahead
            // to the existing pointer.
            curr->next = curr->next->next;
        }
        else
        {
            // Until the current and current->next values are 
            // not same, keep updating current
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    Node *head = NULL;
    int n;
    cout << "Enter number of Elements:";
    cin >> n;
    cout << "Enter elements:";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        push(&head, a);
    }
    cout <<"Original Linked list:\n";
    printlinkedlist(head);
    cout <<"\nNew Linked List:\n";
    head = delete_duplicates(head);
    printlinkedlist(head);
}

/*
Sample Input:
Enter number of Elements:5
Enter elements:1 1 2 2 3

Sample Output:
Original Linked list:
->3->2->2->1->1
New Linked List:
->3->2->1

Time-Complexity: O(n)
Space-Complexity: O(1)
*/
