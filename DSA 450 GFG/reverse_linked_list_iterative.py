#https://leetcode.com/problems/reverse-linked-list/

# Iterative method
#Approach : 

# Store the head in a temp variable called current . 

#   curr = head , prev = null 

# Now for a normal linked list , the current will point to the next node and so on till null 
# For reverse linked list, the current node should point to the previous node and the first node here will point to null 

# Keep iterating the linkedlist until the last node and keep changing the next of the current node to prev node and also 
# update the prev node to current node and current node to next node


# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    
    def reverseList(self, head):
        curr = head
        prev = None
        while(curr != None):
          next = curr.next
          curr.next = prev
          prev = curr
          curr = next
          
        return prev
          