
/* Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3. No disk may be placed on top of a smaller disk.
*/

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
/* Input = 3

Output:

Move from A to B
Move from A to C
Move from B to C
Move from A to B
Move from C to A
Move from C to B
Move from A to B
*/
