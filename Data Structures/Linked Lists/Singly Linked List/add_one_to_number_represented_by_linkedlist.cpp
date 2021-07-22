//Link to Problem:  https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

//Problem Description: We need to add 1 to a number represented as Linked List

//Sample Test Cases

/*

Test Case 1

If the linked list given is as follows

4 -> 5 -> 6

We need to return this linked list as output

4 -> 5 -> 7

*/

/*

Test Case 2

If the linked list given is as follows

9 -> 9 -> 9

We need to return this linked list as output

1 -> 0 -> 0 -> 0


*/

#include <bits/stdc++.h>
using namespace std;

//Structure of Linked List
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

// Function to display a linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public:
    // A utility function to reverse a linked list
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *next = NULL;
        Node *prev = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to add 1 to a number represented as linked list
    Node *addOne(Node *head)
    {
        // we first reverse the linked list
        head = reverse(head);

        // we create a boolean variable whether 1 is added to the number or not.
        //If it is true, we assume, we need to add 1 in the number (so we make
        //it true by default)
        //when 1 is added to the number, we will make it false
        bool f = true;

        //curr refers to the current pointer which points to the head of the
        //linked list
        Node *curr = head;

        // we iterate till we reach the end of linked list OR we added 1 to the
        // linked list OR Both is some case (as described in test case 2)
        while (curr != NULL && f == true)
        {

            //This is the condition that would be executed when we have numbers
            //like 9, 99, 999, 9999 and so on

            //Here next pointer of current would be null and the data of current
            //pointer would be 9
            if (curr->next == NULL && curr->data == 9)
            {
                // we make the data value of current pointer to 1
                curr->data = 1;

                // we make a new node called temp with value 0 (because we need
                // to have 1 extra 0 for example in case of 9 <- 9 <- 9, we make the
                // current value to 1 and the list would look like 1 <- 0 <- 0
                Node *temp = new Node(0);

                // we add that zero before the head, this will make the linked
                // list as  1 <- 0 <- 0 <- 0
                temp->next = head;

                // we make temp as the head of the linked list
                head = temp;

                //we point current pointer to its next node which will make
                //curr point to NULL and will exit from the while loop
                curr = curr->next;
            }

            //This is the case that would be executed when we have numbers like
            //19, 119, etc (i.e 9 is present on the LSB(least significant bit) of original number )
            else if (curr->data == 9)
            {
                // we make the value of current pointer to 0 and move to next node
                curr->data = 0;
                curr = curr->next;
            }

            //This is the trivial case that would be executed for numbers like 5
            //16, 456 etc
            else
            {

                // we increment the value of current's pointer by 1.
                curr->data = curr->data + 1;

                // we make f false so as to terminate the while loop
                f = false;

                //move the current pointer to its next node
                curr = curr->next;
            }
        }

        //we reverse the reversed linked list to obtain the original linked list
        head = reverse(head);

        // we finally return the head of new linked list
        return head;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
