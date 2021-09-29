/*

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes 
with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Constraints:
 n == number of nodes in the linked list
 0 <= n <= 104
 -106 <= Node.val <= 106

*/

/*
Time Complexity: O(N), where N is the size of the array
Space Complexity: O(1), Constant Space
*/

/*

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes 
with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Constraints:
 n == number of nodes in the linked list
 0 <= n <= 104
 -106 <= Node.val <= 106

*/

/*
Time Complexity: O(N), where N is the size of the array
Space Complexity: O(1), Constant Space
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode // Linked list node
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

ListNode *oddEvenList(ListNode *head)
{
    int len = 1;// variable to store length of linked List
    ListNode *end = head;
    if (head == NULL)
        return NULL;
    while (end->next != NULL) // calculation of length
    {
        end = end->next;
        len++;
    }
    if (len <= 2)
        return head;
    ListNode *Nend = end; // pointer to point to the new end of the list
    ListNode *temp = head;
    while (temp != end)
    { 
        ListNode *t = temp->next; 
        temp->next = t->next; // breaking the link
        temp = temp->next; 
        t->next = NULL;
        Nend->next = t; // adding the node to the end
        Nend = Nend->next; // updating end
        if (t == end)
            break;
    }
    return head;
}
void printList(ListNode *head) // function to print the list
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main() // driver function
{
    int data = 1; // adding the elements to the list
    ListNode *head = new ListNode(data);
    ListNode *tail = head;
    for (int i = 2; i<=5 ; i++)
    {
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    
    head = oddEvenList(head);
    printList(head);

    return 0;
}