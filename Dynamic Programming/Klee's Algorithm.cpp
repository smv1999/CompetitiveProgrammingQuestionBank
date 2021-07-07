/*    
    Description: Given a Point with x and y coordinates,this algorithm finds the union of the
                 lengths covered by all these line segments.
    This algorithm was proposed by Klee in 1977 and is asymptotically the fastest.     */


#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

//Structure to store the point coordinates.
typedef struct points {
	int x, y;
}points;

//vector to indicate the points in the plane.
vector<points>plane;

//function to find the union of the lengths.
int find_union(vector<points>line) {

	int size = line.size();

	//This vector first stores the coordinate and then the bool value.
	//Here,the starting coordinate is marked false and the ending coordinate as true in pair.
	vector<pair<int, bool>> points(size * 2);

	for (int i = 0; i < size; i++)
	{

		points[i * 2] = make_pair(line[i].x, false);
		points[i * 2 + 1] = make_pair(line[i].y, true);

	}

	//This is to sort all the ending points.
	sort(points.begin(), points.end());

	//Initializing variable answer which will store the final length and counter which will keep track of the opening and closing segment.
	int answer = 0, counter = 0;

	//traversing through all the ending points
	for (int i = 0; i < size * 2; i++)
	{
		//for adding the difference of current and previous points to answer.
		if (counter)
			answer += (points[i].x - points[i - 1].x);

		//for the endpoint of the segment, decrements the counter or else increment the counter.
		if (points[i].y)
			counter--;
		else
			counter++;
	}

	return answer;
}

int main()
{

	//declaration of the number of points.
	int n;

	cout << "Enter the desired number of points:\n";
	cin >> n;
	cout << "Enter the x and y coordinates for the points with a space:\n";

	plane.resize(n);

	//For input of x and y coordinates of the desired points
	for (int i = 0; i < n; i++)
	{
		cin >> plane[i].x >> plane[i].y;
	}

	//Outputs the final length of the union the length of segments.
	cout << "The union of the length of the line segments is :\n";

	int ans = find_union(plane);

	cout << ans;
	return 0;

}

/*    Time Complexity: O(N log N)
      Space Complexity: O(N)        */

/* Test Case:
*
Sample Input: Enter the desired number of points:
			  4
			  Enter the x and y coordinates for the points with a space:
			  2 4
			  5 6
			  3 7
			  1 6
Sample Output: The union of the length of the line segments is:
			  6
			  */