/*
We have to find all elements of power set of given set as string using bit  manipulation


Example 1:
I/p : "sd"
O/p : "", "s", "d", "sd"

Example 2:
I/p : "abc"
O/p : "", "a", "b", "c", "ab", "bc", "ac", "abc"

Formula for Power Set: 2^n , where n is number of elements present in set.

Here, we will be using the formula mentioned above
in the function printPowerSet. 
In function printPowerSet Outer function has complexity of 2^n
and inner funtion has complexity of n.
So Time Complexity = Theta(2^n * n)

*/

#include<iostream>
#include<bits/stdc++.h>  // we can also use cmath but bits/stdc++.h is prefered more
using namespace std;

int printPowerSet(string str)  // function to print all elements of power set
{
    int n = str.length();
    int pow_Size = pow(2, n);

    for (int counter = 0; counter < pow_Size; counter++) // This for loop will run for 2^n times i.e. to find all elements for powerset
    {
        for (int j = 0; j < n; j++) // This will run for total n times to print elements where the bit is set.
        {
            if ((counter & (1 << j)) != 0) // Check every bit and if bit is set then prints the element of that index.
            {
                cout << str[j];
            }
        }
        cout << endl;
    }

}

int main()
{
    string str = "abc";   // string to be passed

    printPowerSet(str);

    return 0;
}