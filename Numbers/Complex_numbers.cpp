/* Title : To perform the following operations on Complex numbers:
           Add, subtract, multiply, divide, complex conjugate,Modulus. */

/* Program Code : */
#include <iostream>
#include<cmath>
using namespace std;
class complex
{
float real, img;
public:
void display();
void read();
void add(complex,complex);
void sub(complex,complex);
void multiply(complex,complex);
void divide(complex,complex);
void conjugate(complex);
float modulus(complex);
};
int main()
{
 complex sum,su,mult,div,conj,c1,c2,c,mod ;
int opt;
do{
cout<<"ENTER THE OPTION" ;
cout<<"\n1.ADD \n2.SUB \n3.Multiply \n4.Divide \n5.Conjugate \n6.Modulus"<<'\n'<<endl;
cin>>opt;
switch(opt)
{
  case 1 : c1.read();
           c2.read();
           cout<<"Sum is :"<<endl;
           sum.add(c1,c2);
           break;
  case 2 : c1.read();
           c2.read();
           cout<<"Difference is :";
           su.sub(c1,c2);
           break;
  case 3 : c1.read();
           c2.read();
           cout<<"Muliplication is : "<<endl;
           mult.multiply(c1,c2);
           break;
  case 4 : cout<<"Enter dividant and then divisior"<<endl;
           c1.read();
           c2.read();
           cout<<"Division is :"<<endl;
           div.divide(c1,c2);
           break;
  case 5 : c.read();
           cout<<"Conjuage is :"<<endl;
           conj.conjugate(c);
           break;
  case 6 : c.read();
           cout<<"Modulus of the given complex number is : "<<endl;
           cout<<mod.modulus(c)<<endl;
           break;
}
 cout<<"\n Wish to continue ? : Press 1 or 0 \n1.Yes 0.No\n";
 cin>>opt; }
 while(opt!=0);
return 0;
}

void complex :: read()
{
cout<<"Enter real and imaginary part : ";
cin>>real>>img;
}
void complex :: display()
{
  if(img>=0)
{ cout<<real<<"+"<<img<<"i"<<endl; }
 else
  cout<<real<<img<<"i"<<endl;
}

void complex :: add(complex c1,complex c2)
{
real = c1.real+c2.real;
img = c1.img+c2.img;
display();

}
void complex :: sub(complex c1 , complex c2)
{

  real=c1.real-c2.real ;
  img = c1.img-c2.img ;

  display();
}
void complex :: multiply(complex c1 , complex c2)
{
  real=(c1.real*c2.real)-(c1.img*c2.img);
  img=(c1.real*c2.img)+(c1.img*c2.real);

  display();
}
void complex :: divide(complex c1 , complex c2)
{  int i;
  float r ,im;
   i=(c2.real)*(c2.real) + (c2.img)*(c2.img);
   real=(c1.real*c2.real)-(c1.img*c2.img*(-1));
   img=(c1.real*c2.img*(-1))+(c1.img*c2.real);
   real=real/i;
   img=img/i;
  display();
}
void complex :: conjugate(complex c)
{ int t;
  real=c.real;
  img=-c.img;
  display();
}
float complex ::modulus(complex c)
{
  float k;
  k=sqrt(c.img*c.img+ c.real*c.real) ;
  return k;
}
