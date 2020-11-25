/*Finding common elements between two arrays in which the elements are distinct.
Eg:

1 2 3 4 5 12 8
6 7 3 4 2 9  11

1 2 3 4 5 8 12
2 3 4 6 7 9 11

O/P:
2 3 4 
*/
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n1,n2,a;

    cin>>n1;
    vector<int> v1,v2,v3;
    for(int i=0;i<n1;i++)
    {   cin>>a;
        v1.push_back(a);
    }
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cin>>a;
        v2.push_back(a);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    // Two Pointer Method
    int j=0,k=0;
    while(j<v1.size() && k<v2.size())
    {
        if(v1[j]==v2[k])
        {
            v3.push_back(v1[j]);
            j++;
            k++;
        }
        else if(v1[j]<v2[k])    
            j++;
        else 
            k++;    
    }
    for(int i:v3)
        cout<<i<<" ";
    return 0;
}
