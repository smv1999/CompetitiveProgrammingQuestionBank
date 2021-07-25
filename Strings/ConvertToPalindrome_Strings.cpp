# include<bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin>>A;
    int n = A.size();
    int i=0, j=n-1, count=0;
    while(i<j)
    {
        if(A[i]==A[j])
        {
            i++;
            j--;
        }
        else  if(A[i+1]==A[j] && count == 0)
        {
            count++;
            i++;
        }
        else if(A[i]==A[j-1] && count == 0)
        {
            count++;
            j--;
        }
        else break;
    }
    if(i<j)
        cout<<"0"<<endl;
    else
        cout<<"1"<<endl;
}

