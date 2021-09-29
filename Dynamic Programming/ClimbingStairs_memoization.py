# https://leetcode.com/problems/climbing-stairs/

# Memoization

from functools import lru_cache

class Solution:
    @lru_cache(maxsize = 1000)
    def climbStairs(self, n: int) -> int:
        if(n == 0 or n == 1):
          return 1
        else:
          return self.climbStairs(n-1) + self.climbStairs(n-2)
