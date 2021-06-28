
# Link for the problem : https://leetcode.com/problems/merge-intervals/

# Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

# Create a list merged to store the merged intervals
# Condition for merging  : If the first index of current interval is less than last index of previous interval 
# If condition satisfies , replace the last index of previous interval with the maximum between current and previous interval's last index
# If not , then simply append the interval in the merged list 



class Solution:
    def merge(self, intervals):
      
        intervals.sort(key = lambda x : x[0])
        merged = [] 
        
        for interval in intervals :
          
          if not merged or merged[-1][1] < interval[0] :
            merged.append(interval)
          else :
            merged[-1][1] = max(merged[-1][1] , interval[1])
            
        return merged
    
    
