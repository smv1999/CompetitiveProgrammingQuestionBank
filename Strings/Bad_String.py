'''
Aim: Read a string, S and print its integer value. If S cannot be converted to 
an integer, print Bad String.

'''

# getting the input
S = input().strip()
try:
    # if it's possible to convert the entered string into an integer then this block will execute
    print(int(S))
except:
    # if it's not possible, then this block will be executed
    print('Bad String')
    
'''

COMPLEXITY:
	
	 Time Complexity -> O(1)
	 Space Complexity -> O(1)
     
Sample Input 1:
3
Sample Output 1:
3
Sample Input 2:
SB
Sample Output 2:
Bad String

Explaination:
'3' as a string can be converted into the integer 3, whereas SB can't be 
converted to an integer hence the 'except' block is executed and 'Bad String' 
is printed.

''' 