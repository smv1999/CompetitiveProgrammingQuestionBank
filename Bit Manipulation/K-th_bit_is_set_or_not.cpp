// Given a number N and a bit number K, check if the Kth bit of N is set or not.Position of set bit '1' should be indexed starting with 0 from the LSB side in the binary representation of the number.

// Example
// Input: N = 4, K = 0
// Output: No

// Time Complexity: O(LogN)
// Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k)
    {
        if((1<<k)&n)
            return true;
        else
            return false;
    }
int main()
{
    int t;
    cin>>t;//taking testcases
    while(t--)
    {
        long long n;
        cin>>n;//input n
        int k;
        cin>>k;//bit number k
        
        if(checkKthBit(n, k))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}  
