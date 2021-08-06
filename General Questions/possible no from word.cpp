/* C++ program to print a given number in words. The program
handles numbers from 0 to 9999 
Just take an example  if the user privide the number
INPUT-
1-No of test cases
1234-the given number
OUTPUT- 
One thousand Two hundred and twenty four */

#include <bits/stdc++.h>
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             LONG_LONG_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define endl            '\n'
#define mk(arr,n,type)  type *arr=new type[n]
#define w(x)            int x; cin >> x; while(x--)
#define f(i,x,y)        for(int i = x; i < y; i++)
#define g(i,x,y)        for(int i = x;i<=y;i++)



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



void c_p_p()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
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

/* ******* Your Functions Above ******** */

int32_t main()
{
	c_p_p();
	#ifndef ONLINE_JUDGE
	// For getting input from input.txt file 
    // For getting input from input.txt file 
    freopen("inpute.exe", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.exe", "w", stdout); 
#endif
    int t;
    cin>>t;
    
    while(t--)
{
    long n ;
  cin>>n;

  // convert given number in words
  cout << convertToWords(n) << endl;
   

}
return 0;
}
/*Time complexity:
Time complexity: O(1). 
The loop runs for a constant amount of time.
Auxiliary space: O(1). 
As no extra space is required.
Time complexity: O(1). */


	
	
