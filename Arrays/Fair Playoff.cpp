/* Problem Statement:
Four players participate in the playoff tournament. The tournament is held according to the following scheme: the first player will play with the second, and the third player with the fourth, then the winners of the pairs will play in the finals of the tournament.

It is known that in a match between two players, the one whose skill is greater will win. The skill of the i-th player is equal to si and all skill levels are pairwise different (i. e. there are no two identical values in the array s).

The tournament is called fair if the two players with the highest skills meet in the finals.

Determine whether the given tournament is fair.

Example:

Input:
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2

Output:
YES
NO
YES
NO
*/

#include<iostream>
using namespace std;

int main()
{
	long int T;
	cin>>T;
	
	while(T--)
	{
		int s[4], i, f1 = 0, f2 = 0, sm = 0, no = 0, yes = 0;
		for(i = 0; i < 4; i++)
			cin>>s[i];				//a 1-D array to store the skills of 4 players
			
		if(s[0] > s[1])				//comparing first player with second
			f1 = s[0];
			
		else
			f1 = s[1];
			
		if(s[2] > s[3])				//comparing third player with fourth
			f2 = s[2];
			
		else
			f2 = s[3];
			
			
		if(f2 - f1 > 0)
			sm = f1;
		else
			sm = f2;
			
		
		for(i = 0; i < 4; i++)
		{
			if(s[i] > sm)				//to check if the finals were fair or not
				yes++;					//assign 'yes' if the players with highest skills are in finals
			else
				no++;					//assign 'no' if the players with highest skills were not in finals
		}
		if(yes == 1)
			cout<<"YES"<<endl;			//print 'YES' for a fair playoff
		else 
			cout<<"NO"<<endl;			//print 'NO' for an unfair playoff
	}
	return 0;
}
