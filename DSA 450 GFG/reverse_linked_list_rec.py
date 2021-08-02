# Approach :
# Divide the linked list to two halved
# First half is head and the remaining as rest 
# The head points to the rest in a normal linked list 
# In the reverse linked list , the next of current points to the prev node and the head node should point to NULL
# Keep continuing this process till the last node 


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseList(self, head):
        if head is None or head.next is None:
          return head
        rest = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return rest