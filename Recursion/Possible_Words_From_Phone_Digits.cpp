/*
Possible Words From Phone Digits
Medium Accuracy: 51.47% Submissions: 11922 Points: 4
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.


Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi
bdg bdh bdi beg beh bei bfg bfh bfi
cdg cdh cdi ceg ceh cei cfg cfh cfi
Explanation: When we press 2,3,4 then
adg, adh, adi, ... cfi are the list of
possible words.
Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil
egj egk egl ehj ehk ehl eij eik eil
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then
dgj, dgk, dgl, ... fil are the list of
possible words.
Your Task:
You don't need to read input or print anything. You just need to complete the function possibleWords() that takes an array a[ ] and N as input parameters and returns an array of all the possible words in lexicographical increasing order.

Expected Time Complexity: O(4N * N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10
2 ≤ a[i] ≤ 9
*/

//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.


    void formstring(int a[], int N, string s, vector<string>&v, int i,map<int, vector<char>>m){
        if(i == N){
            v.push_back(s);
            return;
        }
        int pos = a[i];
        for(auto j : m[pos]){
            formstring(a,N,s+j,v,i+1,m);
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        map<int, vector<char>>m;
        int k = 0;
        for(int i = 2;i<=6;i++){
            int j = 0;
            while(j<3){
                m[i].push_back('a'+ j + k);
                j++;
            }
            k+=3;
        }
        m[7] = {'p','q','r','s'};
        m[8] = {'t','u','v'};
        m[9] = {'w','x','y','z'};

        vector<string>ans;
        formstring(a,N,"",ans,0,m);
        return ans;
    }
};


// { Driver Code Starts.

int main() {

	int T;

	cin >> T; //testcases

	while(T--){ //while testcases exist
	   int N;

	   cin >> N; //input size of array

	   int a[N]; //declare the array

	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }

	   Solution obj;

	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}

	return 0;
}  // } Driver Code Ends
