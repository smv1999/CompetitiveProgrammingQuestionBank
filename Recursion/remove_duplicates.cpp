#include <iostream>
#include <string.h>
using namespace std;
void removeduplicates(char input[]){
  if(input[0]=='\0'){
    return ;//if it is empty string
  }
  if(input[0]==input[1]){//checking for consecutive duplicate 
    for(int i=0;input[i]!='\0';i++){
      input[i]=input[i+1];//shift to left 
    }
    removeduplicates(input);
  }else{
  removeduplicates(input+1);
  }
}

int main() {
   char input[1000];
   cin.getline(input,1000);
   removeduplicates(input);
   cout<<input;
}
/*Example
aaaabbbbb
O/p ab 
*/