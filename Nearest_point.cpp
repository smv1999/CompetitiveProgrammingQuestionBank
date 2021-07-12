#include<iostream>
#include<cmath>
using namespace std ;
class points
{
  int i ,j;
  float dis;
  public :
  points()
  {
    cout<<" Enter the x and y components "<<endl;
    cin>>i>>j;
  }
  float nearest(class points X, class points Y)
  {
    dis=sqrt((X.i-Y.i)*(X.i-Y.i)+(X.j-Y.j)*(X.j-Y.j));
    return dis;
  }
};
int main()
{ int i ,j ;
  cout<<"\n WELCOME !! \n Enter for the nearest points A , B ,C respectively :  "<<endl;
  class points A , B ,C ;
  cout<<" Now enter for the central point : "<<endl;
  class points central_point;
  float dis1=A.nearest(A,central_point);
  float dis2=B.nearest(B,central_point);
  float dis3=C.nearest(C,central_point);
  cout<<" Distance between point A and central point is : "<<dis1<<endl;
  cout<<" Distance between point B and central point is : "<<dis2<<endl;
  cout<<" Distance between point C and central point is : "<<dis3<<endl;
  if(dis1==dis2 && dis2==dis3 && dis1==dis3)
  {
    cout<<" All are at same distance "<<dis1<<endl;
  }
  else {
  float a[3]={ dis1 , dis2 , dis3 }; float temp ;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3-i;j++)
    {
      if(a[j]>a[i])
      {
         temp=a[i];
         }
    }
  }
    cout<<" "<<temp<<" : is the nearest distance . "<<endl;
    if(dis1==dis2){ cout<< " Point A and B are at same distance . "<<endl;}
    if(dis2==dis3){ cout<< " Point C and B are at same distance . "<<endl;}
    if(dis3==dis1){ cout<< " Point A and C are at same distance . "<<endl;}

  }
  return 0;

}
