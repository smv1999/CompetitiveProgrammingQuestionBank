#include<stdio.h>
#include<malloc.h>
#include<string.h>
int LCS(char s1[], char s2[]);
#define max(x,y) ( (x) > (y) ? (x) : (y))

int main()
{
   char s1[] = "abcdefghijklmnopqrstuvwxyz", s2[]="selvakumarbalakrishnan";
  //  char s1[] = "abcdef",s2[]="axyczf";
  //  char s1[] = "abcdefghijklmnopqrstuvwxyz" , s2[]="raviteja";
    int lcs;
    lcs = LCS(s1,s2);
    printf("%d", lcs);
    return 0;
}
int LCS(char s1[], char s2[])
{
    int **dp_table;
    int s1_ind, s2_ind,s1_len, s2_len, res;
    s1_len = 1+ strlen(s1);
    s2_len = 1+ strlen(s2);
    dp_table = malloc((s1_len) * sizeof(int *));
    for(s1_ind = 0; s1_ind <= s1_len;s1_ind++)
        dp_table[s1_ind] = malloc( (s2_len)  * sizeof(int));
    for(s1_ind = 0; s1_ind <= s1_len;s1_ind++)
        dp_table[0][s1_ind] = 0;
    for(s2_ind = 0; s2_ind <= s2_len;s2_ind++)
        dp_table[s2_ind][0] = 0;
    for(s1_ind = 1; s1_ind < s1_len ; s1_ind++)
    {

        for(s2_ind = 1; s2_ind < s2_len; s2_ind++)
    {
        if(s1[s1_ind-1] == s2[s2_ind-1])
            dp_table[s1_ind][s2_ind] = 1 + dp_table[s1_ind][s2_ind-1];
        else
            dp_table[s1_ind][s2_ind] =
            max(dp_table[s1_ind-1][s2_ind], dp_table[s1_ind][s2_ind-1]);
                }
    }
                res = dp_table[s1_len][s2_len];
 for(s1_ind = 0; s1_ind <= s1_len ; s1_ind++, printf("\n"))
        for(s2_ind = 0; s2_ind <= s2_len; s2_ind++)
         printf("%d ", dp_table[s1_ind][s2_ind]);
  for(s1_ind = 0; s1_ind <= s1_len ; s1_ind++)
    free(dp_table[s1_ind]);
  free(dp_table);

return res;
}
