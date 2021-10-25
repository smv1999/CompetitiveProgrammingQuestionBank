/* C++ program to print a given number in words. The program
handles numbers from 0 to 9999 
Just take an example  if the user privide the number
INPUT-
1-No of test cases
1234-the given number
OUTPUT- 
One thousand Two hundred and twenty four */
#include<bits/stdc++.h>
using namespace std;
string one[] = { "", "one ", "two ", "three ", "four ",
        "five ", "six ", "seven ", "eight ",
        "nine ", "ten ", "eleven ", "twelve ",
        "thirteen ", "fourteen ", "fifteen ",
        "sixteen ", "seventeen ", "eighteen ",
        "nineteen " };

// strings at index 0 and 1 are not used, they is to
// make array indexing simple
string ten[] = { "", "", "twenty ", "thirty ", "forty ",
        "fifty ", "sixty ", "seventy ", "eighty ",
        "ninety " };
/* ******* Your Functions Below ******** */


// n is 1- or 2-digit number
string numToWords(int n, string s)
{
  string str = "";
  // if n is more than 19, divide it
  if (n > 19)
    str += ten[n / 10] + one[n % 10];
  else
    str += one[n];

  // if n is non-zero
  if (n)
    str += s;

  return str;
}

// Function to print a given number in words
string convertToWords(long n)
{
  // stores word representation of given number n
  string out;

  // handles digits at ten millions and hundred
  // millions places (if any)
  out += numToWords((n / 10000000), "crore ");

  // handles digits at hundred thousands and one
  // millions places (if any)
  out += numToWords(((n / 100000) % 100), "lakh ");

  // handles digits at thousands and tens thousands
  // places (if any)
  out += numToWords(((n / 1000) % 100), "thousand ");

  // handles digit at hundreds places (if any)
  out += numToWords(((n / 100) % 10), "hundred ");

  if (n > 100 && n % 100)
    out += "and ";

  // handles digits at ones and tens places (if any)
  out += numToWords((n % 100), "");

  return out;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
{
    long n ;
  cin>>n;

  // convert given number in words
  cout << convertToWords(n) << endl;


}
}

/*Time complexity:
Time complexity: O(1). 
The loop runs for a constant amount of time.
Auxiliary space: O(1). 
As no extra space is required.
Time complexity: O(1). */


	
	
