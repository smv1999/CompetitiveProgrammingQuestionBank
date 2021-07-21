int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)
            return s.length();
        vector<int> freq(128,0);
        int si=0,ei=0,n=s.length(),maxlen=INT_MIN,count=0;
        while(ei<n){
            if(freq[s[ei++]]++ > 0)
                count++;
            
            while(count>0){                 //if freq of char at ei in the chosen substring is greater than 2
                if(freq[s[si++]]-- >1)    //iterate till the freq becomes 1
                    count--;
            }
            
            if(ei-si>maxlen)                //each time compare length of obtained substr with unique char to the maximum length
                maxlen=ei-si;
        }
        return maxlen;
    }