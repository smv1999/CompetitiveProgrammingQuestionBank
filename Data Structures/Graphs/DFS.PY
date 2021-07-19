def Depthfirstsearch(matrix,start):
    visit=[start] #Keep Track of Visited elements
    stack=[start] #DFS is implemented using stack
    while(len(stack)) :
        ele=stack.pop(-1) #pop the element from stack ie last element from list
        for i in range(len(matrix)):
            if matrix[ele][i]==1 and i not in visit: # check the adjacent elements and push into the stack if the vertix was not visited
                  stack.append(ele)
                  visit.append(i)
                  stack.append(i) 
                  break
    return visit
def valid(li,n): 
    if len(li)==n: #each row should contain n elements
        for i in li: 
            if i!=0 and i!=1: #each row should contain 0's and 1's 
                return False
    return True
# main function
if __name__ == "__main__":
     n=int(input("Enter the no of vertices\n")) # Read no of vertices
     print("Enter adjacency matrix of graph") # Read adjacency matrix
     matrix=[]
     for _ in range(n):
         li=list(map(int,input().split()))
         if(valid(li,n)==False): # check wheather the given list is in valid adjacency matrix or not should contain 0's and 1's
             print("Enter valid n*n matrix")
             exit # Terminate the program for incorrect details
         matrix.append(li)   
     start=int(input("Enter the starting vertix\n"))
     ans=Depthfirstsearch(matrix,start)
     print("DFS of the given graph is ",end=" ")
     print(*ans)  