/*WAP TO GENERATE THE GIVEN PATTERN

* * * * * * * * * *
 * * * *   * * * *
  * * *     * * *
   * *       * *
    *         *
     * * * * *
      * * * *
       * * *
        * *
         *
*/
#include<stdio.h>
int main()
{
	int i,j,k,l,n;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=n;i>=1;i--)
	{
		for(k=n-i;k>=1;k--)
		printf(" ");
		for(j=1;j<=i;j++)
		{
		if(j%2==1)
		printf("*");
		else
		printf(" ");
		}
		for(l=i-1;l>=1;l--)
		{
		if(l%2==1)
		printf("*");
		else
		printf(" ");
		}
		//
		for(j=n;j>=i;j--)
		printf(" ");
		for(j=n-i;j>=1;j--)
		printf(" ");
		for(j=1;j<=i;j++)
		{
		if(j%2==1)
		printf("*");
		else
		printf(" ");
		}
		for(l=i-1;l>=1;l--)
		{
		if(l%2==1)
		printf("*");
		else
		printf(" ");
		}

		printf("\n");
	}

	for(i=n;i>=1;i--)
	{
		for(j=n;j>=1;j--)
		printf(" ");
		for(k=n-i;k>=1;k--)
		printf(" ");
		for(j=1;j<=i;j++)
		{
		if(j%2==1)
		printf("*");
		else
		printf(" ");
		}
		for(l=i-1;l>=1;l--)
		{
		if(l%2==1)
		printf("*");
		else
		printf(" ");
		}
		printf("\n");
	}
	return 0;
}
/*
9
* * * * * * * * * * * * * * * * * *
 * * * * * * * *   * * * * * * * *
  * * * * * * *     * * * * * * *
   * * * * * *       * * * * * *
    * * * * *         * * * * *
     * * * *           * * * *
      * * *             * * *
       * *               * *
        *                 *
         * * * * * * * * *
          * * * * * * * *
           * * * * * * *
            * * * * * *
	         * * * * *
	          * * * *
               * * *
                * *
		         *

--------------------------------
*/
