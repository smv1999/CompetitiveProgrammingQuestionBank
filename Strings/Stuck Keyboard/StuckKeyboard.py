# Problem taken from Binary Search

# Problem Statement :
#      You are given two strings 'typed' and 'target'.
#  You want to write 'target' but the keyboard is stuck so some characters may be written
#  one or more times. Return whether it's possible that 'typed' was meant to write 'target'

# Example :
#      Sample Input - 1 :
#          typed = "aaabcccc"
#          target = "abc"
#      Sample Output - 1 : 
#          true

#      Sample Input - 2 :
#          typed = "abc"
#          target = "ab"
#      Sample Output - 2 : 
#          false

class Solution:
    def solve(self, typed, target):
        if(len(typed) == 0 or len(target) == 0):
            return len(typed) == len(target)
        i , j , cnt1 , cnt2 = 0 , 0 , 0 , 0
        ch = False
        while(i < len(typed) and j < len(target)):
            x , y = i + 1 , j + 1
            while(x < len(typed) and typed[x] == typed[i]):
                x += 1
            while(y < len(target) and target[y] == target[j]):
                y += 1
            cnt1 , cnt2 = x - i , y - j
            if(target[j] == typed[i]):
                if(cnt1 < cnt2):
                    return False
            else:
                return False
            if(x < len(typed) and y < len(target)):
                i , j = x , y
            else:
                if(not(x >= len(typed) and y >= len(target))):
                    ch = True
                break
        if(ch):
            return False
        if(cnt1 >= cnt2 and typed[i] == target[j]):
            return True
        return False
            