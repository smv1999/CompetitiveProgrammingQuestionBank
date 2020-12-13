/*Characters or SumDigits

Given a string input1, having alphabets or digits or both, find the sum of digits of extract only the characters depending on input2.

Prototype string findCharsOrDigitSum(string input1, int input2) input1 - String having alphabets or digits or both.

Input2 - Either O or 1

If input2 = 0, find the sum of digits from string input If input 2 = 1, extract only ALPHABETS from string input1

Rules:

• If there are no DIGITS in the given string and input2 is 0, result would be ZERO

• If there are no ALPHABETS in the given string and input2 is 1, result would again

be ZERO

• If the given string is null (or empty) and if input2 is either 0 or 1, result would be NULL

• No special characters or spaces are allowed in string input1

Example 1:

input1 = 1W213p4506

input2 = 0

output = 21

Explanation: Since Input 2 is 0, consider reading only digits and sum up them, 1+2+3+4+5+6 = 21 Hence output would be 21 in form of string
*/

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str, res = "";
    cin >> str;
    int choice;
    cin >> choice;
    int sum = 0;
    bool digFound = false, alphaFound = false;
    if (choice == 0)
    {
        for (char c : str)
        {
            if (isdigit(c))
            {
                digFound = true;
                sum += c - '0';
            }
        }
        if (digFound)
            res += to_string(sum);
    }
    else if (choice == 1)
    {
        for (char c : str)
        {
            if (isalpha(c))
            {
                alphaFound = true;
                res += c;
            }
        }
    }
    if (!digFound && choice == 0)
    {
        res += "ZERO";
    }
    else if (!alphaFound && choice == 1)
    {
        res += "ZERO";
    }
    else if (str.empty())
    {
        res += "NULL";
    }
    cout << res;
    return 0;
}
