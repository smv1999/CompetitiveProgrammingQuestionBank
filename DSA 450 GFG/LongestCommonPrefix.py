# Link : https://leetcode.com/problems/longest-common-prefix/submissions/ 

# Approach : 

# Example
# Input: strs = ["flower","flow","flight"]
# Output: "fl"

# We are supposed to return the longest common prefix  

# Variables : 
# prefix => longest common substring 

# 1. Assume the longest common substring to be the first element of the list . prefix = strs[0]
# 2. Iterate through the list of words and keep comparing each char of the word with the prefix 
# 3. If the char of word != char of prefix , reduce the prefix to last matched char
# 4. If the word is shorter than the prefix , and all charachters are matched , then prefix = word


# Working
# prefix = "flower"

# i = 1
# prefix = "flower" , word = "flow"

# f = f , pass
# l = l , pass 
# o = o , pass
# w = w , pass
# i = 4 , 4 >= len("flow") , prefix = "flow"  , break



# i = 2 
# prefix = "flow" , word = "flight"
# f = f , pass
# l = l , pass
# o != i  => prefix = prefix[:i] = "fl" , break


# o/p = "fl"


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        n = len(strs)
        prefix = strs[0]
        
        for word in strs:
          for i in range(0 , len(prefix)):
            if(i >= len(word)):
              prefix = word
              break
              
            elif(prefix[i] != word[i]):
              prefix = prefix[:i]
              break
              
        return prefix
            
            
# TC : O(mn)