//Problem Statement Link https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

//Example Test Case
//Input
//  n        -> Size of Array
//  arr[]    -> Array
//  m        -> No. of Students
/*

n = 4
arr[] = {12,34,67,90}
m = 2

Here possible allocations can be: 

1. {12}, {34, 67, 90} i.e one student reads 12 pages and another 
   reads 191 (34+67+91) pages, so here maximum is 191

2. {12,34}, {67,90} i.e one student reads  46 (12+34) pages and another 
   reads 158 (67+91) pages, so here maximum is 158

3. {12,34, 67} i.e one student reads  113 (12+34+67) pages and another 
   reads 91 pages, so here maximum is 113

Out of three cases minimum maximum is 113 so that would be printed in the output

*/

//The program for this problem goes as follows

//Header file to include all header files of C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m)
    {
        // we store the maximum of array in min i.e a student can read atleast
        // one book (with max pages) from the given array of books
        int min = findMax(arr, n);

        //we store suma of all books in max variable
        int max = findSum(arr, n);

        // ans is minimum of maximum pages that can be assigned to a student
        int ans = -1;

        //Applying Binary Search
        while (min <= max)
        {
            int mid = (min + max) / 2;

            //calling isFeaible function to check whether we can have mid as the
            //minimum maximum no. of pages possible

            //If yes, assign mid to ans and check further with smaller values.
            if (isFeasible(arr, n, m, mid))
            {
                ans = mid;
                max = mid - 1;
            }

            //If no, increment the min and check further with larger values
            else
            {
                min = mid + 1;
            }
        }

        //return the final ans
        return ans;
    }

    // A utility function to find sum of array elements
    static int findSum(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    // A utility function to find max of all array elements
    static int findMax(int arr[], int n)
    {
        int max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (max < arr[i])
                max = arr[i];
        }
        return max;
    }

    // A function to check wheter it is feasible to allocate 'mid' no of pages
    // to m students
    static bool isFeasible(int arr[], int n, int m, int mid)
    {
        int student = 1;
        int sum = 0;

        //Iterating over the array elements
        for (int i = 0; i < n; i++)
        {
            //if the current sum is less than mid, add it into the sum variable
            if (sum + arr[i] <= mid)
            {
                sum += arr[i];
            }

            //else increment the number of students and reassign sum with array element
            else
            {
                student++;
                sum = arr[i];
            }
        }

        // finally return whether no of students are less than or equal to m
        return (student <= m);
    }
};

// Main Function
int main()
{

    // t -> No of Test Cases
    // n -> Size of Array
    // A -> Array
    // m -> No of Students
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];

        //Input Array Elements
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;

        //making object of class
        Solution ob;

        //calling findPages Method and displaying the final ans
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
