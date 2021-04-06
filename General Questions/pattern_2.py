'''
PRINT THE FOLLOWING STAR PATTERN :
       *
      **
     ***
    ****
   *****
  ******
 *******
******** 
'''

#Taking user input
n = int(input())

for i in range(n,0,-1):
    print(' '*(i-1),end="")
    print('*'*(n-i+1))
