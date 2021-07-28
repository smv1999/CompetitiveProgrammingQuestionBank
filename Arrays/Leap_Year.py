'''
Aim: To check if the entered year is a leap year or not.

'''

def is_leap(year):
    # a year is a leap one if it's divisible by 4 and if it's not 
    # divisible by 100 or is divisible by 400
    print((year%4==0 and (year%100!=0 or year%400==0))) 

# getting the input
year = int(input().strip())
# displaying the result
is_leap(year) 

'''

COMPLEXITY:
	
	 Time Complexity -> O(1)
	 Space Complexity -> O(1)
     
Sample Input:
2000

Sample Output:
True

Explanation:
2000 % 400 = 0 
2000 % 4 = 0
Hence, 2000 was a leap year.

'''