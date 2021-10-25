'''
Aim: To replace the first character of all the words with their upper case characters.

'''

# Complete the solve function below.
def solve(s):
    # splitting the string into words
    for x in s[:].split():
        # replacing the character with it's capital form
        s = s.replace(x, x.capitalize())
    print('Updated string:',s) 
    
# getting the input
s = input('Enter string: ')
# calling function to compute the result
solve(s)

'''

COMPLEXITY:
	
	 Time Complexity -> O(N)
	 Space Complexity -> O(N)
     
Sample Input:
Enter string: summer of code

Sample Output:
Updated string: Summer Of Code

Explanation:
All the initial characters of the words are capitalized.

'''