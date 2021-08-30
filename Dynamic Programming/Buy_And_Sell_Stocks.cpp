/* problem statement
first input is n representing the number of days 
after that we have n values ,representing the price of stock on that day
output should be maximum profit , if you can buy and sell only one time
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;   // it represent the number of days
    int arr[n]; // this array contains the prices of stock on that day
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int lsf = 9999999; //least so far
    int op = 0;        //overall profit
    int pist = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < lsf)
        {
            lsf = arr[i];
        }
        int pist = arr[i] - lsf; // if stock is sold today
        if (pist > op)
        {
            op = pist;
        }
    }
    cout << op << endl;
}

/* sample input values are
9
11
6
7
19
4
1
6
18
4
*/

/*sample output value for the upper input
17
*/
