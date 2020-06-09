#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;


bool f(int x,int y)
{
    return x>y;
}
void vectorDemo()
{
    vector<int> A = {11,2,3,5,18,1};

    sort(A.begin(), A.end());

    for(int i: A)
    cout<<i<<" "<<endl;

    // search for 11
    bool present  = binary_search(A.begin(),A.end(),11);
    cout<<present<<endl;

    present  = binary_search(A.begin(),A.end(),100);
    cout<<present<<endl;

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);

    vector<int>::iterator it  = lower_bound(A.begin(),A.end(),100); // >=
    cout<<*it<<" "<<endl;

    // vector<int>::iterator it2 = upper_bound(A.begin(),A.end(),100);
    // cout<<*it2<<" "<<endl;

    // cout<<"Number of times 100 is found is:"<<it2-it<<" "<<endl;

    auto it2 = upper_bound(A.begin(),A.end(),100); // >
    cout<<*it2<<" "<<endl;
    
    //sorting in reverse order
    sort(A.begin(),A.end(),f);
    
    for(int i: A)
        cout<<i<<" ";
}
void setDemo()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-10);

    auto it = s.find(-1);
    if(it==s.end())
    cout<<"Element not found!";
    else cout<<"Element found!:"<<*it;

    auto it2 = s.lower_bound(-1);
    cout<<*it2<<" ";
    auto it3 = s.upper_bound(2);
    cout<<*it3<<endl;

    s.erase(1);
    for(int i:s)
    cout<<i<<" ";

}

void mapDemo()
{
    map<int,int> m;
    m[0]=100;
    m[1]=200;
    m[2]=300;

    auto it = m.find(2);
    cout<<it->first<<" "<<it->second<<endl;

    map<char,int> cnt;
    string s="vaidhyanathan";
    for(char c:s)
    {
        cnt[c]++;
    }
    cout<<cnt['a']<<" "<<cnt['z']<<endl;

}

void powerOfSTL()
{
    set<pair<int,int>> s;
    s.insert({2,3});
    s.insert({10,20});
    s.insert({30,400});
    s.insert({401,450});

    int point = 412;

    auto it = s.upper_bound({point,INT_MAX});
    it--;

    if(point>=it->first && point<=it->second)
    {
        cout<<"Yes, Element found in the range "<<it->first<<"-"<<it->second<<endl;
    }
    else{
        cout<<"Oops not found in any range!!!"<<endl;
    }
    
}
int main(int argc, char const *argv[])
{
    // vectorDemo();
    // setDemo();
    // mapDemo();
    powerOfSTL();
    return 0;
}
