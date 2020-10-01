#include<stdio.h>
#include<string.h>
#include<malloc.h>
int LCS(char s1[], char s2[]);
int LCS_utility(char s1[], char s2[], int s1_ind, int s2_ind, int **memo);
#define max(x,y) ( (x) > (y) ? (x) : (y))

int main()
{
   // char s1[] = "abcd", s2[]="axd";
       char s1[] = "abcdef", s2[] = "axyczf";
    //  char s1[] = "abcdefghijklmnopqrstuvwxyz", s2[]="selvakumarbalakrishnan";
    int lcs;

    lcs = LCS(s1,s2);
    printf("%d", lcs);


    return 0;
}
int LCS(char s1[], char s2[])
{
    int **memo=0, s1_len, s2_len, s1_ind,s2_ind,res;
    s1_len = 1+strlen(s1);
    s2_len = 1+strlen(s2);
    memo = (int **) malloc( s1_len * sizeof(int *));
    for(s1_ind = 0; s1_ind < s1_len; s1_ind++)
        memo[s1_ind] = (int *) malloc(s2_len*sizeof(int));
    for(s1_ind = 0; s1_ind < s1_len; s1_ind++)
       for(s2_ind=0;s2_ind < s2_len ; s2_ind++)
           memo[s1_ind][s2_ind]   = -1;

     LCS_utility(s1,s2,0,0, memo);
     for(s1_ind = 0; s1_ind < s1_len; s1_ind++, printf("\n"))
       for(s2_ind=0;s2_ind < s2_len ; s2_ind++)
          printf("%+3d ", memo[s1_ind][s2_ind]);
       res = memo[0][0];
     for(s1_ind = 0; s1_ind < s1_len; s1_ind++)
        free(memo[s1_ind]);
     free(memo);
     return res;


}
int LCS_utility(char s1[], char s2[], int s1_ind, int s2_ind, int **memo)
{
    int left, right;
  //  printf("%d %d\n", s1_ind,s2_ind);
    if(s1[s1_ind] == 0 || s2[s2_ind] == 0)
    {
        memo[s1_ind][s2_ind]=0;
        return memo[s1_ind][s2_ind];
    }
    if(memo[s1_ind][s2_ind] != -1 )
        return memo[s1_ind][s2_ind]; // subproblem solution reused
    if(s1[s1_ind] == s2[s2_ind])
    {
        memo[s1_ind][s2_ind] =  1 + LCS_utility(s1,s2, s1_ind+1, s2_ind+1,memo);
        return memo[s1_ind][s2_ind];
    }
    else
    {
        left=LCS_utility(s1, s2, s1_ind,s2_ind+1,memo);
        right = LCS_utility(s1,s2, s1_ind+1,s2_ind,memo);
        memo[s1_ind][s2_ind] = max(left,right);
        return memo[s1_ind][s2_ind];
    }
}
