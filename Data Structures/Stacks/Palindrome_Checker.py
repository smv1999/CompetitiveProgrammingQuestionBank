'''
Aim: Determine whether the entered string is palindrome or not.

'''

class Solution:
    def __init__(self):
          self.stack = []
          self.queue = []
          return(None)

    def pushCharacter(self, char):
          self.stack.append(char)

    def popCharacter(self):
          return(self.stack.pop(-1))

    def enqueueCharacter(self, char):
          self.queue.append(char)

    def dequeueCharacter(self):
          return(self.queue.pop(0))

# read the string s
s = input()

# creating the Solution class object
obj = Solution()   

l = len(s)

# push/enqueue all the characters of string s to stack
for i in range(l):
    obj.pushCharacter(s[i])
    obj.enqueueCharacter(s[i])
    
isPalindrome = True
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
''' 
for i in range(l // 2):
    if obj.popCharacter()!=obj.dequeueCharacter():
        isPalindrome = False
        break
    
# finally print whether string s is palindrome or not
if isPalindrome:
    print("The word, "+s+", is a palindrome.")
else:
    print("The word, "+s+", is not a palindrome.")

'''
Sample Test Case:
Input: 
level
Output: 
The word, level, is a palindrome.
Explaination:
All the characters popped from stack, matched the ones dequeued from queue.

'''