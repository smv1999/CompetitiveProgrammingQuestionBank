/* Title : To find whether a given point lies on the circumference
           of the circle , inside the circle or outside the circle .

   Description : User needs to provide the center co-ordinates and radii
                 of a circle . And the point for which you want to find.
                 */
#include<stdio.h>
#include<conio.h>
int main()
{
  float h , k;
  printf("\n Enter the X , Y center co-ordinates of a circle : \n");
  scanf("%f %f",&h ,&k);
  printf("\n Enter the radius :\n");
  float radii;
  scanf("%f",&radii);
  float eqn;
  float x ,y;
  printf("\n Enter the X and Y co-ordinates of point A : \n");
  scanf("%f %f",&x ,&y);
  float t=(h*h)+(k*k)-(radii*radii);
  eqn=(x*x)-(2*h*x)+(y*y)-(2*k*y)+t;
  printf("Equation of the circle : (x-%0.2f)^2 + (y-%0.2f)^2 -%0.2f \n",h,k,radii*radii);
  if(eqn<0)
  {
    printf("\n Inside the circle ");
  }
  else if(eqn>0)
  {
    printf("\n Outside the circle ");
  }
  else if(eqn==0)
  {
    printf("\n On the circumference of the circle .\n");
  }
  return 0;
}
