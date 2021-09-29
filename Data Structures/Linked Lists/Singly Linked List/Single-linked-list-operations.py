# A pythom program for all operations performed on singly linked-list.
# Time-Complexity = O(n)
# Space-Complexity = O(n)
class Node:
    def __init__(self, data=None, next=None):   # Creation of Node
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None  # head points the first node

    def print(self):
        if self.head is None:
            print("Linked list is empty")
            return
        itr = self.head
        llstr = ''    # empty string
        while itr:
            llstr += str(itr.data)+' --> ' if itr.next else str(itr.data)
            itr = itr.next
        print(llstr)

    def length(self):   # will calculate length of the linked list
        count = 0
        itr = self.head
        while itr:
            count += 1
            itr = itr.next

        return count

    def insert_at_begining(self, data):
        node = Node(data, self.head)  # Creating a new node calling Node method
        self.head = node

    def insert_at_end(self, data):
        if self.head is None:
            self.head = Node(data, None)
            return

        itr = self.head

        while itr.next:
            itr = itr.next

        itr.next = Node(data, None)

    def insert_at(self, index, data):
        if index < 0 or index > self.length():
            raise Exception("Invalid Index")

        if index == 0:
            self.insert_at_begining(data)
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                node = Node(data, itr.next)
                itr.next = node
                break

            itr = itr.next
            count += 1

    def remove_at(self, index):
        if index < 0 or index >= self.length():
            raise Exception("Invalid Index")

        if index == 0:
            self.head = self.head.next
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                itr.next = itr.next.next        # to delete the specified node
                break

            itr = itr.next
            count += 1

    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data)

    # removing element at linkedlist with Value
    def removeval(self, value):
        count = 0
        temp = self.head
        while temp:
            if value != temp.data:
                count += 1
            temp = temp.next
        if count == self.length():
            print("Value is not present")

        else:
            if value == self.head.data:
                self.head = self.head.next
                return
            temp = self.head
            while temp:
                if value == temp.next.data:
                    temp.next = temp.next.next
                    break

                temp = temp.next


if __name__ == '__main__':
    node1 = LinkedList()
    ins = list(input("Enter a values to be inserted by giving space[eg: python c++ java] : ").rstrip().split())
    node1.insert_values(ins)
    node1.print()
    ind = int(input("Enter the index to be added: "))
    val = input('Enter the value: ')
    node1.insert_at(ind, val)
    node1.print()
    remm = int(input('Enter the index to be removed: '))
    node1.remove_at(remm)
    node1.print()
    remval = input('Enter the value to be removed: ')
    node1.removeval(remval)
    node1.print()
    inss = list(input("Enter a values to be inserted by giving space[eg: 45 30 22] : ").rstrip().split())
    node1.insert_values(inss)
    node1. print()
    inend = int(input('Enter the number to be inserted at the end: '))
    node1.insert_at_end(inend)
    node1.print()
    remval1 = input('Enter the value to be removed: ')
    node1.removeval(remval1)
    node1.print()
