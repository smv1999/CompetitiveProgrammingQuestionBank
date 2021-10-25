# Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

# Input:
# N = 6
# start[] = {1,3,0,5,8,5}
# end[] =  {2,4,6,7,9,9}
# Output: 
# 4

# Meetings = [(1,2) , (3,4) , (0,6) , (5,7) , (8,9) , (5,9)]
# Required Output - > Get the max number of meetings that can be scheduled from the timings given 

# Get the maximum number of short meetings from the list of meetings

# Sorting The meetings wrt Start time -> [(0,6),(1,2),(3,4),(5,7),(5,9)]
# O/p = (0,6) => 1 meeting can be scheduled ad the end time of the meeting is 6 and there is no meeting
# starting after 6 , so Op is 1

# Sorting the meetings wrt End Time , Start time->  [(1,2) , (3,4) , (0,6) , (5,7) , (5,9) , (8,9) ]

# Op = [(1,2) , (3,4) , (5,7) , (8,9) ] => 4

# Condition for selecting a meeting - > Start time of the meeting should be greater than
# the end time of the previous meeting

# Approach :

# Variables  :
# i = Track the previous meetings -> i = 0
# j = Track the current meetings  -> j = 1
# counter = Count of number of meetings that can be scheduled  -> counter = 1
# By default the first meeting will be scheduled , so counter initialized with value 1

# 1. Make a list of Meetings with start time and end time 
# 2. Sort the list wrt start time and then sort it wrt to end  time
# 3. Iterate through the meetings and check the condition that whether the start time of the current 
# meeting is greater than the end time of the previous meeting 

# for j in range(1, n):
#   if(Meetings[j][0] > Meetings[i][1]):
#       counter ++
#       i = j

# 4. Return counter


import sys
import io

class Solution:
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,n,start,end):
        # code here
        Meetings = []
        for i in range(n):
            Meetings.append([start[i] , end[i]])
            
        Meetings.sort(key = lambda x : x[0])
        Meetings.sort(key = lambda x : x[1])
        # To track the previous meeting
        i = 0 
        # To track the current meeting
        j = 1
        # First meeting always gets selected
        counter = 1
        
        for j in range(1,n):
            # Condition for scheduling
            if(Meetings[j][0] > Meetings[i][1]):
                counter += 1
                i = j
                
        # print(Meetings)
        return counter
    
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        start_time = list(map(int , input().strip().split()))
        end_time = list(map(int , input().strip().split()))
        ob = Solution()
        print(ob.maximumMeetings(n,start_time , end_time))