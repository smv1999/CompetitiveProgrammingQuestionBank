/*
Problem Statement:
 Given a stack, sort the given stack using recursion such that the greatest element is on the top. 
*/

#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> st)
{
  while (!st.empty())
  {
    int x = st.top();
    st.pop();

    cout << x << " ";
  }

  return;
}

void insert(stack<int> &st, int temp)
{
  // base condition
  if (st.size() == 0 || st.top() < temp)
  {
    st.push(temp);
    return;
  }

  int val = st.top();
  st.pop();

  insert(st, temp);
  st.push(val);

  return;
}

void sortStack(stack<int> &st)
{
  // base condition
  if (st.size() == 0)
    return;

  int temp = st.top();
  st.pop();

  // recursion
  sortStack(st);

  // function to insert element in stack
  insert(st, temp);

  return;
}

int main()
{
  // input number of element in stack
  int n;
  cout<<"Enter the number of elements : ";
  cin >> n;

  stack<int> st;
  cout<<"Enter the elements : ";
  // input stack elements
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    st.push(x);
  }
  cout<<"After Sorting : ";
  // function to sort stack
  sortStack(st);

  // function to print stack element
  printStack(st);

  cout << endl;

  return 0;
}

/*
  Time Complexity: O(N*N)
  Space complexity: O(N)

  SAMPLE INPUT AND OUTPUT
  Enter the number of elements : 10
  Enter the elements : 9 2 5 6 0 1 7 3 4 8
  After Sorting : 9 8 7 6 5 4 3 2 1 0         
*/