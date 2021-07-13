/*
In recreational number theory, a narcissistic number is also known
as a pluperfect digital invariant (PPDI), an Armstrong number or a
plus perfect number is a number that is the sum of its digits
each raised to the power of the number of digits.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check whether the Number is Armstrong Number or Not.

bool is_armstrong(int n) {
	if (n < 0) {
		return false;
	}
	int sum = 0;
	int var = n;
	int number_of_digits = floor(log10(n) + 1);
	while (var > 0) {
		int rem = var % 10;
		sum = sum + pow(rem, number_of_digits);
		var = var / 10;
	}
	return n == sum;
}

int main() {
	cout << "Enter the Number to check whether it is Armstrong Number or Not:" << endl;
	int n;
	cin >> n;
	if (is_armstrong(n))
		cout << n << " is Armstrong Number." << endl;
	else
		cout << n << " is Not Armstrong Number." << endl;
	return 0;
}

/*
Time Complexity: O(log(n))
Space Complexity: O(1)
*/
