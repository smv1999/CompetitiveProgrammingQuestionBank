/* You're given the length of three sides a, b, and c respectively. 
Now If these three sides can form an Equilateral Triangle then print 1, if these three sides can form an Isosceles Triangle then print 2, 
if these three sides can form a Scalene Triangle then print 3, otherwise print −1.*/

/* Input:

·       First-line will contain three numbers a, b, and c separated by space.

Output:

Print the answer in a new line.

Constraints

·       1≤a,b,c≤103

Sample Input 1:

            2 4 3

Sample Output 1:

            3

Sample Input 2:

            4 4 4

Sample Output 2:

            1

Sample Input 3:

            4 4 9

Sample Output 2:

            -1

EXPLANATION:

·       In the first example, (2, 4, 3) will form a Scalene Triangle.

·       In the second example, (4, 4, 4) will form an Equilateral Triangle.

·       In the third example, (4, 4, 9) will not form a triangle.

*/


#include <iostream>
using namespace std;

int main()
{
    int a, b, c; 
    cin >> a >> b >> c; 
    if (a + b > c && b + c > a && c + a > b) // condition for a triangle.
    {
        if (a == b && b == c) // condition for equilateral triangle.
            cout << "1";
        else if (a == b || b == c || c == a) // condition for isosceles triangle.
            cout << "2";
        else
            cout << "3"; 
    }
    else
        cout << "-1"; 
    return 0;
}
