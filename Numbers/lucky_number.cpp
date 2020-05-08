/*
A number is considered lucky if it contains either 3 or 4 or 3 and 4 both in it. Write a program
to print the nth lucky number.  First few numbers in the number system are: 3, 4, 33, 34, 43, 44, 
333, 334, 343, 344, 433, 434, 443, 444, 3333, 3334, 3343, 3344, 3433, 3434, 3443, 3444, …

Input
3

Output
33

*/
#include<iostream>
using namespace std;
void find(int n) 
{ 
    string arr[n+1]; 
    arr[0] = "";  
  
    int size = 1, m = 1; 
  
    while (size <= n) 
    { 
        
        for (int i=0; i<m && (size+i)<=n; i++) 
            arr[size + i] = "3" +  arr[size - m + i]; 
       
        for (int i=0; i<m && (size + m + i)<=n; i++) 
            arr[size + m + i] = "4" +  arr[size - m + i]; 
  
        m = m<<1; 
  
        size = size + m; 
    } 
    cout << arr[n] << endl; 
} 
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    find(n);
    return 0;
}
