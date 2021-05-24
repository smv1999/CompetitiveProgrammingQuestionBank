"""
  Given a linked list and two keys in it, swap nodes for two given keys.
  Nodes should be swapped by changing links. 
  Swapping data of nodes may be expensive in many situations
  when data contains many fields. 
                                     """


""" 
  Input: 8 -> 5 -> 10 -> 7 -> 6 -> 11 -> 9 -> None, key1 = 8, key2 = 5
  Output: 5 -> 8 -> 10 -> 7 -> 6 -> 11 -> 9 -> None4

"""

# Class to create new Node


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Linked_List:
    def __init__(self):
        self.head = None

    # Function to add the data at the end of linked list
    def Insert_At_End(self, new_data):
        new_node = Node(new_data)  # Allocate the new node and put the data
        if self.head is None:  # if list is empty then retrun
            self.head = new_node
            return
        current = self.head
        while(current.next):
            current = current.next
        current.next = new_node  # Move new node to the next of current node

# Fucntion to swap nodes key1 and key2 in linked list by changing links
    def Swap(self, key1, key2):
        Prev_node_1 = None
        Prev_node_2 = None
        Node_1 = self.head
        Node_2 = self.head
        if self.head == None:
            return

        if key1 == key2:  # Nothing to do if key1 and key2 are same
            return
        while(Node_1.data != key1):  # Search for key 1
            Prev_node_1 = Node_1
            Node_1 = Node_1.next
        while(Node_2.data != key2):  # Search for key 2
            Prev_node_2 = Node_2
            Node_2 = Node_2.next
        if Prev_node_1 is not None:
            Prev_node_1.next = Node_2
        else:
            self.head = Node_2
        if Prev_node_2 is not None:
            Prev_node_2.next = Node_1
        else:
            self.head = Node_1
        temp = Node_1.next
        Node_1.next = Node_2.next
        Node_2.next = temp
# Function to print the data to the screen

    def Display(self):
        temp = self.head
        while(temp):
            print(temp.data, "->", end=" ")
            temp = temp.next
        print("None")


if __name__ == "__main__":
    L_list = Linked_List()
    L_list.Insert_At_End(8)
    L_list.Insert_At_End(5)
    L_list.Insert_At_End(10)
    L_list.Insert_At_End(7)
    L_list.Insert_At_End(6)
    L_list.Insert_At_End(11)
    L_list.Insert_At_End(9)
    print("Linked List: ")
    L_list.Display()
    print("Swap List: ")
    L_list.Swap(8, 5)
    L_list.Display()
