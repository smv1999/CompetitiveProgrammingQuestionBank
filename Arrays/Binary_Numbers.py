'''
Aim: Given a base-10 integer, n, convert it to binary (base-2). Then find and print the 
base-10 integer denoting the maximum number of consecutive 1's in n's binary representation. 

'''

n = int(input())                    # getting input
remainder = []
while n > 0:
    rm = n % 2
    n = n//2                        # whenever decimal to binary conversion is done, the number is repeatedly divided by 2 until it could not be divided any further
    remainder.append(rm)            # appending the remainder that is obtained each time in a list
count,result = 0,0
for i in range(0,len(remainder)):
    if remainder[i] == 0:
        count = 0                   # as soon as '0' is encountered, the counter is set to 0
    else:
        count += 1                  # the counter increases every time consecutive ones are encountered 
        result = max(result,count)  # maximum streak of 1's is chosen
print(result)

'''

Sample Test Case:
Input: 
13
Output: 
2
Explaination:
The binary representation of 13 is 1101, so the maximum number of consecutive 1's is 2.

'''