/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows)

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Constraints:
 1 <= s.length <= 1000
 s consists of English letters (lower-case and upper-case), ',' and '.'.
 1 <= numRows <= 1000

*/

/*
Time Complexity: O(N), where N is the length of the array
Space Complexity: O(N), where N is the length of the array
*/

#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    vector<vector<char>> a(numRows); // vector of vector to store character in each rows
    int i = 0; // variable to determine in which row we must add particular character
    bool direction = true; // variable to determine the direction of movement
    for (char ch : s)
    {
        a[i].push_back(ch);
        if (direction == true) // if direction is down => increment i
            i++;
        if (i == numRows) // if i reached end => reverse the direction and decrement i
        {
            direction = false;
            i--;
        }
        if (direction == false) // if direction is up => decrement i
            i--;
        if (i <= 0) // if i reached start => reverse the direction and set i to 0
        {
            direction = true;
            i = 0;
        }
    }

    string str = ""; // forming the final string to return
    for (vector<char> c : a)
    {
        for (char ch : c)
            str += ch;
    }
    return str;
}

int main() // driver function
{
    string str = "PAYPALISHIRING";
    string ans = convert(str,3);
    cout << ans;
    return 0;
}