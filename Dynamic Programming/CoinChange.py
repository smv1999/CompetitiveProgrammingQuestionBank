# https://leetcode.com/problems/coin-change/

#### In the given problem , we are supposed to find minimum number of coins to get the sum equal to the amount given

#### For given example
# - Input :

# 1. coins = [7 , 5 , 1]
# 2. amount = 18

# - O/p :
#     4

# We can achieve 18 by 
# - 2 Coins of 5
# - 1 coin of 7
# - 1 coin of 1
# - Sum = 4

# 18 can be achieved by various combinations of 7 , 5 , 1

# https://ibb.co/TtcVRYx

# Refer the image above

# Lets call 11 , 13 , 17 , 6 , 12 , 10 ... as subSums

# As shown in the image above , 6 has been calculated previously and later on 6 is required in latter part .
# Instead of computing it again , we can store the value for 6 i.e 2 (1 coin of 5 and 1 coin of 1)

# As we need to store the value of recursion ie. Subsums in a memory , hence we choose DP here

# Consider a list op = [] with size equal to the amount

# op[] stores the number of coins required for each number from  1, 2 ,...amount 
# We are supposed to return op[amount] 

# In this case op[18] returns the minimum coins required to produce the sum 18


class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        op = [amount+1] * (amount+1)
        op[0] = 0
        for i in xrange(1, amount+1):
            for c in coins:
                if i >= c:
                    op[i] = min(op[i], op[i-c] + 1)
                    
        if op[amount] >= amount+1:
             return -1
        return op[amount]
    

