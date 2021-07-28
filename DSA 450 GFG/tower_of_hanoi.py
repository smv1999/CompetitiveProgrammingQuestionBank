# we have to transfer n disks from rod A to C using the auxilliary rod B
def tower_of_hanoi(n, A, B, C):
    if(n>0):
        tower_of_hanoi(n-1, A, C, B)
        print("Moving disk ",n," from rod ", A, " to rod ", C)
        tower_of_hanoi(n-1, B, A, C)
    
n= int(input())
tower_of_hanoi(n, 'A','B','C')
