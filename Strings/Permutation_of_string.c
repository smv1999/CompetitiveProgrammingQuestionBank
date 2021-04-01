// program to generate all permutation of the given string
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//declare permutation and swap functions
void permutation(char *,int,int);
void swap(char *,char *);
int main()
{
    char *s;
    // dynamically creating string length
    s=(char*)malloc(sizeof(char)*1000);
    // getting string
    fgets(s);
    // changing size to the length of string+1 to store null at end
    s=realloc(s,strlen(s)+1);
	//calling permutation
    permutation(s,0,strlen(s)-1);
return 0;
}
void permutation(char *str,int s,int e)
{   //declare variables
    static int count;
    int i;
	//base condition
    if(s==e)
    {
        count++;
	    //Printing the string permutation's
        printf("%d(%s)\n",count,str);
    }
    else
    {
        for(i=s;i<=e;i++)
        {  //swapping variables value
            swap(str+s,str+i);
			//calling permutation function
            permutation(str,s+1,e);
			//now swap the variables value and make it before one
            swap(str+s,str+i);
        }
    }
}
//swap function
void swap(char *a,char *b)
{
    char temp;
	//putting value in temp
    temp=*a;
	// putting value in a pointer
    *a=*b;
	//now putting value of temp in b pointer
    *b=temp;
	//swapping done
}
/*Example:
Input: abc
Output: 1(abc)
        2(acb)
        3(bac)
        4(bca)
        5(cba)
        6(cab)
Time Complexity: O(n!)
*/
