"""
Algorithm 
1. Scan the infix expression from left to right. 
2. If the scanned character is an ‘(‘, push it to the stack.
3. else If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, discard both '(' and ')'
4. else If the scanned character is an operand, output it. 
5. Else if it is an operand, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack or the stack is empty or the stack contains a ‘(‘ , push it onto the stack. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator until the stack is not empty or '(' is not encountered. After doing that Push the scanned operator to the stack.  
6. Repeat steps 2-6 until infix expression is scanned. 
7. Empty the stack into the output
8. Print the output 
"""

operators = {'+':1,'-':1,'*':3,'/':3,'^':5}

# Tells if a given list is empty or not
def isEmpty (l):
    return not l


def infix_to_postfix (infix):
    """Converts infix expression to postfix
        takes argument : infix expression string
        returns : equivalent postfix expressiion string"""
    post = ""
    stack = []
    top = -1
    for c in infix:
        
        if c == "(":
            stack.append(c)
        elif c == ")":
            while not isEmpty(stack):
                if stack[top] == "(":
                    stack.pop()
                    break
                else :
                    post += stack.pop()

        elif c.isalpha():
            post += c
        elif c in operators:           
            if isEmpty(stack) or stack[top] == "(" or operators[c] > operators[stack[top]]:
                stack.append(c)

            else:       # operators
                while not isEmpty(stack) :
                    if stack[top] == "(" :
                        break  
                    
                    if operators[stack[top]] >= operators[c] :
                        post += stack.pop()
                    else:
                        stack.append(c)
                if isEmpty(stack) or stack[top]=="(":
                    stack.append(c)
        print(c, stack, post)

    while not isEmpty(stack):
        post += stack.pop()

    print(stack)
    return post


# DRIVER CODE
if __name__ == "__main__":
    
    infix_exp = "a+b*(c^d-e)^(f+g*h)-i"
    postfix_exp = infix_to_postfix(infix_exp)

    print("\nInfix Expression : ", infix_exp)
    print("\nEquivalent Postfix expression : ", postfix_exp)

    # Expected output = abcd^e-fgh*+^*+i-
    # Actual output  =  abcd^e-fgh*+^*+i-