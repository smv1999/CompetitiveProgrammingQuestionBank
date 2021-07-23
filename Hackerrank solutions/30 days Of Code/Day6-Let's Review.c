/* Sample Input

2
Hacker
Rank
Sample Output

Hce akr
Rn ak  

space separates the even indexed characters and odd indexed characters  */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     int n;
     scanf("%d",&n);char s[50000];
     for(int i=0;i<n;i++)
     {
       scanf("%s",s);
       fun(s);
     }
     return 0;
}
