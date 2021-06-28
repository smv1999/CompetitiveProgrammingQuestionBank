/*
Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.
Input:
N = 3
value[] = {1,3,4}
x = 2
Output: True
Explanation: In above test case N = 3.
The linked list with nodes N = 3 is
given. Then value of x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.

*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool detectLoop(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        if (detectLoop(head))
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}

bool detectLoop(Node *head)
{
    Node *first, *second;
    first = second = head;
    first = first->next;
    second = second->next;
    if (second)
        second = second->next;
    while (first && second)
    {
        if (first == second)
            return true;
        first = first->next;
        second = second->next;
        if (second)
            second = second->next;
    }
    return false;
}
