/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
#include <bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        if(num1.size()>num2.size())swap(num1, num2);
        int num1_len = num1.size(), num2_len = num2.size();
        int res[num1_len+num2_len];memset(res, 0, sizeof res);
        for(int i=num1_len-1;i>=0;i--){
            for(int j=num2_len-1;j>=0;j--){
                int p1 = i+j, p2 = p1+1;
                int sum = (num1[i]-'0')*(num2[j]-'0') + res[p2];
                res[p2] = sum%10;
                res[p1] += sum/10;
            }
        }
        string output = ""; int idx = -1;
        for(int i=0;i<num1_len+num2_len && res[i] == 0;i++)
            idx = i;
        for(int i=idx+1;i<num1_len+num2_len;i++)
            output += to_string(res[i]);
        return output;
    }
int main(){
    string num1,num2;
    cin>>num1;
    cin>>num2;
    cout<<multiply(num1, num2);
}