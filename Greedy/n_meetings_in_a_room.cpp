/*
There is one meeting room in a firm.
There are N meetings in the form of (S[i], F[i]) where S[i] is 
start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room 
when only one meeting can be held in the meeting room at a particular time?

Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
*/



#include <bits/stdc++.h>
using namespace std;



/* 
Method followed:
- make a vector of pair of meeting's start and end time
- sort this vector with respect to the end time
- count the first meeting and set time limit as the end of first meeting
- traverse the vector
    - if start time of any meeting is greater than time limit.
        - increment count
        - set time limit as end time of this meeting

*/
class Solution
{
    public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.second<b.second){
            return true;
        }
        return false;
        
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> m;
        for(int i=0;i<n;i++){
            m.push_back(make_pair(start[i],end[i]));
        }
        
        sort(m.begin(),m.end(),comp);
        
        
        
        int currMeet=m[0].first;
        
        int timeLimit = m[0].second;
        
        int count=1;
        
        for(int i=1;i<n;i++){
            auto a=m[i];
            if(a.first>timeLimit){
                count++;
                timeLimit=a.second;
            }
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  