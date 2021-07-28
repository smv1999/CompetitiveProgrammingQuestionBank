/* Given a string A consisting only of lowercase characters, we need to check whether it is possible to make
this string a palindrome after removing exactly one character from this.

If it is possible then print "1" else print "0" (without quotes).
3 <= |A| <= 105
A[i] is always a lowercase character.

Input Format
First and only argument is an string A.

Output Format
Print 1 if it is possible to convert A to palindrome by removing exactly one character else print 0.
 */


# include<bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin>>A;
    int n = A.size();   //n is the size of the given string
    int i=0, j=n-1, count=0;
    while(i<j)          // using two pointer approach with O(n) time complexity
    {
        if(A[i] == A[j])     //comparing first and last character of string
        {
            i++;
            j--;
        }
        else  if(A[i+1]==A[j] && count == 0)
        {
            count++;
            i++;
        }
        else if(A[i]==A[j-1] && count == 0)
        {
            count++;
            j--;
        }
        else break;
    }
    if(i<j)
        cout<<"0"<<endl;
    else
        cout<<"1"<<endl;
}

