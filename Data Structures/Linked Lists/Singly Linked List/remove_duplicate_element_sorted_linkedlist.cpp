/*
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values)
from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

*/
#include <bits/stdc++.h>
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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *removeDuplicates(Node *root);
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}

Node *removeDuplicates(Node *root)
{
    Node *safe = root;
    while (safe->next != NULL)
    {
        if (safe->data == safe->next->data)
            safe->next = safe->next->next;
        else
            safe = safe->next;
    }
    return root;
}