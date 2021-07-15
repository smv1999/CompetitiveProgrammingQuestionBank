/*
Src : LeetCode
--------------

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:

 A:               a1 --- a2
                		  \
                		   c1 --- c2 --- c3
                		  / 
 B:        b1 --- b2 --- b3

It is guaranteed that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.

Example: 

 A:               4 --- 1
                		  \
                		   8 --- 4 --- 5
                		  / 
 B:        5 --- 6 --- 1

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.


Constraints:

#  The number of nodes of listA is in the m.
#  The number of nodes of listB is in the n.
#  0 <= m, n <= 3 * 104
#  1 <= Node.val <= 105
#  0 <= skipA <= m
#  0 <= skipB <= n
#  intersectVal is 0 if listA and listB do not intersect.
3  intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.


Follow up: Could you write a solution that runs in O(n) time and use only O(1) memory?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
    	ListNode *p2 = headB;
        
	    if (p1 == NULL || p2 == NULL) return NULL;
	
	    while (p1 != NULL && p2 != NULL && p1 != p2) {
	        p1 = p1->next;
	        p2 = p2->next;
	        if (p1 == p2) return p1;
	        if (p1 == NULL) p1 = headB;
	        if (p2 == NULL) p2 = headA;
	    }
	        
	    return p1;
    }
};


//CODE
//Time Complexity = O(n) 
//Space Complexity = O(1)
