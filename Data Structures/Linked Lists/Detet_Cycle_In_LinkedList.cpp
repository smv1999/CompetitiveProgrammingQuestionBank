/*
    A Linked List is a linear data structure which includes a series of connected nodes. 
    Each node stores the data and the address of the next node.
    If any node is visited more than once while traversing the list then we can say that it contains cycle/loop.
     Example:
                1 -> 2 -> 3
                    ^     |
                    |     v
                    5 <-  4   
     Output:
            True
    Method:In this method we will traverse the linkedlist using two pointers is slow and fast. 
    Move the slow pointer by one position and fast pointer by two positions.
    If these two pointers meet together at any point at same node then we can say that there is loop/cycle inside linkedlist. 
*/

#include <bits/stdc++.h>
using namespace std;

// Link list node 
class Node
{
public:
    int data;
    Node *next;
};

void push_node(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int detectLoop(Node *list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p)
        {
            return 1;
        }
    }
    return 0;
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node *head = NULL;
    int n = 0;
    cout << "Enter size of linked list" << endl;
    cin >> n;
    int i;
    int d;
    cout << "Enter the elements of linked list" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        push_node(&head, d);
    }

    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "True";
    else
        cout << "False";
    return 0;
}

/*
 Time complexity: O(n)
 Space complexity: O(1)
 
 Input :
 Enter size of linked list
 5
 Enter the elements of linked list
 45 24 32 72 54
 Output :
 True
*/