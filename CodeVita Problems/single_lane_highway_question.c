// Single Lane Highway
// Problem Description
// Certain number of cars are passing a single lane road. Speeds of all cars vary. It is easy to see, that depending on the speeds of the cars various groups will be formed.

// Being a single lane road passing/overtaking is not allowed. Given speeds of cars, calculate how many groups can be formed if all possible permutations are taken into account. Refer example1 for better understanding.

// Print number of groups divided by the number of permutations.

// Constraints
// 0 <= N < 10 ^ 5

// 0 <= speed of individual vehicle < 10 ^ 9

// Input
// First line contains an integer N, which denotes the number of vehicles

// Second line contains N space separated integers which denotes the speed of individual vehicle.

// Output
// Print number of groups divided by the number of permutations rounded upto 6 decimal places.

// Time Limit
// 1

// Examples
// Example 1

// Input

// 3

// 10 20 30

// Output

// 1.833333

// Explanation:

// So all possible permutations are:

// {10 20 30}

// {10 30 20}

// {20} {10 30}

// {20 30} {10}

// {30} {10 20}

// {30 20} {10}

// So here there are total 6 permutations, and total number of groups are 11.

// So, output is 11/6 = 1.833333


// Example 2

// Input

// 4

// 56 78 13 92

// Output

// 2.083333

// Explanation:

// So here there are total 24 permutations,

// For example:

// {56 78 13 92}

// {92} {13 78 56}

// {56} {13 92 78}

// {78 92} {13 56}

// .

// .

// So on and so forth. The total number of groups are 50.

// So, the output is 50/24 = 2.083333

#include<stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int car_speed[n];
  for(int speed_ind=0;speed_ind<n;speed_ind++)
    scanf("%d", &car_speed[speed_ind]);

  if (n == 0 || n==1)
  {
    printf("%0.6f",(float)n);
    return 0;
  }

  double sum=0;
  
  for(int i=1;i<=n;i++)
  {
    sum += 1.0/i;
  } 
  printf("%0.6f",sum);
 
  return 0;

}
