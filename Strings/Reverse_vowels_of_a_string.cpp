// Problem taken from LeetCode

 // Problem Statement :
 //      You are given a string.
 // Write a function that takes a string as input and reverse only the vowels of a string.
 
 // Example :
 //      Sample Input - 1 :
 //          "hello"
 //      Sample Output - 1 : 
 //          "holle"

 //      Sample Input - 2 :
 //          "leetcode"
 //      Sample Output - 2 : 
 //          "leotcede"




class Solution {
public:
    string reverseVowels(string s) {
        int i = 0 , j = s.size() - 1;
        while(i < j) {
            while(i < j && 
                  (s[i] != 'a' &&
                   s[i] != 'e' &&
                   s[i] != 'i' &&
                   s[i] != 'o' &&
                   s[i] != 'u' &&
                   s[i] != 'A' &&
                   s[i] != 'E' &&
                   s[i] != 'I' &&
                   s[i] != 'O' &&
                   s[i] != 'U' 
                  )) {
                      i++;
                  }
            while(j > i && 
                  (s[j] != 'a' &&
                   s[j] != 'e' &&
                   s[j] != 'i' &&
                   s[j] != 'o' &&
                   s[j] != 'u' &&
                   s[j] != 'A' &&
                   s[j] != 'E' &&
                   s[j] != 'I' &&
                   s[j] != 'O' &&
                   s[j] != 'U' 
                  )) {
                      j--;
                  }
            if(i < j) {
                swap(s[i] , s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};