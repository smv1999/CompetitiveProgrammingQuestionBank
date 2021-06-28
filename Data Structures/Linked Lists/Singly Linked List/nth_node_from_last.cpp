/*
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

*/

#include <stdio.h>
#include <stdlib.h>
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

int getNthFromLast(struct Node *head, int n);

int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
}

int getNthFromLast(Node *head, int n)
{
    Node *temp = head;
    int total_ele = 0;
    while (temp != NULL)
    {
        total_ele++;
        temp = temp->next;
    }
    int fromFirst = total_ele - (n - 1), count = 0;
    if (n > total_ele)
        return -1;
    temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == fromFirst)
        {
            return temp->data;
        }
        temp = temp->next;
    }
}
