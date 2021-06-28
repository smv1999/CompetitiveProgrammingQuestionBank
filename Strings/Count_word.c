/*  Program to find the total numbers of words in a sentence  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function which calculate and return total numbers of words
int count_words(char *sen)
{
    int i=0,check=1,word=0;
    //until i is less then length of sen variable the loop will run
    while(strlen(sen)>i)
    {
/*if sen[i]th index value is not equal to space and i is not the last index number because
the last index no. contain null and null is not alphabet so we not need to treat it as a alphabet*/
        if(sen[i]!=' '&&i!=strlen(sen)-1)
        {
            //if check is equal to 1(first time word occurrence after space)
            if(check==1)
            {
                //increment word and assign 0 to check
                word++;
            check=0;
            }
        }
        // if the sen[i]th index no. value is a space or null then run else
        else
        {
            //assign 1 to check
            check=1;
        }
        //increment i by 1
        i++;
    }
    return word;
}
//driver code
int main()
{
    //initialize required variables
    char *sen,res;
    // dynamically locating the address in sen variable
    sen=(char*)malloc(sizeof(char)*1000);
    printf("Enter a sentence: ");
    //taking input
    fgets(sen,1000,stdin);
    // resizing the sen variable length so memory wastage can be prevent
    sen=(char*)realloc(sen,strlen(sen)+1);
    // calling count_words function which will return total words in res variable
    res=count_words(sen);
    //printing the total words
    printf("Total number of words: %d",res);
}
/*
Test case 1:
Input: Enter a sentence:         DSA    is    a Important            Topic
Output: Total number of words: 5

Test case 2:
Input: Enter a sentence: Who are you?
Output: Total number of words: 3

Time Complexity O(n) where n is the length of string

*/
