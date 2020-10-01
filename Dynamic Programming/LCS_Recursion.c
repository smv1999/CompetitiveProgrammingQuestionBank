#include<stdio.h>
int LCS(char s1[], char s2[]);
int LCS_utility(char s1[], char s2[], int s1_ind, int s2_ind);
#define max(x,y) ( (x) > (y) ? (x) : (y))

int main()
{
 //   char s1[] = "abcd", s2[]="axd";
 //     char s1[] = "abcdef", s2[] = "axyczf";
      char s1[] = "abcdefghijklmnopqrstuvwxyz", s2[]="selvakumarbalakrishnan";
    int lcs;

    lcs = LCS(s1,s2);
    printf("%d", lcs);


    return 0;
}
int LCS(char s1[], char s2[])
{
    return LCS_utility(s1,s2,0,0);
}
int LCS_utility(char s1[], char s2[], int s1_ind, int s2_ind)
{
    int left, right;
    if(s1[s1_ind] == 0 || s2[s2_ind] == 0)
        return 0;
    if(s1[s1_ind] == s2[s2_ind])
        return 1 + LCS_utility(s1,s2, s1_ind+1, s2_ind+1);
    else
    {
        left=LCS_utility(s1, s2, s1_ind,s2_ind+1);
        right = LCS_utility(s1,s2, s1_ind+1,s2_ind);
        return max(left,right);
    }
}
