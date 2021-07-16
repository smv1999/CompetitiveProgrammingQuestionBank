/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example :

		1 ---> 2 ---> 3 ---> 4 ---> 5
	
	becomes
	 
	 	2 ---> 1 ---> 4 ---> 3 ---> 5
					
		
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Follow-up: Can you solve the problem in O(1) extra memory space?
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int n)
    {
        val = n;
        next = NULL;
    }
};

void printList(ListNode* head){
	int i = 0;
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    while (curr != NULL && count != k) { 
        curr = curr->next;
        count++;
    }
    if (count == k) { 
        curr = reverseKGroup(curr, k); 
        while (count-- > 0) { 
            ListNode* tmp = head->next; 
            head->next = curr;
            curr = head; 
            head = tmp; 
        }
        head = curr;
    }
    return head;
}
    
int main()
{
    int NumOfNodes, nn, data, k;
    cin>>NumOfNodes;
    nn = NumOfNodes;
    ListNode* head = NULL;
    ListNode* tail = head;
    
    while(nn--){
    	cin>>data;
    	if(!head){
    		head = new ListNode(data);
    		tail = head;
		}
		else{
			tail->next = new ListNode(data);
			tail = tail->next;
		}			
	}
	cin>>k;
	ListNode* finalHead = reverseKGroup(head, k);
	printList(finalHead);
    return 0;
}
//No extra space used.

