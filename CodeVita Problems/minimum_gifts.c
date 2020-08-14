/*
Minimum Gifts - Problem Description

A Company has decided to give some gifts to all of its employees. For that, company has given some rank to each employee. Based on that rank, company has made certain rules to distribute the gifts.

The rules for distributing the gifts are:

Each employee must receive at least one gift.

Employees having higher ranking get a greater number of gifts than their neighbours.

What is the minimum number of gifts required by company?

Constraints

1 < T < 10

1 < N < 100000

1 < Rank < 10^9

Input

First line contains integer T, denoting the number of testcases.

For each testcases:

First line contains integer N, denoting number of employees.

Second line contains N space separated integers, denoting the rank of each employee.

Output

For each testcase print the number of minimum gifts required on new line.

Example 1

Input

2
5
1 2 1 5 2
2
1 2

Output

7
3
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    int n;

    while(t--)
    {
        scanf("%d", &n);
        int arr[n], giftarr[n], arr_ind, sum=0;

        for(arr_ind=0;arr_ind<n;arr_ind++)
            scanf("%d", &arr[arr_ind]);

        for(arr_ind=0;arr_ind<n;arr_ind++)
            giftarr[arr_ind] = 1;


        for(arr_ind=1;arr_ind<n;arr_ind++)
        {
            if(arr[arr_ind]>arr[arr_ind-1])
                giftarr[arr_ind] = giftarr[arr_ind-1]+1;
            else giftarr[arr_ind] = 1;
        }

        // checking the rank values and the gift values in the reverse order
        for(arr_ind=n-2;arr_ind>=0;arr_ind--)
        {
            if(arr[arr_ind]>arr[arr_ind+1] && giftarr[arr_ind]<=giftarr[arr_ind+1])
                giftarr[arr_ind] = giftarr[arr_ind+1]+1;
        }

        for(int arr_ind=0;arr_ind<n;arr_ind++)
            sum += giftarr[arr_ind];

        //print the answer
        printf("%d", sum)    ;
    }

    return 0;
}

//Sample test case
/*
2
6
1 4 5 7 2 1
13
3
6 5 4
6
*/
