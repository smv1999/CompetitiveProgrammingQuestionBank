/*
LeetCode : #1290
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int total = 0, res = 0;
        ListNode *temp = head;
        while(temp != NULL){
            temp = temp->next;
            total++;
        }
        temp = head;
        total--;
        while(temp != NULL){
            res += pow(2, total) * temp->val; 
            total--;
            temp = temp->next;
        }
        return res;
    }
};