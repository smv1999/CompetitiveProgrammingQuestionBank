/*Write a program to find the count of numbers which consists of unique digits.

Input:

Input consist of two Integer lower and upper value of an range


Output:

Output consists of single line, print the count of unique digits in given range. Else Print"No Unique Number"


Solution:


Input -

10

15

Output:
5
*/
#include<bits/stdc++.h>

using namespace std;

int printUniqueCount(int l, int r)
{
    set<int> st;
    int dupFound, count=0, num;
    for(int i=l;i<=r;i++)
    {
        dupFound = 0;
        num = i;
        while(num)
        {
            if(st.find(num%10) != st.end())
                dupFound=1;
            else st.insert(num%10);
            num = num / 10;
        }
        if(dupFound!=1)
            count++;
        st.clear();
    }
    return count;
}

int main()
{
    int l,r;
    cin>>l>>r;
    cout<<printUniqueCount(l,r);

    return 0;
}
