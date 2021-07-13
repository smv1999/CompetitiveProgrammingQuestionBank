# import the math module for mathematical functions
import math
# define the function moves
def movess(v):
    # create a variable move to count the number of moves for balls in each packet
    move=v
    # initially seperate the balls into two groups
    while(v%2==0):
        v=v//2
        move+=v
        # keep increasing the counts while seperating the balls into groups
    for i in range(3,int(math.sqrt(v))+2,2):
        while(v%i==0):
            v=v//i
            move+=v
    if v>2:
        move+=1        
    return move

# input the number of packets
b=int(input()) 
# input the number of balls in the packet
j=list(map(int,input().strip().split(" ")))
k=0
# call the function moves for balls in every packet
for w in j:
    k+=movess(w)
print(k)
