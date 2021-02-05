/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

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
        struct Node *head = NULL;
        struct Node *temp = head;

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

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    set<int> st;
    st.insert(temp->data);
    while (temp->next != NULL)
    {
        auto pos = st.find(temp->next->data);
        if (pos != st.end())
            temp->next = temp->next->next;
        else
        {
            temp = temp->next;
            st.insert(temp->data);
        }
    }
    return head;
}
