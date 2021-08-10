//We have given an integer N. We have to find out the smallest next palindrome of that integer value.
//suppose we have given 113 as a number so the next smallest palindrome number is 121.

// Intution :- Take a loop from N+1 to INFINITE and call a function ispalindrome which will check wheather the number is palindrome or not.
//In isPalindrome function we will convert the integer into string and then reverse that string , compare original string to reversed one and if both are same return true.
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
int mx = INT_MAX;
bool isPalindrome(int i)
{
  string s1 = "";                    //take a empty string to copy original string
  string s = to_string(i);          //convert integer to string
  s1.append(s);                    //append  original string to s1.
  reverse(s1.begin(), s1.end());    //reverse copied string
  if (s.compare(s1) == 0)           //comparing both string
    return true;                    //if both are equal return true else return false
  return false;
}
int main()
{
  int N;
  cout << "Enter the number : ";
  cin >> N;
  for (int i = N+1; i <= mx; i++)
  {
    if (isPalindrome(i))
    {
      cout << "Next smallest palindrome digit after " << N << " is " << i;
      break;
    }
  }

  return 0;
}
