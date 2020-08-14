#include<stdio.h>

int main()
{
    char space[3][100] =
    {
        "#.*.#******#****.****#.*.",
        "#***#******#*.**.*.*.#***",
        "#*.*#******#*********#*.*"
    };

    int space_ind;

    for(space_ind = 0; space[0][space_ind];space_ind++)
    {
        if(space[0][space_ind] == '#')
           printf("#");
        else if (space[2][space_ind] == '.' )
            continue;
        else if(space[0][space_ind] == '.')
            printf("A");
        else if(space[1][space_ind] == '.')
           printf("I");
        else if(space[0][space_ind+1] == '.')
            printf("U");
        else if(space[1][space_ind+1] == '.')
            printf("O");
        else printf("E");
        if(space[0][space_ind] == '#' || space[2][space_ind] == '.' )
            continue;
          else
                    space_ind+=2;

    }

    return 0;
}
