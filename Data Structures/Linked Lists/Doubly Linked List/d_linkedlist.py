# Class for creating Node
class Node:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

# Double linkedlist area


class DLinkedList:
    # initializind head
    def __init__(self):
        self.head = None

    # insertion at start
    def addbeg(self, data):
        if self.head == None:
            node = Node(data, self.head, None)
            self.head = node
        else:
            node = Node(data, self.head, None)
            self.head.prev = node
            self.head = node

     # printing the list
    def prinnt(self):
        if self.head is None:
            print('empty')
            return
        temp = self.head
        st = ''
        while temp:
            st += '<-' + str(temp.data) + '->'
            temp = temp.next
        print(st)

    # insertion at end
    def addend(self, data):
        if self.head is None:
            self.head = Node(data, None, None)
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            node = Node(data, None, temp)
            temp.next = node

    #printing in forward
    def pforward(self):
        if self.head is None:
            print('empty')
            return
        temp = self.head
        st = ''
        while temp:
            st += str(temp.data) + '->'
            temp = temp.next
        print(st)

     # Finding the length of linkedlist
    def lenn(self):
        if self.head is None:
            print('empty')
            return
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        return count

    # finding last node
    def lastnode(self):
        temp = self.head
        while temp.next:
            temp = temp.next
        return temp

    # Inserting element at linkedlist with index
    def addmid(self, index, data):
        if index < 0 or index >= self.lenn():
            print('Invalid index')
            return

        if index == 0:
            self.addbeg(data)
            return

        if index == self.lenn() - 1:
            self.addend(data)
            return

        temp = self.head
        count = 0
        while temp:
            if count == index - 1:
                node = Node(data, temp.next, temp)
                temp.next.prev = node
                temp.next = node
                break
            temp = temp.next
            count += 1

    #print in reverse
    def pbackward(self):
        if self.head is None:
            print('empty')
            return
        temp = self.lastnode()
        st = ''
        while temp:
            st += '<-' + str(temp.data)
            temp = temp.prev
        print(st)

    # removing element at linkedlist with index
    def remove(self, index):

        if index < 0 or index >= self.lenn():
            print('Invalid index')
            return
        if index == 0:
            self.head = self.head.next
            self.head.prev.next = None
            self.head.prev = None
            return

        if index == self.lenn() - 1:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.prev.next = None
            temp.prev = None
            return

        temp = self.head
        count = 0
        while temp:
            if count == index:
                temp.prev.next = temp.next
                temp.next.prev = temp.prev
                temp.prev = None
                temp.next = None

            temp = temp.next
            count += 1


if __name__ == '__main__':
    li = DLinkedList()
    a = int(input('Enter the value to insert at beg: '))
    li.addbeg(a)
    b = int(input('Enter the value to insert at beg: '))
    li.addbeg(b)
    c = int(input('Enter the value to insert at end: '))
    li.addend(c)
    d = int(input('Enter the value to insert at end: '))
    li.addend(d)
    li.prinnt()
    print("Priting in forward: ", end="")
    li.pforward()
    print('Printing in backward: ', end="")
    li.pbackward()
    print('Len of linked list is ', end='')
    li.lenn()
    e = int(input('Enter the index to be removed: '))
    li.remove(e)
    li.prinnt()
    f = int(input('Enter the index: '))
    g = int(input('Enter the number: '))
    li.addmid(f, g)
    li.prinnt()
