/*

Implementation of Truck tour problem from Hackerrank

Suppose there is a circle. There are N petrol pumps on that circle. 
Petrol pumps are numbered 0 to (N-1) (both inclusive). You have two pieces 
of information corresponding to each of the petrol pump:
(1) the amount of petrol that particular petrol pump will give, and
(2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. 
You can start the tour at any of the petrol pumps. Calculate the first 
point from where the truck will be able to complete the circle. Consider 
that the truck will stop at each of the petrol pumps. The truck will 
move one kilometer for each litre of the petrol.

Link to the problem: https://www.hackerrank.com/challenges/truck-tour/problem
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int petrol[n], distance[n];
    for (int i = 0; i < n; i++)
    {
        cin >> petrol[i];
        cin >> distance[i];
    }
    //the amount of petrol left in the truck
    int amountofpetrol = 0;        
    
    //the total amount of petrol we were short of in each petrol pump
    int previous = 0; 
	
	//stores the index of the starting point      	   
    int startindex = 0;   
	         
    for(int i = 0; i < n; i++)
    {
    	//calculating amount of petrol left
        amountofpetrol += (petrol[i] - distance[i]);
		
		//true means that route does not exists from the current starting point	
        if(amountofpetrol < 0)		
        {
            previous = previous + amountofpetrol;
            amountofpetrol = 0;
            
            //start agaain from starting point
            startindex = i + 1;		
        }
    }
    //returns starting point
    cout << startindex <<endl;		
    return 0;
}

/* Time complexity: O(n)

Example 1:

Sample Input

3
1 5
10 3
3 4

Sample Output

1

Example 2:

Sample Input

3
6 4
3 6
7 3

Sample Output

2*/