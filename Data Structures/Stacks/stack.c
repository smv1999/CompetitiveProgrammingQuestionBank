/*
    Title : Stack Operations :
            1.PUSH    2.POP   3.DISPLAY   4.PEAK ELEMENT
            are performed using arrays . i.e Static memory allocation in c language .
            User need to choose the option number which user  wants to perform .
            PUSH : To enter the data elements .
            POP  : To POP Out the element (To delete).
            Peak : To get the top most element present on the stack.
            It follows first in last out principle .
            Node can be entered and can be deleted from one end only.
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
   int size,opt,i,x;
   printf(" \n *******  WELCOME  ******* : \n We are going to implement stack data structure : \n It follows LIFO  (Last In First Out Principle .)\n");
   printf("\n Enter the size of STACK : \n");
   scanf("%d",&size);
   int top=-1;
   int arr[size];

   do
   {    printf("\n ---- 1.PUSH ---- \n ---- 2.DISPLAY ---- \n ---- 3.POP ---- \n ---- 4.Peak ---- \n ---- 5.Exit ---- ");
        printf("\n Enter the option number : \n");
        scanf("%d",&opt);
         switch(opt)
         {
           case 1 : printf("\n       PUSH         ");
                    if(top==size-1)
                    { printf("\n STACK IS FULL ! \n");  }
                    else
                    {  top++;
                       printf("\n ENETR PUSH THE ELEMENT \n");
                       scanf("%d",&x);
                       arr[top]=x;  }
                       break;
           case 2 : printf("\n          DISPLAY          ");
                    if(top<=-1)
                    { printf("\n The Stack is Empty ! ");
                       top=-1; }
                      else
                   {  printf("\n The elements are : " );
                      for(i=top;i>=0;i--)
                      {  printf("\n %d   " , arr[i] ); } }
                      break;
          case 3:   printf("\n           POP             ");

                  if(top<=-1){ printf("\n The Stack is Empty ! \n ");
                               top=-1; }
                  else {
                        printf("\n Element popped out is : %d " ,arr[top]);
                        top--;
                        if(top<-1) { top=-1 ; }
                      }
                  break;

          case 4 :   printf("\n           Peak           ");
                     if(top<=-1)
                      { printf("\n No element is at the top of the stack . \n Empty stack !");
                        top=-1; }

                     else
                      { printf("\n The present top/peak element of the stack : %d ",arr[top]); }
                      break ;
          case 5 :
                    exit(0);
                    break ;
          default : printf("\n Invalid Option !!\n Please try again . ");
                    break;

         }
    printf("\n DO YOU WISH TO CONTINUE ? \n 1.Yes \n 2.No\n");  /* Enter 1 or other tahn 0 to continue otherwise enter 2 .  */
    scanf("%d",&opt);

   }
   while(opt!=2);
}
/*
Enter the size of STACK :
2

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
1

      PUSH
ENETR PUSH THE ELEMENT
1

DO YOU WISH TO CONTINUE ?
1.Yes
2.No
1

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
1

      PUSH
ENETR PUSH THE ELEMENT
2

DO YOU WISH TO CONTINUE ?
1.Yes
2.No
1

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
1

      PUSH
STACK IS FULL !

DO YOU WISH TO CONTINUE ?
1.Yes
2.No
1

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
2

         DISPLAY
The elements are :
2
1
DO YOU WISH TO CONTINUE ?
1.Yes
2.No
1

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
3

          POP
Element popped out is : 2
DO YOU WISH TO CONTINUE ?
1.Yes
2.No
1

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
4

          Peak
The present top/peak element of the stack : 1
DO YOU WISH TO CONTINUE ?
1.Yes
2.No
1

---- 1.PUSH ----
---- 2.DISPLAY ----
---- 3.POP ----
---- 4.Peak ----
---- 5.Exit ----
Enter the option number :
5
*/
