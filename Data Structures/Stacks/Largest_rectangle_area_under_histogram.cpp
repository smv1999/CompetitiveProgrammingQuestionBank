/*
Given the heights of the bars of a histogram, find out the largest
rectangular area under the histogram. Width of each bar is 1 unit.
*/

#include <bits/stdc++.h>
using namespace std;

// Prints largest rectangular area under histogram
void largestAreaUnderHistogram(int height[], int n)
{

	// Stores index of the bars
	stack<int> s;
	int ans = 0;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++)
	{

		// If stack is empty, push the bar
		if (s.empty())
		{
			s.push(i);
			continue;
		}

		// If height[i] is greater then push the bar
		if (height[i] > height[s.top()])
		{
			s.push(i);
		}
		else
		{
			// I have encountered a height that is less than my last height

			// Pop out all bars whose height is greater than height[i],
			// Simulataneously calculate the new area
			while (!s.empty() && height[i] < height[s.top()])
			{
				int toBeRemoved = s.top();
				s.pop();
				int area;
				if (s.empty())
				{
					area = height[toBeRemoved] * i;
				}
				else
				{
					area = height[toBeRemoved] * (i - s.top() - 1);
				}
				//cout << toBeRemoved << " " << area << endl;
				if (area > ans)
				{
					ans = area;
					l = (!s.empty()) ? s.top() : 0;
					r = i;
				}
				ans = max(ans, area);
			}
			s.push(i);
		}
	}
	cout << "Largest area = " << ans << " between bars " << l << " and " << r;
}

int main()
{

	// Input number of bars
	cout << "Enter number of bars: ";
	int n;
	cin >> n;
	// Input heights
	cout << "Enter height of each bar: ";
	int height[n];
	for (int i = 0; i < n; i++)
		cin >> height[i];

	largestAreaUnderHistogram(height, n);
}

/*
Time Complexity: O(n)
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT 
Enter number of bars: 7
Enter height of each bar: 6 2 5 4 5 1 6
Largest area = 12 between bars 1 and 5
*/