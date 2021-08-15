# Class for creating Linked list Node
class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

# Class for performing operation


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # Function for inserting node
    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node


# Function to check whether linked list has cycle
def has_cycle(head):
    count = 0
    temp = head
    while temp:
        if count == llist_count + 1:
            return "Cycle detection is Found"
        count += 1
        temp = temp.next
    return "No cycle detection is Found"


# Main function
if __name__ == '__main__':
    index = int(input("Enter the index where the last node need to connected:"))

    llist_count = int(input("Enter the linked list count: "))

    llist = SinglyLinkedList()

    print("Enter the element to be added on linked list one by one")
    for _ in range(llist_count):
        llist_item = int(input())
        llist.insert_node(llist_item)

    extra = SinglyLinkedListNode(-1)
    temp = llist.head

    for i in range(llist_count):
        if i == index:
            extra = temp

        if i != llist_count-1:
            temp = temp.next

    temp.next = extra

    result = has_cycle(llist.head)
    print('\n')
    print('Result: ', result)


'''
  Output window:
  
  Enter the index where the last node need to connected:1
  Enter the linked list count: 3
  Enter the element to be added on linked list one by one
  1
  2
  3
  Result:  Cycle detection is Found
  Explanation:
  Index : 2 
  Linked list values: 1 2 3 
  Normal linked list representation: 1 -> 2 -> 3
  By mering the last node of linked list with index value looks like
  1 ->  2 ->  3 ->
        ^ <- <- <-
Complexity:
Time complexity -> O(n)
Space Complexity -> O(n)
 '''
