/*Given 'N' generate all the words that represent 0 to N,
Sort them and print them

N=15

0 ZERO
1 ONE
2 TWO
3 THREE
4 FOUR
5 FIVE
6 SIX
7 SEVEN
8 EIGHT
9 NINE
10 TEN
11 ELEVEN
12 TWELVE
13 THIRTEEN
14 FOURTEEN
15 FIFTEEN
EIGHT
ELEVEN
FIFTEEN
FIVE
FOUR
FOURTEEN
NINE
ONE
SEVEN
SIX
TEN
THIRTEEN
THREE
TWELVE
TWO
ZERO

how many words
n+1 words
char [] *
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
#include<string.h>
char *  itoa ( int value, char * str, int base );

void twoDigit_words(int num, char res[]);
void num_to_words(int num, char res[]);
int main()
{
  int N, num, length_of_word, outer, inner;
   char * * word_list=0,num_in_word[100]="", *temp, numstr[10];
  // scanf("%d", &N);
  N=30;
   word_list = (  char * * ) malloc( (N+1) * sizeof( char *));

   for(num = 0; num <= N; num++)
   {
       num_to_words(num, num_in_word);
       length_of_word = strlen(num_in_word);
       word_list [ num ] =  (char *) malloc( (length_of_word+6) * sizeof(char));
       strcpy(word_list [num], num_in_word);
       itoa (num , numstr, 10);
       strcat(word_list [ num] , numstr);
   }

 //  for(num = 0; num <= N; num++)
   //   printf("%d : %s\n", num, word_list [ num]);

//    for(outer = 0; outer <= N; outer++)
//    {
//        for(inner = 0; inner < (N-outer); inner++)
//        {
//            if(strcmp(word_list [inner], word_list[inner+1]) > 0)
//             {
//                 temp = word_list [inner];
//                 word_list [ inner] = word_list [ inner+1];
//                 word_list [inner+1] = temp;
//             }

//        }
//    }
   for(num = 0 ; num <= N; num++)
       printf("%s\n", word_list [ num]);

   return 0;
}
void twoDigit_words( int num, char res[])
{
    char unit_words [ 10 ] [ 10 ] = {"ZERO","ONE ","TWO ","THREE ","FOUR ","FIVE ","SIX ",\
    "SEVEN ","EIGHT ","NINE " };
    char tens_words  [ 10] [10] = { "", "TEN", "TWENTY ", "THIRTY ","FOURTY ","FIFTY ","SIXTY "\
    ,"SEVENTY ", "EIGHTY ","NINETY "};
    char eleven_nineteen [10] [ 20] = { "", "ELEVEN ","TWELVE ","THIRTEEN ","FOURTEEN ",\
    "FIFTEEN ","SIXTEEN ","SEVENTEEN ","EIGHTEEN ","NINETEEN "};
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


void num_to_words(int N, char given_res [] )
{
    #define TRUE 1
    #define FALSE 0
    char power_words [5] [15 ]= { "", "HUNDRED", "THOUSAND", "LAKH", "CRORE"};
   char res[200]="", temp[200]="";
   int num = N, part_num, part_ctr=0, div_factor;
   int initFlag =  FALSE, andFlag=FALSE;
    if(num == 0)
    {
        strcpy(given_res, "ZERO ");
        return ;
    }
    while(num)
    {
   div_factor = part_ctr == 1 ? 10 : 100;
   part_num  = num % div_factor;
   if(part_num > 0)
   {
       twoDigit_words(part_num, temp);
       strcat(temp, power_words [ part_ctr ]);
       if(part_ctr > 0 && part_num > 1)
        strcat(temp,"S ");
       else
        strcat(temp," ");
        if(initFlag == TRUE && andFlag == FALSE)
       {
           strcat(temp, "AND ");
           andFlag = TRUE;
       }
       strcat(temp, res);
       strcpy(res, temp);
       initFlag = TRUE;
   }
   num = num / div_factor;
   part_ctr++;
   }
strcpy(given_res, res);
}




















