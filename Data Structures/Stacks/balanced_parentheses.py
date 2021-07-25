## Python code to Check for 
# balanced parentheses in an expression


#Function to check parentheses
def validparentheses(s):
    open_brace=["{","[","("]
    closed_brace=["}","]",")"]
    stack=[]
    for i in s:
        if i in open_brace:
            stack.append(i)
        elif i in closed_brace:
            p=closed_brace.index(i)
            if len(stack)>0 and open_brace[p]==stack[len(stack)-1]:
                stack.pop()
            else:
                return False
    if(len(stack)==0): #return true if given expression is balanced
        return True
    else:
        return False   #return false is not balanced
    
s=input("Enter the Expression to be evaluated:")
if(validparentheses(s)):
    print("Expression is Balanced")
else:
    print("Expression is Unbalanced")