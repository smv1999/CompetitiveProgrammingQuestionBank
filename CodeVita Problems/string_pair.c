// String Pair
// Problem Description
// One person hands over the list of digits to Mr. String, But Mr. String understands only strings. Within strings also he understands only vowels. Mr. String needs your help to find the total number of pairs which add up to a certain digit D.

// The rules to calculate digit D are as follow

// Take all digits and convert them into their textual representation

// Next, sum up the number of vowels i.e. {a, e, i, o, u} from all textual representation

// This sum is digit D

// Now, once digit D is known find out all unordered pairs of numbers in input whose sum is equal to D. Refer example section for better understanding.

// Constraints
// 1 <= N <= 100

// 1 <= value of each element in second line of input <= 100

// Number 100, if and when it appears in input should be converted to textual representation as hundred and not as one hundred. Hence number of vowels in number 100 should be 2 and not 4

// Input
// First line contains an integer N which represents number of elements to be processed as input

// Second line contains N numbers separated by space

// Output
// Lower case representation of textual representation of number of pairs in input that sum up to digit D

// Note: - (If the count exceeds 100 print "greater 100")

// Time Limit
// 1


// Examples
// Example 1

// Input

// 5

// 1 2 3 4 5

// Output

// one

// Explanation

// 1 -> one -> o, e

// 2 -> two -> o

// 3 -> three -> e, e

// 4 -> four -> o, u

// 5 -> five - > i, e

// Thus, count of vowels in textual representation of numbers in input = {2 + 1 + 2 + 2 + 2} = 9. Number 9 is the digit D referred to in section above.

// Now from given list of number {1,2,3,4,5} -> find all pairs that sum up to 9.

// Upon processing this we know that only a single unordered pair {4, 5} sum up to 9. Hence the answer is 1. However, output specification requires you to print textual representation of number 1 which is one. Hence output is one.

// Note: - Pairs {4, 5} or {5, 4} both sum up to 9. But since we are asking to count only unordered pair, the number of unordered pair is this combination is only one.

// Example 2

// Input

// 3

// 7 4 2

// Output

// zero

// Explanation

// 7 -> seven -> e, e

// 4 -> four -> o, u

// 2 -> two -> o

// Thus, count of vowels in textual representation of numbers in input = {2 + 2 + 1} = 5. Number 5 is the digit D referred to in section above.

// Since no pairs add up to 5, the answer is 0. Textual representation of 0 is zero. Hence output is zero.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void numToWords( int num, char res[])
{
    char unit_words [ 10 ] [ 6 ] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",\
    "SEVEN","EIGHT","NINE" };
    char tens_words  [ 10] [10] = { "", "TEN", "TWENTY ", "THIRTY ","FOURTY ","FIFTY ","SIXTY "\
    ,"SEVENTY ", "EIGHTY ","NINETY "};
    char eleven_nineteen [10] [ 20] = { "", "ELEVEN","TWELVE","THIRTEEN","FOURTEEN",\
    "FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    int N, ud, td;
    char num_in_words[500]="";
    N = num;
    {

    ud = N % 10;
    td = N / 10;
    if(N < 10)
        strcpy(num_in_words , unit_words [ N ]);
    else if ( N > 10 && N < 20)
        strcpy(num_in_words, eleven_nineteen [ ud ]);
    else{

        strcpy(num_in_words, tens_words [ td]);
        if(ud > 0)
            strcat(num_in_words, unit_words[ud]);
    }

    strcpy(res, num_in_words);
    }
}
int vowelCount(char s[])
{
    int count=0;
    for(int s_ind=0;s_ind<(int)strlen(s);s_ind++)
    {
        switch(tolower(s[s_ind]))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            count++;
            break;
        }
    }
    return count;
}
int countPairs(int arr[], int n, int sum) 
{ 
    int count = 0; 
  
    for (int arr_ind=0; arr_ind<n; arr_ind++) 
        for (int inner=arr_ind+1; inner<n; inner++) 
            if (arr[arr_ind]+arr[inner] == sum) 
                count++; 
  
    return count; 
} 
void toLower(char s[])
{
    for(int s_ind=0;s_ind<(int)strlen(s);s_ind++)
    {
        s[s_ind] = tolower(s[s_ind]);
    }
}
int main(int argc, char const *argv[])
{
    int N, length_of_word, countSum=0;
    scanf("%d", &N);
    int arr[N], arr_ind;
    char ** res, tempStr[500], resultStr[500];
    res = (  char * * ) malloc( (N+1) * sizeof( char *));
    for(arr_ind=0;arr_ind<N;arr_ind++)
        scanf("%d", &arr[arr_ind]);
     
    for(arr_ind=0;arr_ind<N;arr_ind++)
    {
        if(arr[arr_ind]!=100)
        {
            numToWords(arr[arr_ind],tempStr);
            length_of_word = (int)strlen(tempStr);
            res[arr_ind] =  (char *) malloc( (length_of_word+10) * sizeof(char));
            strcpy(res[arr_ind], tempStr);
        }
        else if(arr[arr_ind]==100){
            length_of_word = (int)strlen("hundred");
            res[arr_ind] =  (char *) malloc( (length_of_word+10) * sizeof(char));
            strcpy(res[arr_ind], "hundred");
        }
    }
    for(arr_ind=0;arr_ind<N;arr_ind++)
    {
        countSum  += vowelCount(res[arr_ind]);
    }
    if(countPairs(arr,N,countSum)<=100)
    {
    numToWords(countPairs(arr,N,countSum), resultStr);
    toLower(resultStr);
    printf("%s", resultStr);
    }
    else{
        printf("greater 100");
    }
    return 0;
}
