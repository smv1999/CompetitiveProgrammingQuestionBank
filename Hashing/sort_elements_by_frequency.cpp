// Given an array of integers, sort the array according to frequency of elements. 
// That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.
// Input:
// N = 5
// A[] = {5,5,4,6,4}
// Output: 4 4 5 5 6

class Solution{
    public:
    
    //custom comparator function to sort map according to frequencies
    static bool cmp( pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    }
   
    vector<int> sortByFreq(int arr[],int n)
    {
        
        vector<int>ans;
        map<int,int> m;
        vector<pair<int, int> > A;
        
      //storing the elements as keys and counting its frequency 
        for(int i=0; i<n; i++)
        {
            int x= arr[i];
            m[x]++;
        }
      
        // Copy key-value pair from Map
        // to vector of pairs
        for (auto &it : m) {
            A.push_back(it);
        }
      
      //sorting the vector of pairs using cmp function
        sort(A.begin(), A.end(), cmp) ;
        
        for(auto x: A)
        {
          //printing the element the no. of times it occured in the actual array
           while(x.second)
           {
               ans.push_back(x.first);
               x.second--;
           }
            
        }   
        
        return ans;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	     
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}
