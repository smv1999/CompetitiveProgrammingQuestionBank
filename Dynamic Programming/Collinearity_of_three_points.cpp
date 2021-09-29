/*
Problem Statement
Given 3 co-ordinates , find if they are collinear or not .
Three or more points are said to be collinear if they all lie on the same straight line.
*/

#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

/*
We can calculate the area formed by the three points, and if the area is
zero then they lie on a same line. 
*/
bool check_collinear(Point a, Point b, Point c) {
    int area = 0;

    /*
    The Area of a Triangle formed by three points (x1, y1), (x2, y2), (x3, y3)
    is determined by the following formula
    
    Area = (1/2) * {x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)}     
    */
    area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);

    if (area == 0)
        return true;
    else
        return false;
}

int main() {
    int x, y;
    Point a, b, c;
    cout << "\nEnter the first co-ordinates:  ";
    cin >> a.x >> a.y;
    cout << "Enter the second co-ordinates: ";
    cin >> b.x >> b.y;
    cout << "Enter the third co-ordinates:  ";
    cin >> c.x >> c.y;

    if (check_collinear(a, b, c)) {
        cout << "\nThe given points are collinear" << endl;
    } else {
        cout << "\nThe given points are not collinear" << endl;
    }
    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

Enter the first co-ordinates:  1 1
Enter the second co-ordinates: 2 2
Enter the third co-ordinates:  3 3

The given points are collinear
*/