
#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;
int mx = INT_MAX;
bool isPalindrome(int i)
{
  string s1 = "";
  string s = to_string(i);
  s1.append(s);
  reverse(s1.begin(), s1.end());
  if (s.compare(s1) == 0)
    return true;
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