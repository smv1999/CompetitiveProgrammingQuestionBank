#include<stdio.h>
int main(){
  int mat1[2][2], mat2[2][2], mat3[2][2], i, j;
  int a, b, c, d , e, f, g;
 
  printf("Enter the elements of first matrix:\n"); //matrix 1
  for(i = 0;i < 2; i++)
  {
      for(j = 0;j < 2; j++)
      {
           scanf("%d", &mat1[i][j]);
      }
  }
 
  printf("Enter the elements of second matrix:\n"); //matrix 2
  for(i = 0; i < 2; i++)
  {
      for(j = 0;j < 2; j++)
      {
           scanf("%d", &mat2[i][j]);
      }
  }
  //Displaying
  printf("The Matrix 1:\n"); //Displaying matrix 1 elements
  for(i = 0; i < 2; i++)
  {
      for(j = 0; j < 2; j++)
      {
           printf("%d\t", mat1[i][j]);
      }
      printf("\n");
  }
 
  printf("The Matrix 2:\n"); //Displayimg matrix 2 elements
  for(i = 0;i < 2; i++)
  {
      for(j = 0;j < 2; j++)
      {
           printf("%d \t", mat2[i][j]);
      }
      printf("\n");
  }
 //reduced eight times Time Complexity to Seven Times
  a= (mat1[0][0] + mat1[1][1]) * (mat2[0][0] + mat2[1][1]); 
  b= (mat1[1][0] + mat1[1][1]) * mat2[0][0];
  c= mat1[0][0] * (mat2[0][1] - mat2[1][1]);
  d= mat1[1][1] * (mat2[1][0] - mat2[0][0]);
  e= (mat1[0][0] + mat1[0][1]) * mat2[1][1];
  f= (mat1[1][0] - mat1[0][0]) * (mat2[0][0]+mat2[0][1]);
  g= (mat1[0][1] - mat1[1][1]) * (mat2[1][0]+mat2[1][1]);
 
  mat3[0][0] = a + d- e + g;
  mat3[0][1] = c + e;
  mat3[1][0] = b + d;
  mat3[1][1] = a - b + c + f;
 
   printf("Strassen's algorithm : Matrix Multiplication\n"); //Resultant matrix after applying Strassen's Algo
   for(i = 0; i < 2 ; i++)
   {
      for(j = 0;j < 2; j++)
      {
           printf("%d\t", mat3[i][j]); //displaying resultant matrix
      }
      printf("\n");
   }
   return 0;
}
