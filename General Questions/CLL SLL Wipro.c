#include<stdio.h>
#include<malloc.h>

typedef struct cll_sll_wipro
{
     int data;
     struct cll_sll_wipro *next;

} CLL_SLL_WIPRO;

typedef CLL_SLL_WIPRO * CLL_SLL_WIPRO_PTR;
CLL_SLL_WIPRO_PTR addNode(CLL_SLL_WIPRO_PTR start, int input_Val);
void displayCLL(CLL_SLL_WIPRO_PTR start);
int main()
{
    CLL_SLL_WIPRO_PTR start=0;
    int input[] = {30, 40, 12, 45, 6, 24, 42, 33, 51, 48, 28};
    int input_size, input_ind;
    input_size = sizeof(input) / sizeof (input[0]);
    for(input_ind = 0; input_ind < input_size ; input_ind++)
    {
        start = addNode(start, input[input_ind]);
       displayCLL(start);
    }

     return 0;
}
CLL_SLL_WIPRO_PTR addNode(CLL_SLL_WIPRO_PTR start, int input_Val)
{
    CLL_SLL_WIPRO_PTR tptr, prev , nn, actual_start;

    nn = (CLL_SLL_WIPRO_PTR) malloc(sizeof(CLL_SLL_WIPRO));
    nn->data = input_Val;
    nn-> next = 0;
    if(start == 0) // FIRST NODE
    {
        nn->next = nn;
        return nn;
    }
      // Find the Original Start
      actual_start = tptr = start;
      do
      {
         tptr=tptr->next;
         if(tptr->data < actual_start->data)
            actual_start = tptr;
      } while(tptr!=start);


      if(nn->data < actual_start->data)  // insertion in the beginning
      {
          tptr = actual_start;
          do
          {
              prev = tptr;
              tptr=tptr->next;
          }while(tptr!=actual_start);
          prev->next = nn ;
          nn->next = tptr;
          return nn;

      }
      else
      {
       tptr = actual_start;
          do
          {
              prev = tptr;
              tptr=tptr->next;
          }while(tptr!=actual_start && nn->data > tptr->data);
          prev->next = nn ;
          nn->next = tptr;
          return nn;



      }

}
void displayCLL(CLL_SLL_WIPRO_PTR start)
{
    CLL_SLL_WIPRO_PTR tptr;
    if(start==0) return;
    tptr = start;
    printf("\n");
    do
    {
        printf("%d ", tptr->data);
        tptr = tptr->next;
    }while(tptr!=start);
}


