#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// AND
// 11 - 19
// 10, 20,30,40,50,60,70,80,90
// rest are combinations

void twoDigit_words(int num, char res[]);
int main()
{

   char res[200];
   twoDigit_words(18, res);
   printf("%s", res);

    return 0;
}

void twoDigit_words( int num, char res[])
{
    char unit_words [ 10 ] [ 6 ] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",\
    "SEVEN","EIGHT","NINE" };
    char tens_words  [ 10] [10] = { "", "TEN", "TWENTY ", "THIRTY ","FOURTY ","FIFTY ","SIXTY "\
    ,"SEVENTY ", "EIGHTY ","NINETY "};
    char eleven_nineteen [10] [ 20] = { "", "ELEVEN","TWELVE","THIRTEEN","FOURTEEN",\
    "FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    int N, ud, td;
    char num_in_words[100]="";
  //  scanf("%d", &N);
   // for( N= 0; N < 100; N++, num_in_words[0]='\0')
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
