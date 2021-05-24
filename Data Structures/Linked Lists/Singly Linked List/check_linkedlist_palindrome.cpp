/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

bool isPalindrome(Node *head);
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << isPalindrome(head) << endl;
    }
    return 0;
}

bool isPalindrome(Node *head)
{
    struct Node *temp;
    temp = head;
    string s = "";
    while (temp)
    {
        s += '0' + temp->data;
        temp = temp->next;
    }
    int l = s.size();
    for (int i = 0; i < l / 2; i++)
        if (s[i] != s[l - i - 1])
            return false;
    return true;
}
