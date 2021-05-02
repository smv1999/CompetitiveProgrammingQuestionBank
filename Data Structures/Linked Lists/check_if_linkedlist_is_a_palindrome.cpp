#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


/*
Approch used: 
-First traverse the LL to the middle node
using floyd's algorithm. 
-Than reverse the second half of the Linked list.
-Reset the fast pointer to head and compare each node.

-If Any does not match, the LL is not a palindrome.


*/
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

class Solution
{
public:
    //Function to check whether the list is palindrome.
    Node *reverseList(Node *head)
    {
        Node *curr = head;
        Node *temp = NULL;
        Node *prev = NULL;
        while (curr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        fast = head;
        while (slow)
        {
            if (slow->data != fast->data)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }

        return true;
        //Your code here
    }
};

int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}
