#https://leetcode.com/problems/longest-palindromic-substring/

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        # result to store palindrome
        res = ""

        for i in range(len(s)):

            # for odd len strings
            # Eg : "racecar"
            tmp = self.helper(i, i, s)
            if len(res) < len(tmp):
                res = tmp

            # for even len strings
            # Eg: "aaaabbaa"
            tmp = self.helper(i, i + 1, s)
            if len(res) < len(tmp):
                res = tmp


        return res

    def helper(self, l, r, s):
    # Helper function to check if the left pointer and right pointer are equal 
    # if inbound and palindrome, move left left and right right
        
        while (l >= 0 and r < len(s) and s[l] == s[r]):
            l -= 1
            r += 1

 
        return s[l + 1: r]