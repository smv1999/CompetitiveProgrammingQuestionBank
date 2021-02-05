/*
You are given a function:

int CheckPassiord(char str, int n):

The function accepts string 'str of size 'n' as argument

Implement the function which returns 1 if given string str' is a valid password else 0.

str is a valid password if it satisfies below conditions:

At least 4 characters

• At least one numeric digit

• At least one Capital letter

• Must not have space or slash (/)

• Starting character must not be a number

Assumption: Input string will not be empty.

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(char str[], int n)
{
    if (n > 4)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(str[i]))
            {
                flag = 1;
            }
        }
        if (!flag)
            return 0;
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (isupper(str[i]))
            {
                flag = 1;
            }
        }
        if (!flag)
            return 0;
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] != ' ' || str[i] != '/')
            {
                flag = 1;
            }
        }
        if (flag)
            return 0;
        if (!isdigit(str[0]))
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int main()
{
    char str[100];

    scanf("%[^\n]%*c", str);

    printf("%s", str);

    int n = strlen(str);

    printf("%d", check(str, n));
}