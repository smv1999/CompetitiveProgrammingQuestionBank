/*Suppose a teacher said to his student to create a class Display which have a
  member function show through which it can print integer,float and string.So student
  said OK sir i will use function overloading to do that..
  Function Overloading: It is a way through which you can create more than one function
  of same name but different argument or you can say that different signature */
#include<iostream>
#include<string.h>
using namespace std;
// creating Display class which will display integer,float and string.
class Display
{
public:
    //this show function will display you integer
    void show(int n)
    {
       cout<<n<<"\n";
    }
    //this show function will display you float value
    void show(float n)
    {
        cout<<n<<"\n";
    }
    //this show function will display you string value
    void show(string n)
    {
        cout<<n<<"\n";
    }
};
//driver code
int main()
{
    //initialize variable
    int n;
    float a;
    char *str;
    //dynamically memory allocation
    str=(char*)malloc(sizeof(char)*1000);
    //initialize Display class variable d to access the show function
    Display d;
    cout<<"Enter a string, integer and float: ";
    //taking inputs
    cin.getline(str,1000);
    cin>>n>>a;
    //resizing str length
    realloc(str,strlen(str)+1);
    //calling Display member function show by passing string
    d.show(str);
    //calling Display member function show by passing integer
    d.show(n);
    //calling Display member function show by passing float
    d.show(a);
    return 0;
}
