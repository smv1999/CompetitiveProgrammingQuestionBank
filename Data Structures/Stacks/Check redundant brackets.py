"""Check redundant brackets
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.
Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.
Time Limit: 1 second
Sample Input 1:
a+(b)+c
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
Sample Input 2:
(a+b)
Sample Output 2:
false"""

def checkRedundantBrackets(expression) :
  s=expression
  le = len(s)
  l=[]
  for i in range(le):
    if s[i]=="(":  # checks open bracket
      l.append("(") # put open brackets to stack
    elif s[i] in "+-*/": #check char in the string
      l.append(s[i])      #if it an operator then put it into the stack
    elif s[i] ==")":       # checks close bracket
      if l[-1]=="(":       # and if there is no operator in the stack
          return True      # then its redundant and further code will not run
      elif l[-1] in "+-*/":        # if it has operator 
        
        while l[-1]!="(":          # then pop till we don't get open bracket
          l.pop()                  
        l.pop()                     #pop open bracket
  return False                      #it is false if no redundant bracket is found till end

expression=input("Enter the expression:\n")
print("output:")
if checkRedundantBrackets(expression):
  print('true')
else:
  print('false')
"""
Time complexity: O(n)
Space complexity: O(n)
"""