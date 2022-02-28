https://codeforces.com/contest/189/problem/A
#include<bits/stdc++.h>
    using namespace std;
 
    // Reference : https://www.geeksforgeeks.org/maximize-the-value-of-x-y-z-such-that-ax-by-cz-n/
 
    int maxResult(int n, int a, int b, int c)
    {
        int maxVal = 0;
    
        // i represents possible values of a * x
        for (int i = 0; i <= n; i += a)
        {
            // j represents possible values of b * y
            for (int j = 0; j <= n - i; j += b)
            {
                float z = (float)(n - (i + j)) / (float)(c);
    
                // If z is an integer
                if (floor(z) == ceil(z))
                {
                    int x = i / a;
                    int y = j / b;
                    maxVal = max(maxVal, x + y + (int)z);
                }
            }
        }
    
        return maxVal;
    }
     
    int main()
    {   
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        int a[3];
        for( int i = 0; i < 3; ++i){
            cin >> a[i];
        }
        cout << maxResult(n , a[0] ,a[1], a[2]); 
        return 0;
    }
