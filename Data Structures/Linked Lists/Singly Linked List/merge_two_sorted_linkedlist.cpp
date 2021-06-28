/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) 
and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.
*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(struct Node *a, struct Node *b);

void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int data;
        cin >> data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin >> data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for (int i = 1; i < m; i++)
        {
            cin >> data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

Node *sortedMerge(Node *A, Node *B)
{
    // code here
    Node *head = NULL;
    Node **ref = &head;
    while (A && B)
    {
        if (A->data < B->data)
        {
            *ref = A;
            A = A->next;
        }
        else
        {
            *ref = B;
            B = B->next;
        }
        ref = &((*ref)->next);
    }
    *ref = (A) ? A : B;
    return head;
}