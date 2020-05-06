/*
Inner Reduce Pattern Printing

Given a number N, the program must print the pattern as follows:

Input
4

Output

4444444
4333334
4322234
4321234
4322234
4333334
4444444


*/
#include <bits/stdc++.h> 
using namespace std; 

#define max 100 

void print(int a[][max], int size) 
{ 
for (int i = 0; i < size; i++) { 
	for (int j = 0; j < size; j++) { 
	cout << a[i][j]; 
	} 
	cout << endl; 
} 
} 

void innerPattern(int n) { 
	
int size = 2 * n - 1; 
int front = 0; 
int back = size - 1; 
int a[max][max]; 
while (n != 0) 
{ 
	for (int i = front; i <= back; i++) { 
	for (int j = front; j <= back; j++) { 
		if (i == front || i == back || 
			j == front || j == back) 
		a[i][j] = n; 
	} 
	} 
	++front; 
	--back; 
	--n; 
} 
print(a, size); 
} 

int main() 
{ 
	int n; 
    cin>>n;
	innerPattern(n); 
	
return 0; 
} 

