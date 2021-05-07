# Problem : https://leetcode.com/problems/count-and-say/

# Input: n = 4
# Output: "1211"
# Explanation:
# countAndSay(1) = "1"
# countAndSay(2) = say "1" = one 1 = "11"
# countAndSay(3) = say "11" = two 1's = "21"
# countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

# Initialize counter = 1 to store the count of every element 
# Initialize o/p string as ret = ""
# If the previous element in the string is equal to the current element in the string , increament the counter
# else Concatenate the count and the previous element of the string in ret

# Return ret

class Solution:
    def countAndSay(self, n):
        if (n == 1):
            return ("1")
        
        s = self.countAndSay(n-1)
        
        ret = ""
        cnt = 1
        i = 1
        while i < len(s) + 1:
            if i < len(s) and s[i] == s[i-1]:
                cnt += 1
            else:
                ret += str(cnt) + str(s[i-1])
                cnt = 1
            i += 1
            
        return (ret)