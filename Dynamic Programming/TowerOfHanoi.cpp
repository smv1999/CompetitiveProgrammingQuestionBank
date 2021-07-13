#include<iostream>
using namespace std;

void towerofHanoi(int n, char src, char helper ,char dest){
	
	
	if(n==0){
		return; //base case
	}
	
	towerofHanoi(n-1, src, dest, helper);
	cout<<"Move from "<<src<<" to "<<helper<<endl;
	towerofHanoi(n-1, dest, helper, src);
	
	
	
}

int main(){
	
	towerofHanoi(3, 'A', 'B', 'C');
	
	return 0;
	
	
}
