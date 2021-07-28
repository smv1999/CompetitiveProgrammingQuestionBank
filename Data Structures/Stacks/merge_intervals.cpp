// Given a set of time intervals in any order, merge all overlapping intervals
// into one and output the result which should have only mutually exclusive
// intervals. Let the intervals be represented as pairs of integers for
// simplicity. For example, let the given set of intervals be {{1,3}, {2,4},
// {5,7}, {6,8}}. The intervals {1,3} and {2,4} overlap with each other, so they
// should be merged and become {1, 4}. Similarly, {5, 7} and {6, 8} should be
// merged and become {5, 8}.

// Write a function that produces the set of merged intervals for the given set
// of intervals.

#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int start, end;
};

bool compare(Interval i1, Interval i2) { return (i1.start < i2.start); }

void mergeIntervals(Interval arr[], int n)
{
    if (n <= 0)
        return;
    stack<Interval> s;
    sort(arr, arr + n, compare);
    s.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        Interval top = s.top();

        if (top.end < arr[i].start)
            s.push(arr[i]);

        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}

int main()
{
    Interval arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
