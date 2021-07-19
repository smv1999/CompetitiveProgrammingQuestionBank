#Longest Common Prefix in python

#define the function to evaluate the longest common prefix
def longestCommonPrefix(s): 
        p = ''             #declare an empty string
        for i in range(len(min(s, key=len))):
            f = s[0][i]
            for j in s[1:]:
                if j[i] != f:
                    return p
            p += f
        return p     #return the longest common prefix


n = int(input("Enter the number of names in list for input:"))
print("Enter the Strings:")
s = [input() for i in range(n)]
if(longestCommonPrefix(s)):
    print("The Common Prefix is:" ,longestCommonPrefix(s))
else:
    print("There is no common prefix for the given list of strings, hence the answer is:", 0)