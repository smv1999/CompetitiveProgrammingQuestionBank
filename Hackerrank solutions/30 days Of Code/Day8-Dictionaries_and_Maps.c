/* PROBLEM STATEMENT
Given n names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. 
You will then be given an unknown number of names to query your phone book for. 
For each  name queried, print the associated entry from your phone book on a new line in the form name=phoneNumber; 
if an entry for name  is not found, print Not found instead.

Note: Your phone book should be a Dictionary/Map/HashMap data structure.

Input Format

The first line contains an integer,n , denoting the number of entries in the phone book.
Each of the n subsequent lines describes an entry in the form of 2 space-separated values on a single line. 
The first value is a friend's name, and the second value is an 8-digit phone number.

After the n lines of phone book entries, there are an unknown number of lines of queries. 
Each line (query) contains a name to look up, and you must continue reading lines until there is no more input.

Note: Names consist of lowercase English alphabetic letters and are first names only.

Output Format

On a new line for each query, print Not found if the name has no corresponding entry in the phone book; otherwise,
print the full  name and  phone number in the format name=phoneNumber.

Sample Input

3
sam 99912222
tom 11122222
harry 12299933
sam
edward
harry
 
 Sample Output

sam=99912222
Not found
harry=12299933
Explanation

We add the following n=3 (Key,Value) pairs to our map so it looks like this:
phonebook={ (sam ,99912222),(tom, 11122222),(harry, 12299933)}

We then process each query and print key=value if the queried  is found in the map; otherwise, we print Not found.

Query 0: sam
Sam is one of the keys in our dictionary, so we print sam=99912222.

Query 1: edward
Edward is not one of the keys in our dictionary, so we print Not found.

Query 2: harry
Harry is one of the keys in our dictionary, so we print harry=12299933.     */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
   
    int n;
string name;
long num;
cin >> n; 
cin.ignore();
map <string, long> pBook;
for (int i = 0; i < n; i++) {
    cin >> name;
    cin >> num;
    pBook[name] = num;
}
while(cin >> name) {
    if (pBook.find(name) != pBook.end())
     //pBook.end means that it has reached to the last element of pBook. 
        //so if we use != , it means that it has not reached to the end. Thus it means that the name is found somewhere in the middle of pBook.
    {
      
        cout << name << "=" << pBook.find(name)->second << endl;
      //map.find() iterates through your map structure. if it finds the element then it returns an iterator to that element else it returns end. 
      //End being an element past the last element of that container, essentially telling you it wasn't found.
      //Remember containers in c++: arrays, vectors, maps, queues, stacks, etc. start at 0. 
      //So if you have a map container with 10 elements and an index of 10 is returned this is outside the bounds of the container so in this function end is returned.
     
    } else {
        cout << "Not found" << endl;
    }
}  
    return 0;
}

// Time Comlexity: O(n)
// Space Complexity: O(1)
