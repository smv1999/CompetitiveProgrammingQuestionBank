/* PROBLEM STATEMENT 


Finally a monsoon has come. According to the Meteorological Department, there will be rain in the upcoming N days in the city. Initially, the water level of the city is zero millimetres. The amount of rain on the i-th day can be described by an integer Ai as follows:

If Ai>0, the water level of the city increases by Ai millimetres on the i-th day.
If Ai=0, there is no rain on the i-th day. The water level of the city decreases by D millimetres on such a day. However, if the water level is less than D millimetres before the i-th day, then it becomes zero instead.
There will be a red alert in the city if the water level becomes strictly greater than H millimetres on at least one of the N days. Determine if there will be a red alert.

Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, D and H.
The second line contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, print a single line containing the string "YES" if there will be a red alert or "NO" otherwise.

Constraints
1≤T≤103
1≤N,D≤102
0≤Ai≤102 for each valid i
1≤H≤104
Subtasks
Subtask #1 (100 points): original constraints

Sample Input 1 
4
4 2 6
1 3 0 2
2 1 100
1 100
4 2 3
1 2 0 2
3 7 10
5 3 9 
Sample Output 1 
NO
YES
NO
YES
Explanation
Example case 1:

On the first day, the water level of the city increases to 1 millimtre.
On the second day, the water level increases by 3 millimeters and becomes 1+3=4 millimtres.
On the third day, there is no rain in the city, so the water level decreases by D=2 millimtres and becomes 4−2=2 millimtres.
On the fourth day, the water level increases by 2 millimtres and becomes 2+2=4 millimtres.
There will be no red alert in the city because the water level does not exceed H=6 millimtres on any of the four days.

Example case 2: The water level of the city on the 2-nd day is equal to 101 millimtres, which is greater than H=100 millimtres, so there will be a red alert in the city.

Example case 3: The water levels of the city on the four days are [1,3,1,3]. The water level is equal to H=3 millimtres on the second and fourth day, but it does not exceed the threshold.

Example case 4: There will be a red alert in the city on the 3-rd day.  */

// SOLUTION

#include <stdio.h>

int main(void) {
	
	int t,n,d,h;
	
	scanf("%d",&t);

	 while(t--)
	 {
	     	scanf("%d %d %d",&n,&d,&h);
	     	int sum=0;int val; int ret=0;
	     	for(int i=0;i<n;i++)
	     	{
	     	    scanf("%d",&val);
	     	    if(val>0)
	     	    {
	     	        sum+=val;
	     	       
	     	    }
	     	    if(val==0)
	     	    {
	     	        sum=(sum<d)?0 : (sum-d);
	     	       
	     	    }
	     	     if(sum>h)
	     	        {
	     	            ret=1;
	     	        }
	     	}
	     	if(ret==0)
	     	printf("NO\n");
	     	else
	     	printf("YES\n");
	     	
	     	
	 }
	 
	
	return 0;
}
