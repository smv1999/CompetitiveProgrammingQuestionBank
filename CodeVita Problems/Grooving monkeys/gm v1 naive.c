#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//{0,2,4,8,6,3,9,5,7,10,1} ans is 12
// {0,4,11,5,6,7,12,8,9,3,10,1,2 } ans is 30
// {0,3,22,2,5,10,4,21,6,15,11,9,17,26,7,23,14,24,18,20,16,12,25,1,19,13,8} ans is 144
int main()
{

//int monkey_moves[] = {0,2,4,8,6,3,9,5,7,10,1};
//int monkey_moves[] = {0,4,11,5,6,7,12,8,9,3,10,1,2};
int monkey_moves[] = {0,3,22,2,5,10,4,21,6,15,11,9,17,26,7,23,14,24,18,20,16,12,25,1,19,13,8};

int mm_ind, mm_size,seconds;
int *odd, *even, oddInd,evenInd;
mm_size = sizeof(monkey_moves) / sizeof(monkey_moves[0]);
// make space for processing
odd = (int *) malloc(mm_size * sizeof(int));
even = (int *) malloc(mm_size * sizeof(int));

// Set the monkeys at initial position
for(evenInd=0;evenInd<mm_size;evenInd++)
    even[evenInd] = evenInd;
seconds =0;
    while(1)
    {
    // odd second move
    for(evenInd=1;evenInd<mm_size;evenInd++)
        odd[monkey_moves[evenInd]] = even[evenInd];
    seconds++;
    // verify
    for(oddInd=1;oddInd<mm_size;oddInd++)
        if(odd[oddInd]!=oddInd) break;
    if(oddInd == mm_size) break;
    //even second move
    for(oddInd=1;oddInd<mm_size;oddInd++)
        even[monkey_moves[oddInd]] = odd[oddInd];
    seconds++;
    // verify
    for(evenInd=1;evenInd<mm_size;evenInd++)
        if(even[evenInd]!=evenInd) break;
    if(evenInd == mm_size) break;
    } // while(1) ends here
    printf("%d", seconds);




return 0 ;
}
