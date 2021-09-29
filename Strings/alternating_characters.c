/*  Program to find the total numbers of deletions needed to make a String with only alternating characters  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function which calculate and return total numbers of deletions
int alternatingCharacters(char* s) {
    //initialize required variables
    int a=strlen(s);
    int k=0,i;
    //To verify all the letters of a String
    for(i=0;i<a;i++)
    {
        //Comparing characters
        //If both are same, then one has to deleted
        if(s[i]==s[i+1])
            //number of deletions to be done gets incremented
            k++;
    }
    return k;
}
void main()
{
    //initialize required variables
    //t = Number of test cases
    int t,ans;
    char str[20];
    scanf("%d",&t);
    while(t--){
        //For each test case get a String as input
        scanf("%s",str);
        //Print the number of deletions required for each String
        printf("%d\n",alternatingCharacters(str));   
    }
}
/*
Test case 1:
Input:  5
        AAAA
        BBBBB
        ABABABAB
        BABABA
        AAABBB
Output: 3
        4
        0
        0
        4
Time Complexity O(n) where n is the length of string
*/

