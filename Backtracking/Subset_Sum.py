'''
Aim: From a list of integers, check and return a set of integers whose sum 
     will be equal to the target value K.

'''

# Main Recursive function to find the desired Subset Sum
def Subset_Sum(li, target, ans=[]):

    # Base Cases
    if target == 0 and ans != []:
        return ans

    elif li == []:
        return False

    # li[0] is not included in the answer Subset
    temp = Subset_Sum(li[1:], target, ans)
    if temp:
        return temp

    # li[0] included in the answer Subset
    temp = Subset_Sum(li[1:], target - li[0], ans + [li[0]])

    return temp

# --------------------------- DRIVER CODE------------------------------

if __name__ == "__main__":

    li = [int(i) for i in input("Enter the List of Integers: ").split()]
    Target = int(input("Enter the Target value: "))

    ans = Subset_Sum(li, Target)
    if not ans:
        print("No Subset Sum matched to the Target")
    else:
        print("The Required Subset is : ", *ans)

'''

Sample Input: 
Enter the List of Integers: -1 2 6 7 -4 7 5 -2 
Enter the Target value: 0

Sample Output:
The Required Subset is :  6 -4 -2

Explanation:
6 - 4 - 2 = 0, the required result

COMPLEXITY:

     Time Complexity: O(2^N)
     Space complexity: O(N)
     
'''